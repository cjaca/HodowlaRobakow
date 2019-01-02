#include "Nest.h"

Nest::Nest()
{
	loadTexture();
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

void Nest::draw(sf::RenderTarget & target)
{
	target.draw(this->NestSprite);
}

sf::Sprite * Nest::getSprite()
{
	return &this->NestSprite;
}

int Nest::loadTexture()
{
	if (!NestTexture.loadFromFile("img/nest.png"))
		return -1;
	NestSprite.setTexture(NestTexture);
	return 0;
}