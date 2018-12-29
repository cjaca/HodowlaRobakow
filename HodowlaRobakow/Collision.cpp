#include "Collision.h"

//test from different machine

Collision::Collision()
{
}


Collision::~Collision()
{
}

bool Collision::CheckCollision(sf::Sprite & sprite1, sf::Sprite & sprite2)
{
	if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
	{
		return true;
	}
		return false;
}
