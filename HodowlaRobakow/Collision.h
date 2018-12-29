#pragma once
#include <SFML\Graphics.hpp>

class Collision
{
public:
	Collision();
	~Collision();
	bool CheckCollision(sf::Sprite &sprite1, sf::Sprite &sprite2);
};

