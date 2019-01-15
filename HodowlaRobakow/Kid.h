#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "DEFINITIONS.h"
#include "AssetManager.h"


class Kid
{
public:
	Kid(AssetManager &assets, sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600), float lifek = 100.0, int t = 0);
	~Kid();
	void draw(sf::RenderTarget & target);
	void Update_Move(sf::Sprite &target);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	void Random_Respawn_Position();
	void kolizja();
	void setSize(float k);
	void sleep(int time);
	void setPosition(sf::Vector2f position);
	void gatherInfo(sf::Vector2f position);
	int getSize();
	int goSleep, wakeUp;
	int instrukcja = 0;
	int predkosc = 1;
	int startLife;
	int bornTime;
	float life; //wartosc poczatkowa zycia muchy
	bool flagaKolizja = true; //ustawia flage czy ma kolizjowac
	bool isAsleep = false; //ustawia flage do spania
	bool collectedInfo = false; // flaga ktora mowi czy mucha ma info gdzie jest jajo
	bool isDead = false; //jezeli life<=0 to zmieni status na true, i mucha powinna zostac usunieta
	sf::Vector2f itemPosition;
protected:
	AssetManager *manager;
	sf::RectangleShape HpBar;
	sf::Vector2f position;
	int a, b, c, licznik, a1, b1, c1, a2, b2, c2;
	int wPoziomie = 0, wPionie = 0;
	int size = 0;
	float x, y;
private:
	sf::Sprite sprite;
	int Load_Texture();
};

