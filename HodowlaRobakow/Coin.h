#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "Egg.h"
class Coin : public Egg
{
	sf::Texture coinTexture;
	//sf::Sprite sprite;
	int loadTexture();

public:
	Coin(AssetManager &assets, sf::Vector2f position);
	~Coin();
};

