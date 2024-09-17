#pragma once
#include <SFML/Graphics.hpp>

int const ELEMENT_COUNT = 400;

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

	int elements[400];
	sf::RectangleShape elementsShape[400];
};

