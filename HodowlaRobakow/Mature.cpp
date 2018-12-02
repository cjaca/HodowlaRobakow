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
	//AntSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	return 0;
}


//void Mature::updateMove()
//{
//
//	position.x = x;
//	position.y = y;
//	
//	if (licznik == a) {
//		a = rand() % 100 + 1; //ilosc pol do przejscia
//		b = rand() % 2; //okresla x(horyzontalnie) = 0 lub y (pionowo) = 1
//		c = rand() % 2; //okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
//		predkosc = rand() % 3 + 1;
//		licznik = 0;
//	}
//
//	if (b == 0) {
//		if (c == 0)
//		{
//			x = x - predkosc;
//			AntSprite.setRotation(315.f);
//		}
//		else
//		{
//			x = x + predkosc;
//			AntSprite.setRotation(90.f);
//		}
//	}
//	else
//	{
//		if (c == 0)
//		{
//			y = y - predkosc;
//			AntSprite.setRotation(0.f);
//		}
//		else
//		{
//			y = y + predkosc;
//			AntSprite.setRotation(180.f);
//		}
//	}
//	licznik++;
//
//
//	// Check screen boundaries
//	//okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
//	if (x < 0) {
//		c = 1;
//		x = 0;
//	}
//	if (x > SCREEN_WIDTH) {
//		c = 0;
//		x = SCREEN_WIDTH;
//	}
//	if (y < 0) {
//		c = 1;
//		y = 0;
//	}
//	if (y > SCREEN_HEIGHT) {
//		c = 0;
//		y = SCREEN_HEIGHT;
//	}
//
//	// Clear the window and apply grey background
//	//target.clear(sf::Color(50, 50, 50));
//
//	position.x = x;
//	position.y = y;
//
//	// Rotate and draw the sprite
//	AntSprite.setPosition(x, y);
//	
//
//
//}

sf::Sprite *Mature::getSprite()
{
	return &this->AntSprite;
}

//sf::Vector2f Mature::getPosition()
//{
//	position.x = x;
//	position.y = y;
//	return sf::Vector2f(position);
//}

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

//float Mature::GetX() const
//{
//	return x;
//}
//
//float Mature::GetY() const {
//	return y;
//}