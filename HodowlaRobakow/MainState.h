#pragma once
#include "DEFINITIONS.h"
#include "PlayState.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>




class MainState
{
public:
	MainState(sf::String title, sf::Vector2f screenRes);
	~MainState();
	void runGame();

private:
	sf::RenderWindow *window;
	sf::Vector2f ScreenSize;
	PlayState *playState;
};
