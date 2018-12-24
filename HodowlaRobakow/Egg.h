#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

class Egg
{
	sf::Texture EggTexture;
	sf::Sprite EggSprite;
	sf::Vector2f position;
	
	int loadTexture();
	int size = 0;
public:
	Egg(sf::Vector2f position);
	~Egg();
	void draw(sf::RenderTarget & target);
	void updateMove(sf::Sprite &target);
	sf::Sprite *getSprite();
	void setPosition(int x, int y);
	bool flaga = false;
	bool doZniszczenia = false;
};

