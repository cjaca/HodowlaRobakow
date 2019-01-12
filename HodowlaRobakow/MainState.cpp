#include "MainState.h"



MainState::MainState(sf::String title, sf::Vector2f m_ScreenSize)
{
	this->m_ScreenSize = m_ScreenSize;
	window = new sf::RenderWindow(sf::VideoMode(m_ScreenSize.x, m_ScreenSize.y), title, sf::Style::Close);
	window->setFramerateLimit(FPS_LIMIT);
	window->setKeyRepeatEnabled(false);
}


MainState::~MainState()
{
	delete window;
}

void MainState::runGame()
{
	playState = new PlayState(window);
	playState->Init();
	while (window->isOpen())
	{
		playState->HandleInput();
		playState->Update();
		playState->Draw();
		window->display();
		window->clear(sf::Color(50, 50, 50));
	}
}




