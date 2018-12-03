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
	//sf::RectangleShape HpBar;
	
	int loadTexture();

	int size=0;

protected:
	sf::RectangleShape HpBar;
	sf::Vector2f position;
	float x;
	float y;
	int a, b, c, licznik, predkosc = 1;

public:
	Kid(sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Kid();
	void draw(sf::RenderTarget & target);
	void updateMove(sf::Sprite &target);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	bool kolizja(sf::Sprite &target);
	int getSize();
	void setSize();
	void evolution();
	void hpBar();
};

