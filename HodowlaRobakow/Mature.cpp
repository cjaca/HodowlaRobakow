#include "Mature.h"
#include "Egg.h"
#define SPRITE_SPEED	1


Mature::Mature(AssetManager &assets, sf::Vector2f position): Kid(assets)
{
	manager = &assets;
	life = 200;
	this->position = position;
	x = position.x;
	y = position.y;
	loadTexture();
	sprite.setOrigin(12,12);
	sprite.setPosition(position);
	HpBar.setPosition(position.x-3,position.y-3);
	HpBar.setOutlineColor(sf::Color::Red);
	HpBar.setSize(sf::Vector2f(6,6));
}

Mature::~Mature()
{
}

void Mature::draw(sf::RenderTarget & target)
{
	target.draw(this->sprite);
	target.draw(this->HpBar);
}

int Mature::loadTexture()
{
	sprite.setTexture(manager->GetTexture("fly-mature"));
	return 0;
}


sf::Sprite *Mature::getSprite()
{
	return &this->sprite;
}

// void Mature::setSize(float k) //TODO: Ogarnac setSize aby byl wspolny dla wszystkich, tak na prawde to zmienia sie tylko zaleznosci od life
// {
// 	int rozmiarPaskaHP;
// 	//set size of Fly
// 	this->size = this->size + 1;
// 	if (isAsleep == false)
// 	{
// 		life = life - k;
// 	}
// 	if (life <= 0)
// 	{
// 		isDead = true;
// 	}

// 	int kolorG = 2.55 * life;
// 	HpBar.setFillColor(sf::Color(255, kolorG, 0));
// 	HpBar.setSize(sf::Vector2f(6,6));
// }

void Mature::collect()
{
	sprite.setTexture(manager->GetTexture("fly-egg"));

	int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	this->flagaKolizja = false; 	 //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie	
	carryItem = true;
	pozycjaMuchyX = this->getPosition().x;
	pozycjaMuchyY = this->getPosition().y;

	//wyznaczanie drogi do gniazda ktore zawsze jest w tym samym miejscu

	//TODO: zrobic z tego oddzieln� metod� w klasie bazowej \/
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

void Mature::goGetIt(sf::Vector2f position)
{
	//int x, y;
	float pozycjaMuchyX, pozycjaMuchyY;
	this->flagaKolizja = false; 	 //ustawia flage musze ze jest zajeta i zeby wiedziala ze sie nie odbija od innych w tym momencie	
	this->goToEgg = true;
	pozycjaMuchyX = this->getPosition().x;
	pozycjaMuchyY = this->getPosition().y;
	
	//wyznaczanie drogi do gniazda ktore zawsze jest w tym samym miejscu

	wPoziomie = position.x - pozycjaMuchyX;
	wPionie = position.y - pozycjaMuchyY;
	//std::cout << "Mucha dostala info ze jajko jest na pozycji "<< position.x<< " "<< position.y << std::endl;
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
				target.setRotation(270.f);
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
		target.setPosition(x,y);
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
		target.setPosition(x, y);
		this->HpBar.setPosition(x - 3, y - 3);
		if (getPosition().x > 500 && getPosition().x < 530 && getPosition().y > 375 && getPosition().y < 385) {
			instrukcja -= 1;
			
			a1 = 0;
			b1 = 0;
			c1 = 0;
			if (goToEgg == false && goToSleep == false && carryItem == true)
			{
				carryItem = false;
				flagaKolizja = true;
				randRespawnPosition();
				target.setPosition(x, y);
				loadTexture();
				return 1; // kod nr 1 - powiadamia ze jajko zostalo zwrocone do bazy i ma zwiekszyc ilosc zarcia dla much.
			}
			else if (goToEgg == true)
			{
				flagaKolizja = true;
				//std::cout << "powinienem teraz podniesc jajko " << std::endl;
				goToEgg = false;
			}
			if (goToSleep == true)
			{
				randRespawnPosition();
				this->goToSleep = false;
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
		target.setPosition(x, y);
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



