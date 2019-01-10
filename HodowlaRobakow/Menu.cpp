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
	showNestMoneyText.setPosition(sf::Vector2f(1100, 110));
	showNestMoneyText.setString("Ilosc monet: ");

	plusSpriteNestMoney.setTexture(manager->GetTexture("plus"));
	plusSpriteNestMoney.setOrigin(1, 1);
	plusSpriteNestMoney.setPosition(sf::Vector2f(1190, 105));

	minusSpriteNestMoney.setTexture(manager->GetTexture("minus"));
	minusSpriteNestMoney.setOrigin(1, 1);
	minusSpriteNestMoney.setPosition(sf::Vector2f(1210, 105));

	showNestMoneyNumber.setFont(manager->GetFont("trebu"));
	showNestMoneyNumber.setCharacterSize(10);
	showNestMoneyNumber.setFillColor(sf::Color::Yellow);
	showNestMoneyNumber.setOrigin(sf::Vector2f(50, 10));
	showNestMoneyNumber.setPosition(sf::Vector2f(1100, 130));

	showNestFoodText.setFont(manager->GetFont("trebu"));;
	showNestFoodText.setCharacterSize(10);
	showNestFoodText.setFillColor(sf::Color::White);
	showNestFoodText.setOrigin(sf::Vector2f(50, 10));
	showNestFoodText.setPosition(sf::Vector2f(1100, 150));
	showNestFoodText.setString("Ilosc jedzenia w gniezdzie: ");

	plusSpriteNestFood.setTexture(manager->GetTexture("plus"));
	plusSpriteNestFood.setOrigin(1, 1);
	plusSpriteNestFood.setPosition(sf::Vector2f(1190, 145));

	minusSpriteNestFood.setTexture(manager->GetTexture("minus"));
	minusSpriteNestFood.setOrigin(1, 1);
	minusSpriteNestFood.setPosition(sf::Vector2f(1210, 145));

	showNestFoodNumber.setFont(manager->GetFont("trebu"));
	showNestFoodNumber.setCharacterSize(10);
	showNestFoodNumber.setFillColor(sf::Color::Yellow);
	showNestFoodNumber.setOrigin(sf::Vector2f(50, 10));
	showNestFoodNumber.setPosition(sf::Vector2f(1100, 170));

	showTotalFlyText.setFont(manager->GetFont("trebu"));
	showTotalFlyText.setCharacterSize(10);
	showTotalFlyText.setFillColor(sf::Color::White);
	showTotalFlyText.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyText.setPosition(sf::Vector2f(1100, 190));
	showTotalFlyText.setString("Ilosc wszystkich much: ");

	showTotalFlyNumber.setFont(manager->GetFont("trebu"));
	showTotalFlyNumber.setCharacterSize(10);
	showTotalFlyNumber.setFillColor(sf::Color::Yellow);
	showTotalFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyNumber.setPosition(sf::Vector2f(1100, 210));

	showKidFlyText.setFont(manager->GetFont("trebu"));
	showKidFlyText.setCharacterSize(10);
	showKidFlyText.setFillColor(sf::Color::White);
	showKidFlyText.setOrigin(sf::Vector2f(50, 10));
	showKidFlyText.setPosition(sf::Vector2f(1100, 230));
	showKidFlyText.setString("Ilosc mlodych much: ");

	plusSpriteKid.setTexture(manager->GetTexture("plus"));
	plusSpriteKid.setOrigin(1, 1);
	plusSpriteKid.setPosition(sf::Vector2f(1190, 225));

	minusSpriteKid.setTexture(manager->GetTexture("minus"));
	minusSpriteKid.setOrigin(1, 1);
	minusSpriteKid.setPosition(sf::Vector2f(1210, 225));
	
	showKidFlyNumber.setFont(manager->GetFont("trebu"));
	showKidFlyNumber.setCharacterSize(10);
	showKidFlyNumber.setFillColor(sf::Color::Yellow);
	showKidFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showKidFlyNumber.setPosition(sf::Vector2f(1100, 250));

	showMatureFlyText.setFont(manager->GetFont("trebu"));
	showMatureFlyText.setCharacterSize(10);
	showMatureFlyText.setFillColor(sf::Color::White);
	showMatureFlyText.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyText.setPosition(sf::Vector2f(1100, 270));
	showMatureFlyText.setString("Ilosc doroslych much: ");

	plusSpriteMature.setTexture(manager->GetTexture("plus"));
	plusSpriteMature.setOrigin(1, 1);
	plusSpriteMature.setPosition(sf::Vector2f(1190, 265));

	minusSpriteMature.setTexture(manager->GetTexture("minus"));
	minusSpriteMature.setOrigin(1, 1);
	minusSpriteMature.setPosition(sf::Vector2f(1210, 265));

	showMatureFlyNumber.setFont(manager->GetFont("trebu"));
	showMatureFlyNumber.setCharacterSize(10);
	showMatureFlyNumber.setFillColor(sf::Color::Yellow);
	showMatureFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyNumber.setPosition(sf::Vector2f(1100, 290));

	showOldFlyText.setFont(manager->GetFont("trebu"));
	showOldFlyText.setCharacterSize(10);
	showOldFlyText.setFillColor(sf::Color::White);
	showOldFlyText.setOrigin(sf::Vector2f(50, 10));
	showOldFlyText.setPosition(sf::Vector2f(1100, 310));
	showOldFlyText.setString("Ilosc starszych much: ");

	plusSpriteOld.setTexture(manager->GetTexture("plus"));
	plusSpriteOld.setOrigin(1, 1);
	plusSpriteOld.setPosition(sf::Vector2f(1190, 305));

	minusSpriteOld.setTexture(manager->GetTexture("minus"));
	minusSpriteOld.setOrigin(1, 1);
	minusSpriteOld.setPosition(sf::Vector2f(1210, 305));

	showOldFlyNumber.setFont(manager->GetFont("trebu"));
	showOldFlyNumber.setCharacterSize(10);
	showOldFlyNumber.setFillColor(sf::Color::Yellow);
	showOldFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showOldFlyNumber.setPosition(sf::Vector2f(1100, 330));
	////////
	showKidRespText.setFont(manager->GetFont("trebu"));
	showKidRespText.setCharacterSize(10);
	showKidRespText.setFillColor(sf::Color::White);
	showKidRespText.setOrigin(sf::Vector2f(50, 10));
	showKidRespText.setPosition(sf::Vector2f(1100, 350));
	showKidRespText.setString("Ilosc much z jednego legu: ");

	plusSpriteKidResp.setTexture(manager->GetTexture("plus"));
	plusSpriteKidResp.setOrigin(1, 1);
	plusSpriteKidResp.setPosition(sf::Vector2f(1190, 345));

	minusSpriteKidResp.setTexture(manager->GetTexture("minus"));
	minusSpriteKidResp.setOrigin(1, 1);
	minusSpriteKidResp.setPosition(sf::Vector2f(1210, 345));

	showKidRespNumber.setFont(manager->GetFont("trebu"));
	showKidRespNumber.setCharacterSize(10);
	showKidRespNumber.setFillColor(sf::Color::Yellow);
	showKidRespNumber.setOrigin(sf::Vector2f(50, 10));
	showKidRespNumber.setPosition(sf::Vector2f(1100, 370));
	//
	showKidDpsText.setFont(manager->GetFont("trebu"));
	showKidDpsText.setCharacterSize(10);
	showKidDpsText.setFillColor(sf::Color::White);
	showKidDpsText.setOrigin(sf::Vector2f(50, 10));
	showKidDpsText.setPosition(sf::Vector2f(1100, 390));
	showKidDpsText.setString("Nieodpornosc na glod mlodej: ");

	plusKidDps.setTexture(manager->GetTexture("plus"));
	plusKidDps.setOrigin(1, 1);
	plusKidDps.setPosition(sf::Vector2f(1190, 385));

	minusKidDps.setTexture(manager->GetTexture("minus"));
	minusKidDps.setOrigin(1, 1);
	minusKidDps.setPosition(sf::Vector2f(1210, 385));

	showKidDpsNumber.setFont(manager->GetFont("trebu"));
	showKidDpsNumber.setCharacterSize(10);
	showKidDpsNumber.setFillColor(sf::Color::Yellow);
	showKidDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showKidDpsNumber.setPosition(sf::Vector2f(1100, 410));
	////
	showMatureDpsText.setFont(manager->GetFont("trebu"));
	showMatureDpsText.setCharacterSize(10);
	showMatureDpsText.setFillColor(sf::Color::White);
	showMatureDpsText.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsText.setPosition(sf::Vector2f(1100, 430));
	showMatureDpsText.setString("Nieodpornosc na glod doroslej:");

	plusMatureDps.setTexture(manager->GetTexture("plus"));
	plusMatureDps.setOrigin(1, 1);
	plusMatureDps.setPosition(sf::Vector2f(1190, 425));

	minusMatureDps.setTexture(manager->GetTexture("minus"));
	minusMatureDps.setOrigin(1, 1);
	minusMatureDps.setPosition(sf::Vector2f(1210, 425));

	showMatureDpsNumber.setFont(manager->GetFont("trebu"));
	showMatureDpsNumber.setCharacterSize(10);
	showMatureDpsNumber.setFillColor(sf::Color::Yellow);
	showMatureDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsNumber.setPosition(sf::Vector2f(1100, 450));
	////
	showOldDpsText.setFont(manager->GetFont("trebu"));
	showOldDpsText.setCharacterSize(10);
	showOldDpsText.setFillColor(sf::Color::White);
	showOldDpsText.setOrigin(sf::Vector2f(50, 10));
	showOldDpsText.setPosition(sf::Vector2f(1100, 470));
	showOldDpsText.setString("Nieodpornosc na glod starszej:");

	plusOldDps.setTexture(manager->GetTexture("plus"));
	plusOldDps.setOrigin(1, 1);
	plusOldDps.setPosition(sf::Vector2f(1190, 465));

	minusOldDps.setTexture(manager->GetTexture("minus"));
	minusOldDps.setOrigin(1, 1);
	minusOldDps.setPosition(sf::Vector2f(1210, 465));

	showOldDpsNumber.setFont(manager->GetFont("trebu"));
	showOldDpsNumber.setCharacterSize(10);
	showOldDpsNumber.setFillColor(sf::Color::Yellow);
	showOldDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showOldDpsNumber.setPosition(sf::Vector2f(1100, 490));
	////
	showEggRespText.setFont(manager->GetFont("trebu"));
	showEggRespText.setCharacterSize(10);
	showEggRespText.setFillColor(sf::Color::White);
	showEggRespText.setOrigin(sf::Vector2f(50, 10));
	showEggRespText.setPosition(sf::Vector2f(1100, 510));
	showEggRespText.setString("Nowe jajka generuja sie co:");

	plusEggResp.setTexture(manager->GetTexture("plus"));
	plusEggResp.setOrigin(1, 1);
	plusEggResp.setPosition(sf::Vector2f(1190, 505));

	minusEggResp.setTexture(manager->GetTexture("minus"));
	minusEggResp.setOrigin(1, 1);
	minusEggResp.setPosition(sf::Vector2f(1210, 505));

	showEggRespNumber.setFont(manager->GetFont("trebu"));
	showEggRespNumber.setCharacterSize(10);
	showEggRespNumber.setFillColor(sf::Color::Yellow);
	showEggRespNumber.setOrigin(sf::Vector2f(50, 10));
	showEggRespNumber.setPosition(sf::Vector2f(1100, 530));
	////
	showCoinRespText.setFont(manager->GetFont("trebu"));
	showCoinRespText.setCharacterSize(10);
	showCoinRespText.setFillColor(sf::Color::White);
	showCoinRespText.setOrigin(sf::Vector2f(50, 10));
	showCoinRespText.setPosition(sf::Vector2f(1100, 550));
	showCoinRespText.setString("Nowe monety generuja sie co:");

	plusCoinResp.setTexture(manager->GetTexture("plus"));
	plusCoinResp.setOrigin(1, 1);
	plusCoinResp.setPosition(sf::Vector2f(1190, 545));

	minusCoinResp.setTexture(manager->GetTexture("minus"));
	minusCoinResp.setOrigin(1, 1);
	minusCoinResp.setPosition(sf::Vector2f(1210, 545));

	showCoinRespNumber.setFont(manager->GetFont("trebu"));
	showCoinRespNumber.setCharacterSize(10);
	showCoinRespNumber.setFillColor(sf::Color::Yellow);
	showCoinRespNumber.setOrigin(sf::Vector2f(50, 10));
	showCoinRespNumber.setPosition(sf::Vector2f(1100, 570));
	////
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
	target.draw(plusSpriteKid);
	target.draw(minusSpriteKid);
	target.draw(plusSpriteMature);
	target.draw(minusSpriteMature);
	target.draw(plusSpriteOld);
	target.draw(minusSpriteOld);
	target.draw(plusSpriteNestFood);
	target.draw(minusSpriteNestFood);
	target.draw(plusSpriteNestMoney);
	target.draw(minusSpriteNestMoney);
	target.draw(plusSpriteKidResp);
	target.draw(minusSpriteKidResp);
	target.draw(showKidRespText);
	target.draw(showKidRespNumber);
	target.draw(showKidDpsText);
	target.draw(showKidDpsNumber);
	target.draw(plusKidDps);
	target.draw(minusKidDps);
	target.draw(showMatureDpsText);
	target.draw(showMatureDpsNumber);
	target.draw(plusMatureDps);
	target.draw(minusMatureDps);
	target.draw(showOldDpsText);
	target.draw(showOldDpsNumber);
	target.draw(plusOldDps);
	target.draw(minusOldDps);
	target.draw(showEggRespNumber);
	target.draw(showEggRespText);
	target.draw(plusEggResp);
	target.draw(minusEggResp);
	target.draw(showCoinRespNumber);
	target.draw(showCoinRespText);
	target.draw(plusCoinResp);
	target.draw(minusCoinResp);
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

