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
		elements[i] = 0;
		elementsShape[i].setSize(sf::Vector2f(20.0f, 20.0f));
		elementsShape[i].setFillColor(sf::Color::Cyan);
		elementsShape[i].setPosition((i % 20) * 25.0f + 10.0f, (i / 20) * 25.0f + 10.0f);
	}
}

void Game::update(sf::Time dt)
{
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
	}
}
