#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
class Nest
{
private:
	sf::Texture NestTexture;
	sf::Sprite NestSprite;
	sf::RectangleShape HpBar;
	int loadTexture();
	int level = 0;
	int food = 0;
	int garner = 0;


public:
	Nest();
	~Nest();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
};

