#pragma once
#include "DEFINITIONS.h"
#include "State.h"
#include "PlayState.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>




class MainState : public State
{
public:
	MainState(sf::String title, sf::Vector2f screenRes);
	~MainState();
	void runGame();

private:
	void Init();
	void HandleInput();
	void Update();
	void Draw();
	//sf::RenderWindow

	sf::RenderWindow *window;

	sf::Vector2f ScreenSize;

	GameStates state;
	PlayState *playState;

	//PlayState *playstate;

};
