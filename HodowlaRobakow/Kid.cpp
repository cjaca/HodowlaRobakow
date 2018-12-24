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

bool Kid::updateMove(sf::Sprite &target)
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
				obiekt->getSprite()->setRotation(315.f);
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + 1;
				obiekt->getSprite()->setRotation(90.f);
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 1;
				obiekt->getSprite()->setRotation(0.f);
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 1;
				obiekt->getSprite()->setRotation(180.f);
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
		

		//Change HpBar position with Fly
		obiekt->setPosition(x, y);
		target.setPosition(x, y);
		this->HpBar.setPosition(x - 10, y + 10);
		if (licznik == a) {
			instrukcja -= 1;
			licznik = 0;
			wskaznik = false;
			//obiekt->~Egg();
			obiekt->doZniszczenia = true;
			obiekt = nullptr;
			a1 = 0;
			b1 = 0;
			c1 = 0;
			x = 512;
			y = 520;
			target.setPosition(x, y);
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
				obiekt->getSprite()->setRotation(315.f);
				this->getSprite()->setRotation(315.f);
				licznik++;
			}
			else
			{
				x = x + 1;
				obiekt->getSprite()->setRotation(90.f);
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 1;
				obiekt->getSprite()->setRotation(0.f);
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 1;
				obiekt->getSprite()->setRotation(180.f);
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
		

		//Change HpBar position with Fly
		obiekt->setPosition(x, y);
		target.setPosition(x, y);
		this->HpBar.setPosition(x - 10, y + 10);
		if (licznik == a) {
			instrukcja -= 1;
			licznik = 0;
			a2 = 0;
			b2 = 0;
			c2 = 0;
			//wskaznik = false;
			//obiekt->~Egg();
			//obiekt->doZniszczenia = true;
			//obiekt = nullptr;
		}
		
	}

	
	return false;
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

bool Kid::kolizja(sf::Sprite &target, bool kolizyjny)
{
	if (kolizyjny == true) {
		if (target.getGlobalBounds().intersects(this->KidSprite.getGlobalBounds()))
		{
			std::cout << "JEB JEB muchy sie zderzyly" << std::endl;
			if (c == 0) {
				this->c = rand() % 2;
			}
			else this->c = rand() % 2;
			return true;
		}
	}


	return false;
}

int Kid::getSize()
{
	return size;
}

void Kid::setSize()
{
	int rozmiarPaskaHP;
	//set size of Fly
	size = size + 1;
	//change color of HpBar
	int kolor = 0.5*size;
	if (size < 500) {
		rozmiarPaskaHP = 0.04*size;
	}
	else {
		rozmiarPaskaHP = (0.04*size) - 20;
	}
	HpBar.setFillColor(sf::Color(kolor, 250-kolor, 0));
	HpBar.setSize(sf::Vector2f(20-rozmiarPaskaHP, 4));
}

void Kid::hpBar()
{
	HpBar.setSize(sf::Vector2f(20, 4));
	HpBar.setOutlineColor(sf::Color::Red);
	HpBar.setPosition(position);

}

void Kid::setMove(sf::Vector2f & target)
{
	float xtarget = target.x;
	float ytarget = target.y;
}
