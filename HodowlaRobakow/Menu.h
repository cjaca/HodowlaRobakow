#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "AssetManager.h"
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
	void showKidLife(int k);
	void showMatureLife(int k);
	void showOldLife(int k);
	sf::Sprite *getSprite(int k);
private:
	AssetManager *manager;
	sf::Clock clock;
	sf::Time elapsed;
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
		showCoinRespText, showCoinRespNumber,
		showOldLifeText, showOldLifeNumber,
		showMatureLifeText, showMatureLifeNumber,
		showKidLifeText, showKidLifeNumber;
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
		btnPause, btnGenerate,
		plusKidLife, minusKidLife,
		plusMatureLife, minusMatureLife,
		plusOldLife, minusOldLife;
};


