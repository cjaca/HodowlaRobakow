#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
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

class PlayState : public State
{
public:
	PlayState(sf::RenderWindow *window );
	~PlayState();
	void Init();
	void HandleInput();
	void Update();
	void Draw();
private:
	int CountTime();
	void Evolution();
	void CleanUp();
	void RandomGen();
	void Generate();
	GameStates *state;
	AssetManager *assets;
	Collision collision;
	Menu *menu;
	Nest *gniazdo;
	sf::RenderWindow *window;
	sf::Vector2f m_ScreenSize;
	std::vector<Kid> v_Kids;
	std::vector<Mature> v_Mature;
	std::vector<Old> v_Old;
	std::vector<Egg> v_Eggs;
	std::vector<Coin> v_Coins;
	int m_dt = 0;
	int m_Kid_Ammount = 5;
	int m_Egg_Time_Respawn = 90;
	int m_Coin_Time_Respawn = 150;
	float m_Kid_DPS = 0.22;
	float m_Mature_DPS = 0.22;
	float m_Old_DPS = 0.22;
	float m_Kid_Life = 100;
	float m_Mature_Life = 200;
	float m_Old_Life = 300;
	bool pause = true;
};

