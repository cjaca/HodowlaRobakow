#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "AssetManager.h"
#include "Kid.h"
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
	void showKidProduct(int k);
	void showMatureProduct(int k);
	void showOldProduct(int k);
	void showRespawnTime(int k);
	void showEggFood(int k);
	void showFly(Kid &fly, int k);
	void updateFly();
	sf::Sprite *getSprite(int k);
private:
	int KidProduct = 0;
	int MatureProduct = 0;
	int OldProduct = 0;
	int p_Time = 0;
	bool Show = false;
	AssetManager *manager;
	Kid *kid;
	int FlyNumber = 0;
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
		showKidLifeText, showKidLifeNumber,
		showKidProductText, showKidProductNumber,
		showMatureProductText, showMatureProductNumber,
		showOldProductText, showOldProductNumber,
		showRespawnText, showRespawnNumber,
		showEggText, showEggNumber,
		showFlyPositionText, showFlyPositionNumber,
		showFlyLifeText, showFlyLifeNumber,
		showFlySpeedNumber, showFlySizeNumber,
		showFlyBornNumber, showFlyTypeText;
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
		plusOldLife, minusOldLife,
		plusKidProduct, minusKidProduct,
		plusMatureProduct, minusMatureProduct,
		plusOldProduct, minusOldProduct,
		plusRespawn, minusRespawn,
		plusEgg, minusEgg,
		Fly, foot, head;
};