void Menu::showKidRespAmmount(int k)
{
	std::string s = std::to_string(k);
	showKidRespNumber.setString(s);
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

void Menu::showKidDps(int k)
{
	std::string s = std::to_string(k);
	showKidDpsNumber.setString(s);
}

void Menu::showMatureDps(int k)
{
	std::string s = std::to_string(k);
	showMatureDpsNumber.setString(s);
}

void Menu::showOldDps(int k)
{
	std::string s = std::to_string(k);
	showOldDpsNumber.setString(s);
}

void Menu::showCoinResp(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showCoinRespNumber.setString(s+" s");
}

void Menu::showEggResp(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showEggRespNumber.setString(s+" s");
}

sf::Sprite * Menu::getSprite(int k)
{
	if (k == 1)
	{
		return &this->plusSpriteKid;
	}
	if (k == 2)
	{
		return &this->minusSpriteKid;
	}
	if (k == 3)
	{
		return &this->plusSpriteMature;
	}
	if (k == 4)
	{
		return &this->minusSpriteMature;
	}
	if (k == 5)
	{
		return &this->plusSpriteOld;
	}
	if (k == 6)
	{
		return &this->minusSpriteOld;
	}
	if (k == 7)
	{
		return &this->plusSpriteNestFood;
	}
	if (k == 8)
	{
		return &this->minusSpriteNestFood;
	}
	if (k == 9)
	{
		return &this->plusSpriteNestMoney;
	}
	if (k == 10)
	{
		return &this->minusSpriteNestMoney;
	}
	if (k == 11)
	{
		return &this->plusSpriteKidResp;
	}
	if (k == 12)
	{
		return &this->minusSpriteKidResp;
	}
	if (k == 13)
	{
		return &this->plusKidDps;
	}
	if (k == 14)
	{
		return &this->minusKidDps;
	}
	if (k == 15)
	{
		return &this->plusMatureDps;
	}
	if (k == 16)
	{
		return &this->minusMatureDps;
	}
	if (k == 17)
	{
		return &this->plusOldDps;
	}
	if (k == 18)
	{
		return &this->minusOldDps;
	}
	if (k == 19)
	{
		return &this->plusCoinResp;
	}
	if (k == 20)
	{
		return &this->minusCoinResp;
	}
	if (k == 21)
	{
		return &this->plusEggResp;
	}
	if (k == 22)
	{
		return &this->minusEggResp;
	}
}
