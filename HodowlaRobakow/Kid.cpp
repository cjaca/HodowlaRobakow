#include "Kid.h"



Kid::Kid(sf::Vector2f position)
{
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	KidSprite.setOrigin(8,8);
	KidSprite.setPosition(position);
	a = 0;
	b = 0;
	c = 0;
	licznik = 0;
	hpBar();
}


Kid::~Kid()
{
}

void Kid::draw(sf::RenderTarget & target)
{
	target.draw(this->KidSprite);
	target.draw(HpBar);
}

int Kid::loadTexture()
{
	if (!KidTexture.loadFromFile("img/kid.png"))
		return -1;
	KidSprite.setTexture(KidTexture);
	return 0;
}


int Kid::updateMove(sf::Sprite & target)
{
	if (instrukcja == 0) {
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
		if (x > RESPAWN_WIDTH) {
			c = 0;
			x = RESPAWN_WIDTH;
		}
		if (y < 0) {
			c = 1;
			y = 0;
		}
		if (y > RESPAWN_HEIGHT) {
			c = 0;
			y = RESPAWN_HEIGHT;
		}

		// Rotate and draw the sprite
		target.setPosition(x, y);
		//Change HpBar position with Fly
		this->HpBar.setPosition(x - 10, y + 10);
	}
	if (instrukcja == 1)
	{
		if (licznik == 0) {
			a = a1;
			b = b1;
			c = c1;

		}
		if (b == 0) {
			if (c == 0)
			{
				x = x - predkosc;
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + predkosc;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - predkosc;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + predkosc;
				this->getSprite()->setRotation(180.f);
				licznik++;
			}
		}
		// Check screen boundaries
		//okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
		if (x < 0) {
			c = 1;
			x = 0;
		}
		if (x > RESPAWN_WIDTH) {
			c = 0;
			x = RESPAWN_WIDTH;
		}
		if (y < 0) {
			c = 1;
			y = 0;
		}
		if (y > RESPAWN_HEIGHT) {
			c = 0;
			y = RESPAWN_HEIGHT;
		}


		//Change HpBar position with Fly
		target.setPosition(x, y);
		this->HpBar.setPosition(x - 10, y + 10);
		if (getPosition().x > 500 && getPosition().x < 530 && getPosition().y > 375 && getPosition().y < 385) {
			instrukcja -= 1;
			licznik = a;
			a1 = 0;
			b1 = 0;
			c1 = 0;
			x = 512;
			y = 520;
			this->isAsleep = true; //ustawia flage ze mucha spi i zeby jej nie ruszac
			this->goSleep = this->size;
			this->wakeUp = this->size + 300;
			collectedInfo = false;
		}

	}

	if (instrukcja == 2)
	{
		if (licznik == 0) {
			a = a2;
			b = b2;
			c = c2;
		}
		if (b == 0) {
			if (c == 0)
			{
				x = x - predkosc;
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + predkosc;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - predkosc;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + predkosc;
				this->getSprite()->setRotation(180.f);
				licznik++;
			}
		}
		// Check screen boundaries
		//okresla kierunek 0 to minus(w lewo, w dol), 1 to plus(w prawo, do gory)
		if (x < 0) {
			c = 1;
			x = 0;
		}
		if (x > RESPAWN_WIDTH) {
			c = 0;
			x = RESPAWN_WIDTH;
		}
		if (y < 0) {
			c = 1;
			y = 0;
		}
		if (y > RESPAWN_HEIGHT) {
			c = 0;
			y = RESPAWN_HEIGHT;
		}


		//Change HpBar position with Fly
		target.setPosition(x, y);
		this->HpBar.setPosition(x - 10, y + 10);
		if (getPosition().y > 375 && getPosition().y < 385) {
			instrukcja -= 1;
			licznik = 0;
			a2 = 0;
			b2 = 0;
			c2 = 0;
		}

	}
	return 0;
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

void Kid::kolizja()
{
	if (this->flagaKolizja == true)
	{
		if (c == 0) {
			this->c = rand() % 2;
		}
		else this->c = rand() % 2;
	}

}

void Kid::gatherInfo(sf::Vector2f position)
{
	this->collectedInfo = true;
	this->eggPosition = position;
}

int Kid::getSize()
{
	return this->size;
}

void Kid::setSize()
{
	int rozmiarPaskaHP;
	//set size of Fly
	size = size+1;
	if (isAsleep == false)
	{
		life = life - 0.22;
	}
	if (life <= 0)
	{
		isDead = true;
	}
	
	int kolorG = 2.55 * life;
	if (life <= 100 ) {
		rozmiarPaskaHP = life/5;
	}
	else {
		rozmiarPaskaHP = (0.01*life) - 20;
	}
	HpBar.setFillColor(sf::Color(255, kolorG, 0));
	HpBar.setSize(sf::Vector2f(rozmiarPaskaHP, 4));
}

void Kid::hpBar()
{
	HpBar.setSize(sf::Vector2f(20, 4));
	HpBar.setOutlineColor(sf::Color::Red);
	HpBar.setPosition(position);

}

void Kid::setPosition(sf::Vector2f target)
{
	this->KidSprite.setPosition(target);
}


void Kid::sleep(int time)
{
	int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	this->flagaKolizja = false; 	//this->wskaznik = true; //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie
	pozycjaMuchyX = this->getPosition().x;
	pozycjaMuchyY = this->getPosition().y;

	//wyznaczanie drogi do gniazda ktore zawsze jest w tym samym miejscu

	wPoziomie = 512.f - pozycjaMuchyX;
	wPionie = 384.f - pozycjaMuchyY;
	if (instrukcja == 0) {
		if (wPoziomie > 0) // ---->
		{
			this->a1 = wPoziomie;
			this->b1 = 0;
			this->c1 = 1;
			this->instrukcja++;
			this->licznik = 0;
		}
		if (wPoziomie < 0) // <-----
		{
			this->a1 = wPoziomie * (-1);
			this->b1 = 0;
			this->c1 = 0;
			this->instrukcja++;
			this->licznik = 0;
		}
		if (wPionie > 0) //  \/
		{
			this->a2 = wPionie;
			this->b2 = 1;
			this->c2 = 1;
			this->instrukcja++;
			this->licznik = 0;
		}
		if (wPionie < 0) //  ^
		{
			this->a2 = wPionie * (-1);
			this->b2 = 1;
			this->c2 = 0;
			this->instrukcja++;
			this->licznik = 0;
		}
		if (wPoziomie == 0)
		{
			this->a1 = a2;
			this->b1 = b2;
			this->c1 = c2;
			this->licznik = 0;
		}
		if (wPionie == 0)
		{
			this->a2 = a1;
			this->b2 = b1;
			this->c2 = c1;
			this->licznik = 0;
		}
	}


}
