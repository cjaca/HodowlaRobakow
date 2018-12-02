#include "Mature.h"
#define SPRITE_SPEED	1


Mature::Mature(int oria, int orib,sf::Vector2f position)
{
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	AntSprite.setOrigin(oria,orib);
	AntSprite.setPosition(position);
	a = 0;
	b = 0;
	c = 0;
	licznik = 0;
}

Mature::~Mature()
{
}

void Mature::draw(sf::RenderTarget & target)
{
	target.draw(this->AntSprite);
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
