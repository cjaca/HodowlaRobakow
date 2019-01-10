#pragma once
#include "DEFINITIONS.h"
#include "MainState.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>



int main()
{
	MainState game{ "Hodowla much", sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT) };
	game.runGame();
	return 0;
}
