#include "Menu.h"
#include <string>


Menu::Menu(AssetManager &assets)
{
	manager = &assets;
	
	mainMenuBar.setSize(sf::Vector2f(200, 768));
	mainMenuBar.setOrigin(sf::Vector2f(100, 384));
	mainMenuBar.setPosition(sf::Vector2f(1124, 384));
	mainMenuBar.setFillColor(sf::Color::Black);

	showNestMoneyText.setFont(manager->GetFont("trebu"));;
	showNestMoneyText.setCharacterSize(10);
	showNestMoneyText.setFillColor(sf::Color::White);
	showNestMoneyText.setOrigin(sf::Vector2f(50, 10));
	showNestMoneyText.setPosition(sf::Vector2f(1100, 250));
	showNestMoneyText.setString("Ilosc monet: ");

	showNestMoneyNumber.setFont(manager->GetFont("trebu"));
	showNestMoneyNumber.setCharacterSize(10);
	showNestMoneyNumber.setFillColor(sf::Color::Yellow);
	showNestMoneyNumber.setOrigin(sf::Vector2f(50, 10));
	showNestMoneyNumber.setPosition(sf::Vector2f(1100, 270));

	showNestFoodText.setFont(manager->GetFont("trebu"));;
	showNestFoodText.setCharacterSize(10);
	showNestFoodText.setFillColor(sf::Color::White);
	showNestFoodText.setOrigin(sf::Vector2f(50, 10));
	showNestFoodText.setPosition(sf::Vector2f(1100, 290));
	showNestFoodText.setString("Ilosc jedzenia w gniezdzie: ");

	showNestFoodNumber.setFont(manager->GetFont("trebu"));
	showNestFoodNumber.setCharacterSize(10);
	showNestFoodNumber.setFillColor(sf::Color::Yellow);
	showNestFoodNumber.setOrigin(sf::Vector2f(50, 10));
	showNestFoodNumber.setPosition(sf::Vector2f(1100, 310));

	showTotalFlyText.setFont(manager->GetFont("trebu"));
	showTotalFlyText.setCharacterSize(10);
	showTotalFlyText.setFillColor(sf::Color::White);
	showTotalFlyText.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyText.setPosition(sf::Vector2f(1100, 330));
	showTotalFlyText.setString("Ilosc wszystkich much: ");

	showTotalFlyNumber.setFont(manager->GetFont("trebu"));
	showTotalFlyNumber.setCharacterSize(10);
	showTotalFlyNumber.setFillColor(sf::Color::Yellow);
	showTotalFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyNumber.setPosition(sf::Vector2f(1100, 350));

	showKidFlyText.setFont(manager->GetFont("trebu"));
	showKidFlyText.setCharacterSize(10);
	showKidFlyText.setFillColor(sf::Color::White);
	showKidFlyText.setOrigin(sf::Vector2f(50, 10));
	showKidFlyText.setPosition(sf::Vector2f(1100, 370));
	showKidFlyText.setString("Ilosc mlodych much: ");
	
	showKidFlyNumber.setFont(manager->GetFont("trebu"));
	showKidFlyNumber.setCharacterSize(10);
	showKidFlyNumber.setFillColor(sf::Color::Yellow);
	showKidFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showKidFlyNumber.setPosition(sf::Vector2f(1100, 390));

	showMatureFlyText.setFont(manager->GetFont("trebu"));
	showMatureFlyText.setCharacterSize(10);
	showMatureFlyText.setFillColor(sf::Color::White);
	showMatureFlyText.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyText.setPosition(sf::Vector2f(1100, 410));
	showMatureFlyText.setString("Ilosc doroslych much: ");

	showMatureFlyNumber.setFont(manager->GetFont("trebu"));
	showMatureFlyNumber.setCharacterSize(10);
	showMatureFlyNumber.setFillColor(sf::Color::Yellow);
	showMatureFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyNumber.setPosition(sf::Vector2f(1100, 430));

	showOldFlyText.setFont(manager->GetFont("trebu"));
	showOldFlyText.setCharacterSize(10);
	showOldFlyText.setFillColor(sf::Color::White);
	showOldFlyText.setOrigin(sf::Vector2f(50, 10));
	showOldFlyText.setPosition(sf::Vector2f(1100, 450));
	showOldFlyText.setString("Ilosc starszych much: ");

	showOldFlyNumber.setFont(manager->GetFont("trebu"));
	showOldFlyNumber.setCharacterSize(10);
	showOldFlyNumber.setFillColor(sf::Color::Yellow);
	showOldFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showOldFlyNumber.setPosition(sf::Vector2f(1100, 470));

	czasSymulacji.setFont(manager->GetFont("trebu"));
	czasSymulacji.setCharacterSize(10);
	czasSymulacji.setFillColor(sf::Color::White);
	czasSymulacji.setOrigin(sf::Vector2f(50, 10));
	czasSymulacji.setPosition(sf::Vector2f(1100, 730));
	czasSymulacji.setString("Czas symulacji: ");

	timeElapsed.setFont(manager->GetFont("trebu"));
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
	target.draw(showOldFlyText);
	target.draw(showOldFlyNumber);
	target.draw(showNestFoodText);
	target.draw(showNestFoodNumber);
	target.draw(showNestMoneyText);
	target.draw(showNestMoneyNumber);
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

void Menu::showOldFly(int k)
{
	std::string s = std::to_string(k);
	showOldFlyNumber.setString(s);
}

void Menu::showNestAttributes(int k)
{
	std::string s = std::to_string(k);
	showNestFoodNumber.setString(s);
}

void Menu::showNestMoney(int k)
{
	std::string s = std::to_string(k);
	showNestMoneyNumber.setString(s);
}
