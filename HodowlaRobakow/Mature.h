#pragma once
#include "Kid.h"
#include "Egg.h"
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
	Mature(sf::Vector2f position);
	~Mature();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	void collect();
	void goGetIt(sf::Vector2f position);
	void setSize();
	int updateMove(sf::Sprite &target);
	bool goToEgg = false;
	bool goToSleep = false;
};

