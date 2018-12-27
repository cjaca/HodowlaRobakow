#pragma once
#include "State.h"
#include "DEFINITIONS.h"
#include "Mature.h"
#include "Kid.h"
#include "Nest.h"
#include "Egg.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>


class PlayState : public State
{
public:
	PlayState(sf::RenderWindow *window, GameStates *state);
	~PlayState();

	void Init();
	void HandleInput();
	void Update();
	void Draw();
	
private:
	int IloscMuch();
	sf::RenderWindow *window;
	GameStates *state;
	Nest *gniazdo;
	sf::Vector2f ScreenSize;
	int iloscMuch = 0;
	std::vector<Mature> dorosli;
	std::vector<Kid> dzieci;
	std::vector<Egg> jaja;
	bool isGameStarted;
	int time = 0;
	int countTime();
	void evolution();
	void cleanUp();
	void randomGen();
};

