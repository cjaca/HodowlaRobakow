#pragma once
#include "State.h"
#include "DEFINITIONS.h"
#include "Mature.h"
#include "Kid.h"
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
	Mature *mucha;
	sf::Vector2f ScreenSize;
	int iloscMuch = 3;
	std::vector<Mature> dorosli;
	std::vector<Kid> dzieci;
	bool isGameStarted;
	int time = 0;
	int countTime();
	void evolution();
};
