#include "Coin.h"



Coin::Coin(AssetManager &assets, sf::Vector2f position): Egg(assets)
{
	manager = &assets;
	this->position = position;
	LoadTexture();
	sprite.setOrigin(12, 12);
	sprite.setPosition(position);
	timeLeftToAutoDestroy.setFont(manager->GetFont("trebu"));
	timeLeftToAutoDestroy.setCharacterSize(10);
	timeLeftToAutoDestroy.setFillColor(sf::Color::Black);
	timeLeftToAutoDestroy.setOrigin(5, 5);
	timeLeftToAutoDestroy.setPosition(position.x-1,position.y);
}



Coin::~Coin()
{
}


int Coin::LoadTexture()
{
	sprite.setTexture(manager->GetTexture("coin"));
	return 0;
}