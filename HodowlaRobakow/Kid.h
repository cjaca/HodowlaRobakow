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
	sf::Sprite KidSprite;
	
	int loadTexture();
	int size=0;


protected:
	sf::RectangleShape HpBar;
	sf::Vector2f position;
	float x;
	float y;
	int a, b, c, licznik, predkosc = 1, a1,b1,c1, a2, b2, c2;
	int instrukcja = 0, wPoziomie = 0, wPionie = 0;
public:
	Kid(sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Kid();
	void draw(sf::RenderTarget & target);
	bool updateMove(sf::Sprite &target);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	void kolizja();
	int getSize();
	void setSize();
	void evolution();
	void hpBar();
	void setMove(sf::Vector2f &target);
	bool flagaKolizja = true; //ustawia flage czy ma kolizjowac
	bool isAsleep = false; //ustawia flage do spania
	int goSleep, wakeUp;
	void sleep(int time);
};

