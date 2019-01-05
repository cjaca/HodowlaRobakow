#include "Coin.h"
#include <string>


Coin::Coin(sf::Vector2f position)
{
	this->position = position;
	loadTexture();
	sprite.setOrigin(12, 12);
	sprite.setPosition(position);
	if (!Trebu.loadFromFile("font/TrebuchetMS.ttf"))
	{
		std::cout << "Missing Trebuchet font\n" << std::endl;
	}
	timeLeftToAutoDestroy.setFont(Trebu);
	timeLeftToAutoDestroy.setCharacterSize(10);
	timeLeftToAutoDestroy.setFillColor(sf::Color::Black);
	timeLeftToAutoDestroy.setOrigin(5, 5);
	timeLeftToAutoDestroy.setPosition(position.x-1,position.y);
}



Coin::~Coin()
{
}


int Coin::loadTexture()
{
	if (!coinTexture.loadFromFile("img/coin.png"))
		return -1;
	sprite.setTexture(coinTexture);
	return 0;
}