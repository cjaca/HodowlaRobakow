#include "Mature.h"
#define SPRITE_SPEED	1


Mature::Mature(sf::Vector2f position)
{
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	AntSprite.setOrigin(12,12);
	AntSprite.setPosition(position);

	hpBar();
}

Mature::~Mature()
{
}

void Mature::draw(sf::RenderTarget & target)
{
	target.draw(this->AntSprite);
	target.draw(this->HpBar);
}

int Mature::loadTexture()
{
	if (!AntTexture.loadFromFile("img/fly.png"))
		return -1;
	AntSprite.setTexture(AntTexture);
	return 0;
}




sf::Sprite *Mature::getSprite()
{
	return &this->AntSprite;
}


bool Mature::kolizja(sf::Sprite &target)
{

	if (target.getGlobalBounds().intersects(this->AntSprite.getGlobalBounds()))
	{
		std::cout << "JEB JEB muchy sie zderzyly" << std::endl;
		if (c == 0) {
			this->c = rand() % 2;
		}
		else this->c = rand() % 2;
		return true;
	}

	return false;
}
