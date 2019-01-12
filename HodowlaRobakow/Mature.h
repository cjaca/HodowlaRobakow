#pragma once
#include "Kid.h"

class Mature : public Kid
{
public:
	Mature(AssetManager &assets, sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600), float lifek = 200.0);
	~Mature();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	void Collect();
	void Go_Get_It(sf::Vector2f position);
	void Update_Move();
	bool m_Go_To_Egg = false;
	bool m_Go_To_Sleep = false; 
	bool m_Carry_Item = false;
	bool m_Mission_Complete = false;
private:
	sf::Sprite sprite;
	sf::Vector2f position;
	int Load_Texture();
};

