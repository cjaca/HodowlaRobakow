#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "AssetManager.h"
#include <iostream>
#include <iomanip>
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
	void showKidRespAmmount(int k);
	void showNestAttributes(int k);
	void showNestMoney(int k);
	void showKidDps(int k);
	void showMatureDps(int k);
	void showOldDps(int k);
	void showCoinResp(int k);
	void showEggResp(int k);
	void buttonPause(bool k);
	sf::Sprite *getSprite(int k);
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
		showNestMoneyText, showNestMoneyNumber,
		showKidRespText, showKidRespNumber,
		showKidDpsText, showKidDpsNumber,
		showMatureDpsText, showMatureDpsNumber,
		showOldDpsText, showOldDpsNumber,
		showEggRespText, showEggRespNumber,
		showCoinRespText, showCoinRespNumber;
	sf::RectangleShape mainMenuBar;
	sf::Sprite plusSpriteKid, minusSpriteKid,
		plusSpriteMature, minusSpriteMature,
		plusSpriteOld, minusSpriteOld,
		plusSpriteNestFood, minusSpriteNestFood,
		plusSpriteNestMoney, minusSpriteNestMoney,
		plusSpriteKidResp, minusSpriteKidResp,
		plusKidDps, minusKidDps,
		plusMatureDps, minusMatureDps,
		plusOldDps, minusOldDps,
		plusEggResp, minusEggResp,
		plusCoinResp, minusCoinResp,
		btnPause;
		
	
	//TODO: Add edition fields for attributes of simulation etc.
};


