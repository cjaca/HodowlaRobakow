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


public:
	
	Mature(int oria, int orib, sf::Vector2f position);
	~Mature();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	bool kolizja(sf::Sprite &target);
};

