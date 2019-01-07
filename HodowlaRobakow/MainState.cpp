#include "MainState.h"



MainState::MainState(sf::String title, sf::Vector2f ScreenSize)
{
	this->ScreenSize = ScreenSize;
	window = new sf::RenderWindow(sf::VideoMode(ScreenSize.x, ScreenSize.y), title);
	window->setFramerateLimit(FPS_LIMIT);
	window->setKeyRepeatEnabled(false);
}


MainState::~MainState()
{
	delete window;
}

void MainState::runGame()
{
	Init();
	while (window->isOpen())
	{
		HandleInput();
		Update();
		Draw();
	}
}

void MainState::Init()
{
	state = Play;
	playState = new PlayState(window, &state);
	playState->Init();

}

void MainState::HandleInput()
{
	switch (state)
	{
	case MainState::Play:
		playState->HandleInput();
		break;

	default:
		break;
	}

}

void MainState::Update()
{
	switch (state)
	{
	case MainState::Play:
		playState->Update();
		break;
	default:
		break;
	}
}

void MainState::Draw()
{
	switch (state)
	{
	case MainState::Play:
		playState->Draw();
		break;
	default:
		break;
	}
	window->display();
	window->clear(sf::Color(50, 50, 50));
}


