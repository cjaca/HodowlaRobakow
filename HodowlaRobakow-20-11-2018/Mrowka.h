#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>




class Mrowka 
{

private:

	sf::Texture AntTexture;
	sf::Sprite AntSprite;
	sf::Vector2f position;
	int loadTexture();
	float x;
	float y;
	int a, b, c, licznik, predkosc = 5;


public:
	
	Mrowka(sf::Vector2f position);
	~Mrowka();
	void draw(sf::RenderTarget & target);
	void updateMove(sf::RenderTarget & target,sf::Event &event);
	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	bool kolizja(sf::Sprite &target);

};

