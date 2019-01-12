#pragma once
#include "Egg.h"
class Coin : public Egg
{
public:
	Coin(AssetManager &assets, sf::Vector2f position);
	~Coin();
private:
	int LoadTexture();
};

