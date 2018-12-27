#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
class Menu
{
public:

	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &target);
};

