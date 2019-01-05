#include "Egg.h"
#include <string>


Egg::Egg(sf::Vector2f position)
{
	this->position = position;
	loadTexture();
	sprite.setOrigin(16, 16);
	sprite.setPosition(position);
	if (!Trebu.loadFromFile("font/TrebuchetMS.ttf"))
	{
		std::cout << "Missing Trebuchet font\n" << std::endl;
	}
	timeLeftToAutoDestroy.setFont(Trebu);
	timeLeftToAutoDestroy.setCharacterSize(12);
	timeLeftToAutoDestroy.setFillColor(sf::Color::Black);
	timeLeftToAutoDestroy.setOrigin(6, 6);
	timeLeftToAutoDestroy.setPosition(position);
}

Egg::~Egg()
{
}

int Egg::loadTexture()
{
	if (!EggTexture.loadFromFile("img/egg.png"))
		return -1;
	sprite.setTexture(EggTexture);
	return 0;
}

void Egg::draw(sf::RenderTarget & target)
{
	timeLeft();
	target.draw(sprite);
	target.draw(timeLeftToAutoDestroy);
}


sf::Sprite * Egg::getSprite()
{

	return &this->sprite;
}

void Egg::setPosition(int x, int y)
{
	this->sprite.setPosition(x, y);
}

sf::Vector2f Egg::getPosition()
{
	return this->position;
}

int Egg::getSize()
{
	return size;
}

void Egg::setSize()
{
	this->size = this->size + 1;
}

void Egg::timeLeft()
{
	std::string s = std::to_string(((this->size - 900)*-1)/30);
	timeLeftToAutoDestroy.setString(s);
}
