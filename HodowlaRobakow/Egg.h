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
	
	int loadTexture();
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Font Trebu;
	sf::Text timeLeftToAutoDestroy;
	int size = 0;
public:
	Egg(sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Egg();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	void setPosition(int x, int y);
	sf::Vector2f getPosition();
	int getSize();
	void setSize(); // increase size by 1
	void timeLeft();
	bool flaga = false;
	bool doZniszczenia = false;
};

