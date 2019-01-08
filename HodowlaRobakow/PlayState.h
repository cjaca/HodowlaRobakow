#pragma once
#include "State.h"
#include "DEFINITIONS.h"
#include "AssetManager.h"
#include "Mature.h"
#include "Kid.h"
#include "Old.h"
#include "Nest.h"
#include "Egg.h"
#include "Menu.h"
#include "Coin.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <memory>


class PlayState : public State
{
public:

	PlayState(sf::RenderWindow *window , GameStates *state);
	~PlayState();

	void Init();
	void HandleInput();
	void Update();
	void Draw();
	
	
private:
	AssetManager *assets;
	friend class Menu;
	sf::RenderWindow *window;
	GameStates *state;
	Nest *gniazdo;
	Menu *menu;
	Collision collision;
	sf::Vector2f ScreenSize;
	int iloscMuch = 80;
	std::vector<Kid> dzieci;
	std::vector<Mature> dorosli;
	std::vector<Old> stare;
	std::vector<Egg> jaja;
	std::vector<Coin> kasa;
	bool isGameStarted;
	int countTime();
	void evolution();
	void cleanUp();
	void randomGen();
	int totalEggCount = 0;
	int kidAmmount = 5;
	float kidDPS = 0.22;
	float matureDPS = 0.22;
	float oldDPS = 0.22;
	int eggTR = 90;
	int coinTR = 150;
protected:
	int dt = 0;
};

