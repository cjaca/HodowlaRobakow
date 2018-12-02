#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

class Kid
{

private:

	sf::Texture KidTexture;
	sf::Sprite KidSprite;
	
	int loadTexture();

	int size=0;

protected:
	sf::Vector2f position;
	float x;
	float y;
	int a, b, c, licznik, predkosc = 1;

public:
	Kid(int oria = 8, int orib = 8, sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
	~Kid();
	void draw(sf::RenderTarget & target);
	void updateMove(sf::Sprite &target);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	bool kolizja(sf::Sprite &target);
	int getSize();
	void setSize();
	void evolution();
};

