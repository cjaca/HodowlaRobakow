#include "Egg.h"



Egg::Egg(sf::Vector2f position)
{
	this->position = position;
	loadTexture();
	EggSprite.setOrigin(16, 16);
	EggSprite.setPosition(position);

}

Egg::~Egg()
{
}

int Egg::loadTexture()
{
	if (!EggTexture.loadFromFile("img/egg.png"))
		return -1;
	EggSprite.setTexture(EggTexture);
	return 0;
}

void Egg::draw(sf::RenderTarget & target)
{
	target.draw(this->EggSprite);
}

void Egg::updateMove(sf::Sprite & target)
{

}

sf::Sprite * Egg::getSprite()
{

	return &this->EggSprite;
}

void Egg::setPosition(int x, int y)
{
	this->EggSprite.setPosition(x, y);
}
