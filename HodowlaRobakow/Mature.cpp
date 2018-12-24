#include "Mature.h"
#include "Egg.h"
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
	if (this->wskaznik == false) {
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
}

bool Mature::collisionWithEgg(sf::Sprite &target)
{
	if (instrukcja == 0 ) {
		if (target.getGlobalBounds().intersects(this->AntSprite.getGlobalBounds()))
		{
			std::cout << "JEB JEB muchy z jajem sie zderzyla" << std::endl;
			if (c == 0) {
				this->c = rand() % 2;
			}
			else this->c = rand() % 2;
			return true;
		}
	}
	return false;
}

void Mature::collect(Egg & jajo)
{
	obiekt = &jajo;
	int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	obiekt->flaga = true; //ustawia flage obiektowi jajo ze jest transportowany
	this->wskaznik = true; //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie
	
	pozycjaMuchyX = this->getPosition().x;
	pozycjaMuchyY = this->getPosition().y;

	//wyznaczanie drogi do gniazda ktore zawsze jest w tym samym miejscu

	wPoziomie = 512.f - pozycjaMuchyX;
	wPionie = 384.f - pozycjaMuchyY;
	if (instrukcja == 0) {
		if (wPoziomie > 0)
		{
			this->a1 = wPoziomie;
			this->b1 = 0;
			this->c1 = 1;
			this->instrukcja++;
			//this->updateMatureMove(jajo);
		}
		if (wPoziomie < 0)
		{
			this->a1 = wPoziomie * (-1);
			this->b1 = 0;
			this->c1 = 0;
			this->instrukcja++;
			//this->updateMatureMove(jajo);
		}
		if (wPionie > 0)
		{
			this->a2 = wPionie;
			this->b2 = 1;
			this->c2 = 1;
			this->instrukcja++;
			this->updateMatureMove(*obiekt);
		}
		if (wPionie < 0)
		{
			this->a2 = wPionie * (-1);
			this->b2 = 1;
			this->c2 = 0;
			this->instrukcja++;
			this->updateMatureMove(*obiekt);
		}
	}
}

void Mature::updateMatureMove(Egg & jajo)
{
	this->licznik = 0;
}
