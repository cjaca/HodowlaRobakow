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


void Mature::collect()
{
	if (!AntTexture.loadFromFile("img/fly-egg.png"))
	{
		std::cout << "nie mozna zaladowac obrazka :( \n" << std::endl;
	}
	AntSprite.setTexture(AntTexture);

	this->flagaKolizja = false;
	int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	
	 //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie
	
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
	}
}

int Mature::updateMove(sf::Sprite & target)
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
				x = x - 1;
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + 1;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 1;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 1;
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
		if (licznik == a) {
			instrukcja -= 1;
			licznik = 0;
			flagaKolizja = true;
			a1 = 0;
			b1 = 0;
			c1 = 0;
			x = 512;
			y = 520;
			target.setPosition(x, y);
			loadTexture();
			return 1; // kod nr 1 - powiadamia ze jajko zostalo zwrocone do bazy i ma zwiekszyc ilosc zarcia dla much.
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
				x = x - 1;
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + 1;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 1;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 1;
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
		if (licznik == a) {
			instrukcja -= 1;
			licznik = 0;
			a2 = 0;
			b2 = 0;
			c2 = 0;
		}

	}
}


