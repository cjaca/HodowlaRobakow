#pragma once
#include "DEFINITIONS.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Egg
{
public:
	Egg(AssetManager &assets, sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Egg();
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	void draw(sf::RenderTarget & target);
	void setPosition(int x, int y);
	int getSize();
	void setSize();
	void timeLeft();
	bool flaga = false;
	bool doZniszczenia = false;
protected:
	AssetManager *manager;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Text timeLeftToAutoDestroy;
	int m_Size = 0;
private:
	int Load_Texture();
};

