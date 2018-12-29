#include "Menu.h"
#include <string>


Menu::Menu()
{
	mainMenuBar.setSize(sf::Vector2f(200, 768));
	mainMenuBar.setOrigin(sf::Vector2f(100, 384));
	mainMenuBar.setPosition(sf::Vector2f(1124, 384));
	mainMenuBar.setFillColor(sf::Color::Black);
	if (!Trebu.loadFromFile("font/TrebuchetMS.ttf"))
	{
		std::cout << "Missing Trebuchet font\n" << std::endl;
	}
	timeElapsed.setFont(Trebu);
	timeElapsed.setCharacterSize(18);
	timeElapsed.setFillColor(sf::Color::White);
	timeElapsed.setOrigin(sf::Vector2f(50, 10));
	timeElapsed.setPosition(sf::Vector2f(1180, 750));

	czasSymulacji.setFont(Trebu);
	czasSymulacji.setCharacterSize(10);
	czasSymulacji.setFillColor(sf::Color::White);
	czasSymulacji.setOrigin(sf::Vector2f(50, 10));
	czasSymulacji.setPosition(sf::Vector2f(1180, 730));
	czasSymulacji.setString("Czas symulacji");

	showTotalFlyText.setFont(Trebu);
	showTotalFlyText.setCharacterSize(10);
	showTotalFlyText.setFillColor(sf::Color::White);
	showTotalFlyText.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyText.setPosition(sf::Vector2f(1180, 330));
	showTotalFlyText.setString("Ilosc wszystkich much");

	showTotalFlyNumber.setFont(Trebu);
	showTotalFlyNumber.setCharacterSize(10);
	showTotalFlyNumber.setFillColor(sf::Color::White);
	showTotalFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyNumber.setPosition(sf::Vector2f(1180, 350));
	
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & target)
{
	
	target.draw(mainMenuBar); //musi byc pierwsze bo zakrywa cala reszte
	target.draw(czasSymulacji);
	target.draw(timeElapsed);
	target.draw(showTotalFlyText);
	target.draw(showTotalFlyNumber);
}

void Menu::showTimer(int k)
{

	std::string s = std::to_string((k/30)%60);
	std::string m = std::to_string((k / 30) / 60);
	if (((k / 30) / 60) < 1) 
	{
		timeElapsed.setString(s + " s");
	}
	else
	{
		timeElapsed.setString(m + " m," + s + " s");
	}
	
}

void Menu::showTotalFly(int k)
{
	std::string s = std::to_string(k);
	showTotalFlyNumber.setString(s);
}

