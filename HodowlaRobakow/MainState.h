#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>

using namespace std;

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

	sf::RenderWindow *window;

	sf::Vector2f ScreenSize;

	GameStates state;

	//PlayState *playstate;

};

