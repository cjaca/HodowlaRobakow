#pragma once
#include "DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include "AssetManager.h"
class Nest
{
private:
	sf::Texture NestTexture;
	sf::Sprite NestSprite;
	sf::RectangleShape HpBar;
	int loadTexture(AssetManager & assets);
	int level = 1; //poziom
	int food = 50; //jedzenie
	int foodCapacity = 500;
	int garner = 0; //zagroda
	int garnerCapacity = 50;
	int money = 0;

public:
	Nest(AssetManager &assets);
	~Nest();
	void setNestFood(int n);
	int getNestFood();
	void setGarner(int n);
	int getGarner(); //kazda mucha zajmuje wiecej miejsca w zagrodzie
	void setMoney(int n);
	int getMoney();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
};

