#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Mrowka.h"


int main()
{
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "Hodowla Robakow", sf::Style::Default);
	Window.setFramerateLimit(60);
	/*Mrowka *mrowka;
	mrowka = new Mrowka(sf::Vector2f(100.f, 100.f));

	Mrowka *mucha;
	mucha = new Mrowka(sf::Vector2f(500.f, 500.f));

	Mrowka *krowa;
	krowa = new Mrowka(sf::Vector2f(300.f, 300.f));*/

	int iloscMuch = 10;
	std::vector<Mrowka> mrowki;
	//mrowki.reserve(mrowka);

	for (int i = 0; i < iloscMuch; i++) {
		//Mrowka mrowka(sf::Vector2f(rand() % 800, rand() % 600));
		Mrowka *mrowka;
		mrowka = new Mrowka(sf::Vector2f(rand() % 800, rand() % 600));
		mrowki.push_back(*mrowka);
	}

	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				Window.close();
		}

		//switch (event.type)
		//{
		//case sf::Event::Closed:
		//	Window.close();

		//	case sf::Event::KeyPressed:
		//		if (event.key.code == sf::Keyboard::Escape) {
		//			mrowki.push_back(Mrowka(sf::Vector2f (rand()%800, rand()%600)));

		//		}
		//}
		
		for (int i = 0; i < iloscMuch; i++) {
			mrowki[i].updateMove(Window, event);

		}
		for (int i = 0; i < iloscMuch; i++) {
			mrowki[i].draw(Window);

		}
		//mrowka->updateMove(Window, event);
		//mucha->updateMove(Window, event);
		//krowa->updateMove(Window, event);
		//
		/*for (int i = 0; i < 3; i++) {
			Mrowka mrowka(sf::Vector2f(rand() % 800, rand() % 600));
			mrowki.push_back(mrowka);
		}*/

		//mucha->kolizja(*krowa->getSprite());
		//mucha->kolizja(*mrowka->getSprite());
		//mrowka->kolizja(*krowa->getSprite());
		//mrowka->kolizja(*mucha->getSprite());
		//
		//krowa->draw(Window);
		//mrowka->draw(Window);
		//mucha->draw(Window);
		Window.display();

	}
}