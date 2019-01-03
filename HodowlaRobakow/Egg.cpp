#include "Egg.h"
#include <string>


Egg::Egg(sf::Vector2f position)
{
	this->position = position;
	loadTexture();
	EggSprite.setOrigin(16, 16);
	EggSprite.setPosition(position);
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
	EggSprite.setTexture(EggTexture);
	return 0;
}

void Egg::draw(sf::RenderTarget & target)
{
	timeLeft();
	target.draw(this->EggSprite);
	target.draw(this->timeLeftToAutoDestroy);
}

void Egg::updateMove(int x, int y)
{
	this->setPosition(x, y);
}

sf::Sprite * Egg::getSprite()
{

	return &this->EggSprite;
}

void Egg::setPosition(int x, int y)
{
	this->EggSprite.setPosition(x, y);
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
