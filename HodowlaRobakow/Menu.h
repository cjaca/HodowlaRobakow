#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include <iostream>
class Menu
{
public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow &target);

	

	void showTimer(int k );

	void showTotalFly();
	void showKidFly();
	void showMatureFly();
	void showOldFly();

	void addKidFly();
	void addMatureFly();
	void addOldFly();
	void addEgg();

	void showNestAttributes();

private:
	sf::Clock clock;
	sf::Time elapsed;
	sf::Font Trebu;
	sf::Text timeElapsed, czasSymulacji;
	sf::RectangleShape mainMenuBar;
	//TODO: Add edition fields for attributes of simulation etc.
};


