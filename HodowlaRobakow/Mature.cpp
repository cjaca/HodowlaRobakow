#include "Mature.h"
#include "Egg.h"
#define SPRITE_SPEED	1


Mature::Mature(AssetManager &assets, sf::Vector2f position, float lifek, int t): Kid(assets)
{
	manager = &assets;
	life = lifek;
	this->position = position;
	x = position.x;
	y = position.y;
	Load_Texture();
	sprite.setOrigin(12,12);
	sprite.setPosition(position);
	HpBar.setPosition(position.x-3,position.y-3);
	HpBar.setOutlineColor(sf::Color::Red);
	HpBar.setSize(sf::Vector2f(6,6));
	startLife = life;
	bornTime = t;
}

Mature::~Mature()
{
}

void Mature::draw(sf::RenderTarget & target)
{
	target.draw(this->sprite);
	target.draw(this->HpBar);
}

int Mature::Load_Texture()
{
	sprite.setTexture(manager->GetTexture("fly-mature"));
	return 0;
}


sf::Sprite *Mature::getSprite()
{
	return &this->sprite;
}


void Mature::Collect()
{
	sprite.setTexture(manager->GetTexture("fly-egg"));

	int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	this->flagaKolizja = false; 	 //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie	
	m_Carry_Item = true;
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

void Mature::Go_Get_It(sf::Vector2f position)
{
	float pozycjaMuchyX, pozycjaMuchyY;
	this->flagaKolizja = false; 	 //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie	
	this->m_Go_To_Egg = true;
	pozycjaMuchyX = this->getPosition().x;
	pozycjaMuchyY = this->getPosition().y;
	
	//wyznaczanie drogi do gniazda ktore zawsze jest w tym samym miejscu

	wPoziomie = position.x - pozycjaMuchyX;
	wPionie = position.y - pozycjaMuchyY;
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

void Mature::Update_Move()
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
				sprite.setRotation(270.f);
			}
			else
			{
				x = x + predkosc;
				sprite.setRotation(90.f);
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - predkosc;
				sprite.setRotation(0.f);
			}
			else
			{
				y = y + predkosc;
				sprite.setRotation(180.f);
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
		sprite.setPosition(x,y);
		//Change HpBar position with Fly
		this->HpBar.setPosition(x-3, y -3);
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
				x = x - 2;
				this->getSprite()->setRotation(270.f);
				licznik++;
			}
			else
			{
				x = x + 2;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 2;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 2;
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
		sprite.setPosition(x, y);
		this->HpBar.setPosition(x - 3, y - 3);
		if (getPosition().x > 500 && getPosition().x < 530 && getPosition().y > 375 && getPosition().y < 385) {
			instrukcja -= 1;
			
			a1 = 0;
			b1 = 0;
			c1 = 0;
			if (m_Go_To_Egg == false && m_Go_To_Sleep == false && m_Carry_Item == true)
			{

				m_Carry_Item = false;
				flagaKolizja = true;
				Random_Respawn_Position();
				sprite.setPosition(x, y);
				Load_Texture();
				m_Mission_Complete = true; // kod nr 1 - powiadamia ze jajko zostalo zwrocone do bazy i ma zwiekszyc ilosc zarcia dla much.
			}
			else if (m_Go_To_Egg == true)
			{
				flagaKolizja = true;
				m_Go_To_Egg = false;
			}
			if (m_Go_To_Sleep == true)
			{
				Random_Respawn_Position();
				this->m_Go_To_Sleep = false;
				this->isAsleep = true; //ustawia flage ze mucha spi i zeby jej nie ruszac
				this->goSleep = size;
				this->wakeUp = size + 300;
				collectedInfo = false;
			}

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
				x = x - 2;
				this->getSprite()->setRotation(270.f);
				licznik++;
			}
			else
			{
				x = x + 2;
				this->getSprite()->setRotation(90.f);
				licznik++;
			}
		}
		else
		{
			if (c == 0)
			{
				y = y - 2;
				this->getSprite()->setRotation(0.f);
				licznik++;
			}
			else
			{
				y = y + 2;
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
		sprite.setPosition(x, y);
		this->HpBar.setPosition(x - 3, y - 3);
		if (getPosition().y > 375 && getPosition().y < 385) {
			instrukcja -= 1;
			licznik = 0;
			a2 = 0;
			b2 = 0;
			c2 = 0;
		}

	}
}



