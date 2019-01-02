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
	int level = 0; //poziom
	int food = 0; //jedzenie
	int garner = 0; //zagroda


public:
	Nest();
	~Nest();
	void nestFood(int n);
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
};

