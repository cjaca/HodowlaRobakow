#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "AssetManager.h"
#include <iostream>
class Menu
{
public:
	Menu(AssetManager &assets);
	~Menu();

	void draw(sf::RenderWindow &target);

	void showTimer(int k );

	void showTotalFly(int k);
	void showKidFly(int k);
	void showMatureFly(int k);
	void showOldFly(int k);

	void addKidFly();
	void addMatureFly();
	void addOldFly();
	void addEgg();

	void showNestAttributes(int k);
	void showNestMoney(int k);

private:
	AssetManager *manager;
	sf::Clock clock;
	sf::Time elapsed;
	//sf::Font Trebu;
	sf::Text timeElapsed, czasSymulacji, showTotalFlyText,
		showTotalFlyNumber, showKidFlyText, showKidFlyNumber,
		showMatureFlyText, showMatureFlyNumber,
		showNestFoodText, showNestFoodNumber,
		showOldFlyText, showOldFlyNumber,
		showNestMoneyText, showNestMoneyNumber;
	sf::RectangleShape mainMenuBar;
	//TODO: Add edition fields for attributes of simulation etc.
};


