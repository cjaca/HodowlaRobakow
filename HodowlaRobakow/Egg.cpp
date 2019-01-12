#include "Egg.h"



Egg::Egg(AssetManager &assets, sf::Vector2f position)
{
	manager = &assets;
	this->position = position;
	Load_Texture();
	sprite.setOrigin(16, 16);
	sprite.setPosition(position);
	timeLeftToAutoDestroy.setFont(manager->GetFont("trebu"));
	timeLeftToAutoDestroy.setCharacterSize(12);
	timeLeftToAutoDestroy.setFillColor(sf::Color::Black);
	timeLeftToAutoDestroy.setOrigin(6, 6);
	timeLeftToAutoDestroy.setPosition(position);
}

Egg::~Egg()
{
}

int Egg::Load_Texture()
{
	sprite.setTexture(manager->GetTexture("egg"));
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
	return m_Size;
}

void Egg::setSize()
{
	this->m_Size = this->m_Size + 1;
}

void Egg::timeLeft()
{
	std::string s = std::to_string(((this->m_Size - 900)*-1)/30);
	timeLeftToAutoDestroy.setString(s);
}
