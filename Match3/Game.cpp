#include "Game.h"

static double const FPS{ 60.0f };

Game::Game() : m_window(sf::VideoMode(800, 600, 32), "SFML Application", sf::Style::Default)
{
	init();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::init()
{
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		elements[i] = rand()%4+1;
		elementsShape[i].setSize(sf::Vector2f(20.0f, 20.0f));
		elementsShape[i].setPosition((i % 20) * 25.0f + 10.0f, (i / 20) * 25.0f + 10.0f);

		switch (elements[i]) {
		case 0:
			elementsShape[i].setFillColor(sf::Color::Black);
			break;
		case 1:
			elementsShape[i].setFillColor(sf::Color::Green);
			break;
		case 2:
			elementsShape[i].setFillColor(sf::Color::Yellow);
			break;
		case 3:
			elementsShape[i].setFillColor(sf::Color::Red);
			break;
		case 4:
			elementsShape[i].setFillColor(sf::Color::Magenta);
			break;
		default:
			elementsShape[i].setFillColor(sf::Color::White);
			break;
		}
	}
}

void Game::update(sf::Time dt)
{
	checkMatch();
	for (int i = ELEMENT_COUNT; i > 0; i--)
	{
		if (elements[i] == 0)
		{
			if (i >= 20)
			{
				elements[i] = elements[i - 20];
				elements[i - 20] = 0;
			}
		}
	}
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		switch (elements[i]) {
		case 0:
			elementsShape[i].setFillColor(sf::Color::Black);
			break;
		case 1:
			elementsShape[i].setFillColor(sf::Color::Green);
			break;
		case 2:
			elementsShape[i].setFillColor(sf::Color::Yellow);
			break;
		case 3:
			elementsShape[i].setFillColor(sf::Color::Red);
			break;
		case 4:
			elementsShape[i].setFillColor(sf::Color::Magenta);
			break;
		default:
			elementsShape[i].setFillColor(sf::Color::White);
			break;
		}
	}
	computeSelection();
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		m_window.draw(elementsShape[i]);
	}
	m_window.display();
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
			}
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			select(event);
		}
	}
}

void Game::select(sf::Event t_event)
{
	sf::Vector2f mousepos(t_event.mouseButton.x, t_event.mouseButton.y);
	if(piece1.pieceShape == nullptr || piece2.pieceShape == nullptr)
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		if (mousepos.x < elementsShape[i].getPosition().x + BOX_SIZE &&
			mousepos.x > elementsShape[i].getPosition().x &&
			mousepos.y < elementsShape[i].getPosition().y + BOX_SIZE &&
			mousepos.y > elementsShape[i].getPosition().y)
		{
			if (piece1.pieceShape == nullptr)
			{
				piece1.pieceShape = &elementsShape[i];
				piece1.pieceIndex = i;
				break;
			}
			else
			{
				piece2.pieceShape = &elementsShape[i];
				piece2.pieceIndex = i;
				break;
			}
		}

			/*rect1.x < rect2.x + rect2.w &&
			rect1.x + rect1.w > rect2.x&&
			rect1.y < rect2.y + rect2.h &&
			rect1.y + rect1.h > rect2.y*/
	}
}

void Game::computeSelection()
{
	if(piece1.pieceShape != nullptr && piece2.pieceShape != nullptr)
	{
		int number = elements[piece1.pieceIndex];
		elements[piece1.pieceIndex] = elements[piece2.pieceIndex];
		elements[piece2.pieceIndex] = number;
		piece1.pieceShape = nullptr;
		piece2.pieceShape = nullptr;
	}
}

void Game::checkMatch()
{
	int first{ -1 };
	int second{ -1 };
	int current{ -1 };
	bool deleting{ false };
	for (int i = 2; i < ELEMENT_COUNT; i++)
	{
		if(deleting)
		{
			if (elements[i] == current)
			{
				elements[i] = 0;
			}
			else
				deleting = false;
			
		}
		if(!deleting)
		{
			current = elements[i];
			second = elements[i - 1];
			first = elements[i - 2];
		}
		if (first != -1 && first == second && second == current)
		{
			elements[i] = 0;
			elements[i-1] = 0;
			elements[i-2] = 0;
			deleting = true;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 2; j < 20; j++)
		{
			if (deleting)
			{
				if (elements[i + (j * 20)] == current)
				{
					elements[i + (j * 20)] = 0;
				}
				else
					deleting = false;

			}
			if (!deleting)
			{
				current = elements[i + (j * 20)];
				second = elements[i + ((j - 1) * 20)];
				first = elements[i + ((j - 2) * 20)];
			}
			if (first != -1 && first == second && second == current)
			{
				elements[i + (j * 20)] = 0;
				elements[i + ((j - 1) * 20)] = 0;
				elements[i + ((j - 2) * 20)] = 0;
				deleting = true;
			}
		}
	}
}
