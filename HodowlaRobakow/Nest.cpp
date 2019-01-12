#include "Nest.h"

Nest::Nest(AssetManager & assets)
{
	Load_Texture(assets);
	NestSprite.setOrigin(50, 50);
	NestSprite.setPosition(RESPAWN_WIDTH / 2, RESPAWN_HEIGHT / 2);
}


Nest::~Nest()
{
}

void Nest::setNestFood(int n)
{
	food = food + n;
}

int Nest::getNestFood()
{
	return food;
}

void Nest::setMoney(int n)
{
	money = money + n;
}

int Nest::getMoney()
{
	return money;
}

void Nest::draw(sf::RenderTarget & target)
{
	target.draw(this->NestSprite);
}

sf::Sprite * Nest::getSprite()
{
	return &this->NestSprite;
}

int Nest::Load_Texture(AssetManager &assets)
{
	if (!NestTexture.loadFromFile("img/nest.png"))
		return -1;
	NestSprite.setTexture(assets.GetTexture("nest"));
	return 0;
}