#pragma once
#include "Mature.h"
class Old: public Mature
{
private:
	sf::Texture OldTexture;
	sf::Sprite sprite;
	sf::Vector2f position;
	int Load_Texture();
public:
	Old(AssetManager &assets, sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600), float lifek = 300.0);
	~Old();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	void Update_Move(sf::Sprite &target);
	void loadCoinTexture();
	void Go_Get_It(sf::Vector2f position);
	bool givingBirth = false;
};

