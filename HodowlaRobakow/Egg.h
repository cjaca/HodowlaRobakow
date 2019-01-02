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
	sf::Font Trebu; 
	sf::Text timeLeftToAutoDestroy;
	int loadTexture();
	int size = 0;
public:
	Egg(sf::Vector2f position);
	~Egg();
	void draw(sf::RenderTarget & target);
	void updateMove(int x, int y);
	sf::Sprite *getSprite();
	void setPosition(int x, int y);
	int getSize();
	void setSize(); // increase size by 1
	bool flaga = false;
	bool doZniszczenia = false;
	void timeLeft();
};

