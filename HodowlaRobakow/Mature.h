#pragma once
#include "Kid.h"
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>




class Mature : public Kid
{

private:

	sf::Texture AntTexture;
	sf::Sprite AntSprite;
	sf::Vector2f position;
	int loadTexture();
	//float x;
	//float y;
	//float a, b, c, licznik, predkosc = 1;


public:
	
	Mature(int oria, int orib, sf::Vector2f position);
	~Mature();
	void draw(sf::RenderTarget & target);
	//void updateMove();
	sf::Sprite *getSprite();
	//sf::Vector2f getPosition();
	bool kolizja(sf::Sprite &target);
	//float GetX() const;
	//float GetY() const;
};

