#pragma once
#include "DEFINITIONS.h"
#include "Egg.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

class Kid
{

private:
	sf::Texture KidTexture;
	sf::Sprite sprite;
	int loadTexture();

protected:
	sf::RectangleShape HpBar;
	sf::Vector2f position;
	float x;
	float y;
	int a, b, c, licznik, predkosc = 1, a1,b1,c1, a2, b2, c2;
	int wPoziomie = 0, wPionie = 0;
	int size = 0;
public:
	Kid(sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Kid();
	void draw(sf::RenderTarget & target);
	int updateMove(sf::Sprite &target);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	sf::Vector2f eggPosition;
	void kolizja();
	void gatherInfo(sf::Vector2f position);
	int getSize();
	void setSize();
	void hpBar();
	void setPosition(sf::Vector2f position);
	bool flagaKolizja = true; //ustawia flage czy ma kolizjowac
	bool isAsleep = false; //ustawia flage do spania
	void sleep(int time);
	int goSleep, wakeUp;
	int instrukcja = 0;
	bool collectedInfo = false; // flaga ktora mowi czy mucha ma info gdzie jest jajo
	float life = 100; //wartosc poczatkowa zycia muchy
	bool isDead = false; //jezeli life<=0 to zmieni status na true, i mucha powinna zostac usunieta
	
};

