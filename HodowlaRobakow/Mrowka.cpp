#include "Mrowka.h"
#include <iostream>
#define SPRITE_SPEED	1


Mrowka::Mrowka(sf::Vector2f position)
{
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	AntSprite.setOrigin(16,16);
	AntSprite.setPosition(position);
	a = 0;
	b = 0;
	c = 0;
	licznik = 0;
}

Mrowka::~Mrowka()
{
}

void Mrowka::draw(sf::RenderTarget & target)
{
	target.draw(this->AntSprite);
}

int Mrowka::loadTexture()
{
	if (!AntTexture.loadFromFile("img/ant.png"))
		return -1;
	AntSprite.setTexture(AntTexture);
	return 0;
}


void Mrowka::updateMove(sf::RenderTarget & target, sf::Event &event)
{
	
	if (licznik == a) {
		a = rand() % 100 + 1; //ilosc pol do przejscia
		b = rand() % 2; //okresla x(horyzontalnie) = 0 lub y (pionowo) = 1
		std::cout << b << std::endl;
		c = rand() % 2; //okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
		std::cout << c << std::endl;
		//predkosc = rand() % 3 + 1;
		licznik = 0;
	}

	if (b == 0) {
		if (c == 0)
		{
			x = x - predkosc;
			AntSprite.setRotation(315.f);
		}
		else
		{
			x = x + predkosc;
			AntSprite.setRotation(90.f);
		}
	}
	else
	{
		if (c == 0)
		{
			y = y - predkosc;
			AntSprite.setRotation(0.f);
		}
		else
		{
			y = y + predkosc;
			AntSprite.setRotation(180.f);
		}
	}
	licznik++;


	// Check screen boundaries
	//okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
	if (x < 0) {
		c = 1;
		x = 0;
	}
	if (x > (int)target.getSize().x) {
		c = 0;
		x = target.getSize().x;
	}
	if (y < 0) {
		c = 1;
		y = 0;
	}
	if (y > (int)target.getSize().y) {
		c = 0;
		y = target.getSize().y;
	}

	// Clear the window and apply grey background
	target.clear(sf::Color(50, 50, 50));

	// Rotate and draw the sprite
	AntSprite.setPosition(x, y);
	


}

sf::Sprite *Mrowka::getSprite()
{
	return &this->AntSprite;
}

sf::Vector2f Mrowka::getPosition()
{
	return this->position;
}

bool Mrowka::kolizja(sf::Sprite &target)
{

	if (target.getGlobalBounds().intersects(this->AntSprite.getGlobalBounds()))
	{
		std::cout << "JEB JEB muchy sie zderzyly" << std::endl;
		if (c == 0) {
			this->c = 1;
		}
		else this->c = 0;
		return true;
	}

	return false;
}
