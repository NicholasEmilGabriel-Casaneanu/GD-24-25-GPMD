#pragma once
#include <SFML/Graphics.hpp>

int const ELEMENT_COUNT = 400;
float const BOX_SIZE = 20.0f;

struct element {
	sf::RectangleShape* pieceShape{ nullptr };
	int pieceIndex{ 0 };
};

class Game
{
public:
	Game();
	void run();


protected:

	sf::RenderWindow m_window;

	void init();
	void update(sf::Time dt);
	void render();
	void processEvents();

	void select(sf::Event t_event);
	void computeSelection();

	void checkMatch();

	int elements[400];
	sf::RectangleShape elementsShape[400];

	element piece1;
	element piece2;

};

