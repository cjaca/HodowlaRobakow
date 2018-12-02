#include "Kid.h"



Kid::Kid(int oria, int orib, sf::Vector2f position)
{
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	KidSprite.setOrigin(oria, orib);
	KidSprite.setPosition(position);
	a = 0;
	b = 0;
	c = 0;
	licznik = 0;
}


Kid::~Kid()
{
}

void Kid::draw(sf::RenderTarget & target)
{
	target.draw(this->KidSprite);
}

int Kid::loadTexture()
{
	if (!KidTexture.loadFromFile("img/kid.png"))
		return -1;
	KidSprite.setTexture(KidTexture);
	return 0;
}

void Kid::updateMove(sf::Sprite &target)
{
	if (licznik == a) {
		a = rand() % 100 + 1; //ilosc pol do przejscia
		b = rand() % 2; //okresla x(horyzontalnie) = 0 lub y (pionowo) = 1
		c = rand() % 2; //okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
		predkosc = rand() % 4 + 2;
		licznik = 0;
	}

	if (b == 0) {
		if (c == 0)
		{
			x = x - predkosc;
			target.setRotation(315.f);
		}
		else
		{
			x = x + predkosc;
			target.setRotation(90.f);
		}
	}
	else
	{
		if (c == 0)
		{
			y = y - predkosc;
			target.setRotation(0.f);
		}
		else
		{
			y = y + predkosc;
			target.setRotation(180.f);
		}
	}
	licznik++;


	// Check screen boundaries
	//okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
	if (x < 0) {
		c = 1;
		x = 0;
	}
	if (x > SCREEN_WIDTH) {
		c = 0;
		x = SCREEN_WIDTH;
	}
	if (y < 0) {
		c = 1;
		y = 0;
	}
	if (y > SCREEN_HEIGHT) {
		c = 0;
		y = SCREEN_HEIGHT;
	}

	// Clear the window and apply grey background
	//target.clear(sf::Color(50, 50, 50));

	// Rotate and draw the sprite
	target.setPosition(x, y);

}

sf::Sprite *Kid::getSprite()
{
	return &this->KidSprite;
}

sf::Vector2f Kid::getPosition()
{
	position.x = x;
	position.y = y;
	return this->position;
}

bool Kid::kolizja(sf::Sprite &target)
{

	if (target.getGlobalBounds().intersects(this->KidSprite.getGlobalBounds()))
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

int Kid::getSize()
{
	return size;
}

void Kid::setSize()
{
	size = size + 1;
}
