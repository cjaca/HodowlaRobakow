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

	showNestFoodText.setFont(Trebu);
	showNestFoodText.setCharacterSize(10);
	showNestFoodText.setFillColor(sf::Color::White);
	showNestFoodText.setOrigin(sf::Vector2f(50, 10));
	showNestFoodText.setPosition(sf::Vector2f(1100, 290));
	showNestFoodText.setString("Ilosc jedzenia w gniezdzie: ");

	showNestFoodNumber.setFont(Trebu);
	showNestFoodNumber.setCharacterSize(10);
	showNestFoodNumber.setFillColor(sf::Color::Yellow);
	showNestFoodNumber.setOrigin(sf::Vector2f(50, 10));
	showNestFoodNumber.setPosition(sf::Vector2f(1100, 310));

	showTotalFlyText.setFont(Trebu);
	showTotalFlyText.setCharacterSize(10);
	showTotalFlyText.setFillColor(sf::Color::White);
	showTotalFlyText.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyText.setPosition(sf::Vector2f(1100, 330));
	showTotalFlyText.setString("Ilosc wszystkich much: ");

	showTotalFlyNumber.setFont(Trebu);
	showTotalFlyNumber.setCharacterSize(10);
	showTotalFlyNumber.setFillColor(sf::Color::Yellow);
	showTotalFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyNumber.setPosition(sf::Vector2f(1100, 350));

	showKidFlyText.setFont(Trebu);
	showKidFlyText.setCharacterSize(10);
	showKidFlyText.setFillColor(sf::Color::White);
	showKidFlyText.setOrigin(sf::Vector2f(50, 10));
	showKidFlyText.setPosition(sf::Vector2f(1100, 370));
	showKidFlyText.setString("Ilosc mlodych much: ");
	
	showKidFlyNumber.setFont(Trebu);
	showKidFlyNumber.setCharacterSize(10);
	showKidFlyNumber.setFillColor(sf::Color::Yellow);
	showKidFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showKidFlyNumber.setPosition(sf::Vector2f(1100, 390));

	showMatureFlyText.setFont(Trebu);
	showMatureFlyText.setCharacterSize(10);
	showMatureFlyText.setFillColor(sf::Color::White);
	showMatureFlyText.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyText.setPosition(sf::Vector2f(1100, 410));
	showMatureFlyText.setString("Ilosc doroslych much: ");

	showMatureFlyNumber.setFont(Trebu);
	showMatureFlyNumber.setCharacterSize(10);
	showMatureFlyNumber.setFillColor(sf::Color::Yellow);
	showMatureFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyNumber.setPosition(sf::Vector2f(1100, 430));

	czasSymulacji.setFont(Trebu);
	czasSymulacji.setCharacterSize(10);
	czasSymulacji.setFillColor(sf::Color::White);
	czasSymulacji.setOrigin(sf::Vector2f(50, 10));
	czasSymulacji.setPosition(sf::Vector2f(1100, 730));
	czasSymulacji.setString("Czas symulacji: ");

	timeElapsed.setFont(Trebu);
	timeElapsed.setCharacterSize(18);
	timeElapsed.setFillColor(sf::Color::Green);
	timeElapsed.setOrigin(sf::Vector2f(50, 10));
	timeElapsed.setPosition(sf::Vector2f(1150, 750));
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
	target.draw(showKidFlyText);
	target.draw(showKidFlyNumber);
	target.draw(showMatureFlyText);
	target.draw(showMatureFlyNumber);
	target.draw(showNestFoodText);
	target.draw(showNestFoodNumber);
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

void Menu::showKidFly(int k)
{
	std::string s = std::to_string(k);
	showKidFlyNumber.setString(s);
}

void Menu::showMatureFly(int k)
{
	std::string s = std::to_string(k);
	showMatureFlyNumber.setString(s);
}

void Menu::showNestAttributes(int k)
{
	std::string s = std::to_string(k);
	showNestFoodNumber.setString(s);
}
