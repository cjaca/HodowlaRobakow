#pragma once
#include "Mature.h"
class Old: public Mature
{
private:
	sf::Texture OldTexture;
	sf::Sprite sprite;
	sf::Vector2f position;
	int loadTexture();

public:
	Old(AssetManager &assets, sf::Vector2f position = sf::Vector2f(rand() % 800, rand() % 600));
	~Old();
	void draw(sf::RenderTarget & target);
	sf::Sprite *getSprite();
	//void setSize(float k);
	int updateMove(sf::Sprite &target);
	void loadCoinTexture();
	void goGetIt(sf::Vector2f position);
	bool givingBirth = false;
};

