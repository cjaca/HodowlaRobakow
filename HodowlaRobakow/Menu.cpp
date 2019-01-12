#include "Menu.h"
#include <string>


Menu::Menu(AssetManager &assets)
{
	manager = &assets;
	
	mainMenuBar.setSize(sf::Vector2f(200, 768));
	mainMenuBar.setOrigin(sf::Vector2f(100, 384));
	mainMenuBar.setPosition(sf::Vector2f(1124, 384));
	mainMenuBar.setFillColor(sf::Color::Black);

	czasSymulacji.setFont(manager->GetFont("trebu"));
	czasSymulacji.setCharacterSize(11.5);
	czasSymulacji.setFillColor(sf::Color::White);
	czasSymulacji.setOrigin(sf::Vector2f(50, 10));
	czasSymulacji.setPosition(sf::Vector2f(1080, 10));
	czasSymulacji.setString("Czas symulacji: ");

	timeElapsed.setFont(manager->GetFont("trebu"));
	timeElapsed.setCharacterSize(18);
	timeElapsed.setFillColor(sf::Color::Green);
	timeElapsed.setOrigin(sf::Vector2f(50, 10));
	timeElapsed.setPosition(sf::Vector2f(1080, 25));
	////
	btnPause.setTexture(manager->GetTexture("start"));
	btnPause.setOrigin(1, 1);
	btnPause.setPosition(sf::Vector2f(1150, 10));

	btnGenerate.setTexture(manager->GetTexture("gen"));
	btnGenerate.setOrigin(1, 1);
	btnGenerate.setPosition(sf::Vector2f(1045, 40));
	////
	showNestMoneyText.setFont(manager->GetFont("trebu"));;
	showNestMoneyText.setCharacterSize(11.5);
	showNestMoneyText.setFillColor(sf::Color::White);
	showNestMoneyText.setOrigin(sf::Vector2f(50, 10));
	showNestMoneyText.setPosition(sf::Vector2f(1080, 80));
	showNestMoneyText.setString("Monety: ");

	plusSpriteNestMoney.setTexture(manager->GetTexture("plus"));
	plusSpriteNestMoney.setOrigin(1, 1);
	plusSpriteNestMoney.setPosition(sf::Vector2f(1190, 73));

	minusSpriteNestMoney.setTexture(manager->GetTexture("minus"));
	minusSpriteNestMoney.setOrigin(1, 1);
	minusSpriteNestMoney.setPosition(sf::Vector2f(1210, 73));

	showNestMoneyNumber.setFont(manager->GetFont("trebu"));
	showNestMoneyNumber.setCharacterSize(11.5);
	showNestMoneyNumber.setFillColor(sf::Color::Yellow);
	showNestMoneyNumber.setOrigin(sf::Vector2f(50, 10));
	showNestMoneyNumber.setPosition(sf::Vector2f(1130, 80));
////////////
	showNestFoodText.setFont(manager->GetFont("trebu"));;
	showNestFoodText.setCharacterSize(11.5);
	showNestFoodText.setFillColor(sf::Color::White);
	showNestFoodText.setOrigin(sf::Vector2f(50, 10));
	showNestFoodText.setPosition(sf::Vector2f(1080, 100));
	showNestFoodText.setString("Jedzenie w gniezdzie:");

	showNestFoodNumber.setFont(manager->GetFont("trebu"));
	showNestFoodNumber.setCharacterSize(11.5);
	showNestFoodNumber.setFillColor(sf::Color::Yellow);
	showNestFoodNumber.setOrigin(sf::Vector2f(50, 10));
	showNestFoodNumber.setPosition(sf::Vector2f(1195, 100));

	plusSpriteNestFood.setTexture(manager->GetTexture("plus"));
	plusSpriteNestFood.setOrigin(1, 1);
	plusSpriteNestFood.setPosition(sf::Vector2f(1190, 93));

	minusSpriteNestFood.setTexture(manager->GetTexture("minus"));
	minusSpriteNestFood.setOrigin(1, 1);
	minusSpriteNestFood.setPosition(sf::Vector2f(1210, 93));
//
	showTotalFlyText.setFont(manager->GetFont("trebu"));
	showTotalFlyText.setCharacterSize(11.5);
	showTotalFlyText.setFillColor(sf::Color::White);
	showTotalFlyText.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyText.setPosition(sf::Vector2f(1080, 120));
	showTotalFlyText.setString("Ilosc wszystkich much:");

	showTotalFlyNumber.setFont(manager->GetFont("trebu"));
	showTotalFlyNumber.setCharacterSize(11.5);
	showTotalFlyNumber.setFillColor(sf::Color::Yellow);
	showTotalFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showTotalFlyNumber.setPosition(sf::Vector2f(1200, 120));

	showKidFlyText.setFont(manager->GetFont("trebu"));
	showKidFlyText.setCharacterSize(11.5);
	showKidFlyText.setFillColor(sf::Color::White);
	showKidFlyText.setOrigin(sf::Vector2f(50, 10));
	showKidFlyText.setPosition(sf::Vector2f(1080, 140));
	showKidFlyText.setString("Ilosc mlodych much:");

	plusSpriteKid.setTexture(manager->GetTexture("plus"));
	plusSpriteKid.setOrigin(1, 1);
	plusSpriteKid.setPosition(sf::Vector2f(1190, 133));

	minusSpriteKid.setTexture(manager->GetTexture("minus"));
	minusSpriteKid.setOrigin(1, 1);
	minusSpriteKid.setPosition(sf::Vector2f(1210, 133));
	
	showKidFlyNumber.setFont(manager->GetFont("trebu"));
	showKidFlyNumber.setCharacterSize(11.5);
	showKidFlyNumber.setFillColor(sf::Color::Yellow);
	showKidFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showKidFlyNumber.setPosition(sf::Vector2f(1200, 140));

	showMatureFlyText.setFont(manager->GetFont("trebu"));
	showMatureFlyText.setCharacterSize(11.5);
	showMatureFlyText.setFillColor(sf::Color::White);
	showMatureFlyText.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyText.setPosition(sf::Vector2f(1080, 270));
	showMatureFlyText.setString("Ilosc doroslych much: ");

	plusSpriteMature.setTexture(manager->GetTexture("plus"));
	plusSpriteMature.setOrigin(1, 1);
	plusSpriteMature.setPosition(sf::Vector2f(1190, 265));

	minusSpriteMature.setTexture(manager->GetTexture("minus"));
	minusSpriteMature.setOrigin(1, 1);
	minusSpriteMature.setPosition(sf::Vector2f(1210, 265));

	showMatureFlyNumber.setFont(manager->GetFont("trebu"));
	showMatureFlyNumber.setCharacterSize(11.5);
	showMatureFlyNumber.setFillColor(sf::Color::Yellow);
	showMatureFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyNumber.setPosition(sf::Vector2f(1080, 290));

	showOldFlyText.setFont(manager->GetFont("trebu"));
	showOldFlyText.setCharacterSize(11.5);
	showOldFlyText.setFillColor(sf::Color::White);
	showOldFlyText.setOrigin(sf::Vector2f(50, 10));
	showOldFlyText.setPosition(sf::Vector2f(1080, 310));
	showOldFlyText.setString("Ilosc starszych much: ");

	plusSpriteOld.setTexture(manager->GetTexture("plus"));
	plusSpriteOld.setOrigin(1, 1);
	plusSpriteOld.setPosition(sf::Vector2f(1190, 305));

	minusSpriteOld.setTexture(manager->GetTexture("minus"));
	minusSpriteOld.setOrigin(1, 1);
	minusSpriteOld.setPosition(sf::Vector2f(1210, 305));

	showOldFlyNumber.setFont(manager->GetFont("trebu"));
	showOldFlyNumber.setCharacterSize(11.5);
	showOldFlyNumber.setFillColor(sf::Color::Yellow);
	showOldFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showOldFlyNumber.setPosition(sf::Vector2f(1080, 330));
	////////
	showKidRespText.setFont(manager->GetFont("trebu"));
	showKidRespText.setCharacterSize(11.5);
	showKidRespText.setFillColor(sf::Color::White);
	showKidRespText.setOrigin(sf::Vector2f(50, 10));
	showKidRespText.setPosition(sf::Vector2f(1080, 350));
	showKidRespText.setString("Ilosc much z jednego legu: ");

	plusSpriteKidResp.setTexture(manager->GetTexture("plus"));
	plusSpriteKidResp.setOrigin(1, 1);
	plusSpriteKidResp.setPosition(sf::Vector2f(1190, 345));

	minusSpriteKidResp.setTexture(manager->GetTexture("minus"));
	minusSpriteKidResp.setOrigin(1, 1);
	minusSpriteKidResp.setPosition(sf::Vector2f(1210, 345));

	showKidRespNumber.setFont(manager->GetFont("trebu"));
	showKidRespNumber.setCharacterSize(11.5);
	showKidRespNumber.setFillColor(sf::Color::Yellow);
	showKidRespNumber.setOrigin(sf::Vector2f(50, 10));
	showKidRespNumber.setPosition(sf::Vector2f(1080, 370));
	//
	showKidDpsText.setFont(manager->GetFont("trebu"));
	showKidDpsText.setCharacterSize(11.5);
	showKidDpsText.setFillColor(sf::Color::White);
	showKidDpsText.setOrigin(sf::Vector2f(50, 10));
	showKidDpsText.setPosition(sf::Vector2f(1080, 390));
	showKidDpsText.setString("Nieodpornosc na glod mlodej: ");

	plusKidDps.setTexture(manager->GetTexture("plus"));
	plusKidDps.setOrigin(1, 1);
	plusKidDps.setPosition(sf::Vector2f(1190, 385));

	minusKidDps.setTexture(manager->GetTexture("minus"));
	minusKidDps.setOrigin(1, 1);
	minusKidDps.setPosition(sf::Vector2f(1210, 385));

	showKidDpsNumber.setFont(manager->GetFont("trebu"));
	showKidDpsNumber.setCharacterSize(11.5);
	showKidDpsNumber.setFillColor(sf::Color::Yellow);
	showKidDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showKidDpsNumber.setPosition(sf::Vector2f(1080, 410));
	////
	showMatureDpsText.setFont(manager->GetFont("trebu"));
	showMatureDpsText.setCharacterSize(11.5);
	showMatureDpsText.setFillColor(sf::Color::White);
	showMatureDpsText.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsText.setPosition(sf::Vector2f(1080, 430));
	showMatureDpsText.setString("Nieodpornosc na glod doroslej:");

	plusMatureDps.setTexture(manager->GetTexture("plus"));
	plusMatureDps.setOrigin(1, 1);
	plusMatureDps.setPosition(sf::Vector2f(1190, 425));

	minusMatureDps.setTexture(manager->GetTexture("minus"));
	minusMatureDps.setOrigin(1, 1);
	minusMatureDps.setPosition(sf::Vector2f(1210, 425));

	showMatureDpsNumber.setFont(manager->GetFont("trebu"));
	showMatureDpsNumber.setCharacterSize(11.5);
	showMatureDpsNumber.setFillColor(sf::Color::Yellow);
	showMatureDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsNumber.setPosition(sf::Vector2f(1080, 450));
	////
	showOldDpsText.setFont(manager->GetFont("trebu"));
	showOldDpsText.setCharacterSize(11.5);
	showOldDpsText.setFillColor(sf::Color::White);
	showOldDpsText.setOrigin(sf::Vector2f(50, 10));
	showOldDpsText.setPosition(sf::Vector2f(1080, 470));
	showOldDpsText.setString("Nieodpornosc na glod starszej:");

	plusOldDps.setTexture(manager->GetTexture("plus"));
	plusOldDps.setOrigin(1, 1);
	plusOldDps.setPosition(sf::Vector2f(1190, 465));

	minusOldDps.setTexture(manager->GetTexture("minus"));
	minusOldDps.setOrigin(1, 1);
	minusOldDps.setPosition(sf::Vector2f(1210, 465));

	showOldDpsNumber.setFont(manager->GetFont("trebu"));
	showOldDpsNumber.setCharacterSize(11.5);
	showOldDpsNumber.setFillColor(sf::Color::Yellow);
	showOldDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showOldDpsNumber.setPosition(sf::Vector2f(1080, 490));
	////
	showEggRespText.setFont(manager->GetFont("trebu"));
	showEggRespText.setCharacterSize(11.5);
	showEggRespText.setFillColor(sf::Color::White);
	showEggRespText.setOrigin(sf::Vector2f(50, 10));
	showEggRespText.setPosition(sf::Vector2f(1080, 510));
	showEggRespText.setString("Nowe jajka generuja sie co:");

	plusEggResp.setTexture(manager->GetTexture("plus"));
	plusEggResp.setOrigin(1, 1);
	plusEggResp.setPosition(sf::Vector2f(1190, 505));

	minusEggResp.setTexture(manager->GetTexture("minus"));
	minusEggResp.setOrigin(1, 1);
	minusEggResp.setPosition(sf::Vector2f(1210, 505));

	showEggRespNumber.setFont(manager->GetFont("trebu"));
	showEggRespNumber.setCharacterSize(11.5);
	showEggRespNumber.setFillColor(sf::Color::Yellow);
	showEggRespNumber.setOrigin(sf::Vector2f(50, 10));
	showEggRespNumber.setPosition(sf::Vector2f(1080, 530));
	////
	showCoinRespText.setFont(manager->GetFont("trebu"));
	showCoinRespText.setCharacterSize(11.5);
	showCoinRespText.setFillColor(sf::Color::White);
	showCoinRespText.setOrigin(sf::Vector2f(50, 10));
	showCoinRespText.setPosition(sf::Vector2f(1080, 550));
	showCoinRespText.setString("Nowe monety generuja sie co:");

	plusCoinResp.setTexture(manager->GetTexture("plus"));
	plusCoinResp.setOrigin(1, 1);
	plusCoinResp.setPosition(sf::Vector2f(1190, 545));

	minusCoinResp.setTexture(manager->GetTexture("minus"));
	minusCoinResp.setOrigin(1, 1);
	minusCoinResp.setPosition(sf::Vector2f(1210, 545));

	showCoinRespNumber.setFont(manager->GetFont("trebu"));
	showCoinRespNumber.setCharacterSize(11.5);
	showCoinRespNumber.setFillColor(sf::Color::Yellow);
	showCoinRespNumber.setOrigin(sf::Vector2f(50, 10));
	showCoinRespNumber.setPosition(sf::Vector2f(1080, 570));
	////


	showKidLifeText.setFont(manager->GetFont("trebu"));
	showKidLifeText.setCharacterSize(11.5);
	showKidLifeText.setFillColor(sf::Color::White);
	showKidLifeText.setOrigin(sf::Vector2f(50, 10));
	showKidLifeText.setPosition(sf::Vector2f(1080, 590));
	showKidLifeText.setString("Ilosc zycia mlodej muchy:");

	plusKidLife.setTexture(manager->GetTexture("plus"));
	plusKidLife.setOrigin(1, 1);
	plusKidLife.setPosition(sf::Vector2f(1190, 585));

	minusKidLife.setTexture(manager->GetTexture("minus"));
	minusKidLife.setOrigin(1, 1);
	minusKidLife.setPosition(sf::Vector2f(1210, 585));

	showKidLifeNumber.setFont(manager->GetFont("trebu"));
	showKidLifeNumber.setCharacterSize(11.5);
	showKidLifeNumber.setFillColor(sf::Color::Yellow);
	showKidLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showKidLifeNumber.setPosition(sf::Vector2f(1080, 610));
	////
	showMatureLifeText.setFont(manager->GetFont("trebu"));
	showMatureLifeText.setCharacterSize(11.5);
	showMatureLifeText.setFillColor(sf::Color::White);
	showMatureLifeText.setOrigin(sf::Vector2f(50, 10));
	showMatureLifeText.setPosition(sf::Vector2f(1080, 630));
	showMatureLifeText.setString("Ilosc zycia doroslej muchy:");

	plusMatureLife.setTexture(manager->GetTexture("plus"));
	plusMatureLife.setOrigin(1, 1);
	plusMatureLife.setPosition(sf::Vector2f(1190, 625));

	minusMatureLife.setTexture(manager->GetTexture("minus"));
	minusMatureLife.setOrigin(1, 1);
	minusMatureLife.setPosition(sf::Vector2f(1210, 625));

	showMatureLifeNumber.setFont(manager->GetFont("trebu"));
	showMatureLifeNumber.setCharacterSize(11.5);
	showMatureLifeNumber.setFillColor(sf::Color::Yellow);
	showMatureLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureLifeNumber.setPosition(sf::Vector2f(1080, 650));
	////
	showOldLifeText.setFont(manager->GetFont("trebu"));
	showOldLifeText.setCharacterSize(11.5);
	showOldLifeText.setFillColor(sf::Color::White);
	showOldLifeText.setOrigin(sf::Vector2f(50, 10));
	showOldLifeText.setPosition(sf::Vector2f(1080, 670));
	showOldLifeText.setString("Ilosc zycia starszej muchy:");

	plusOldLife.setTexture(manager->GetTexture("plus"));
	plusOldLife.setOrigin(1, 1);
	plusOldLife.setPosition(sf::Vector2f(1190, 665));

	minusOldLife.setTexture(manager->GetTexture("minus"));
	minusOldLife.setOrigin(1, 1);
	minusOldLife.setPosition(sf::Vector2f(1210, 665));

	showOldLifeNumber.setFont(manager->GetFont("trebu"));
	showOldLifeNumber.setCharacterSize(11.5);
	showOldLifeNumber.setFillColor(sf::Color::Yellow);
	showOldLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showOldLifeNumber.setPosition(sf::Vector2f(1080, 690));

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
	target.draw(btnPause);
	target.draw(showOldLifeNumber);
	target.draw(showMatureLifeNumber);
	target.draw(showKidLifeNumber);
	target.draw(showOldLifeText);
	target.draw(showMatureLifeText);
	target.draw(showKidLifeText);
	target.draw(plusKidLife);
	target.draw(minusKidLife);
	target.draw(plusMatureLife);
	target.draw(minusMatureLife);
	target.draw(plusOldLife);
	target.draw(minusOldLife);
	target.draw(btnGenerate);
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
void Menu::buttonPause(bool k)
{
	if (k == true)
	{
		btnPause.setTexture(manager->GetTexture("start"));
	}
	if (k == false)
	{
		btnPause.setTexture(manager->GetTexture("pause"));
	}
}
void Menu::showKidLife(int k)
{
	std::string s = std::to_string(k);
	showKidLifeNumber.setString(s);
}
void Menu::showMatureLife(int k)
{
	std::string s = std::to_string(k);
	showMatureLifeNumber.setString(s);
}
void Menu::showOldLife(int k)
{
	std::string s = std::to_string(k);
	showOldLifeNumber.setString(s);
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
	if (k == 23)
	{
		return &this->btnPause;
	}
	if (k == 24)
	{
		return &this->plusKidLife;
	}
	if (k == 25)
	{
		return &this->minusKidLife;
	}
	if (k == 26)
	{
		return &this->plusMatureLife;
	}
	if (k == 27)
	{
		return &this->minusMatureLife;
	}
	if (k == 28)
	{
		return &this->plusOldLife;
	}
	if (k == 29)
	{
		return &this->minusOldLife;
	}
	if (k == 30)
	{
		return &this->btnGenerate;
	}
}
