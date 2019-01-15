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
	czasSymulacji.setPosition(sf::Vector2f(1080, 570));
	czasSymulacji.setString("Czas symulacji: ");

	timeElapsed.setFont(manager->GetFont("trebu"));
	timeElapsed.setCharacterSize(18);
	timeElapsed.setFillColor(sf::Color::Green);
	timeElapsed.setOrigin(sf::Vector2f(50, 10));
	timeElapsed.setPosition(sf::Vector2f(1080, 585));
	////
	btnPause.setTexture(manager->GetTexture("start"));
	btnPause.setOrigin(1, 1);
	btnPause.setPosition(sf::Vector2f(1090, 530));

	btnGenerate.setTexture(manager->GetTexture("gen"));
	btnGenerate.setOrigin(1, 1);
	btnGenerate.setPosition(sf::Vector2f(1045, 490));

	foot.setTexture(manager->GetTexture("foot"));
	foot.setOrigin(1, 1);
	foot.setPosition(sf::Vector2f(1030, 750));
	head.setTexture(manager->GetTexture("head"));
	head.setOrigin(1, 1);
	head.setPosition(sf::Vector2f(1030, 10));
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
	////
	showMatureFlyText.setFont(manager->GetFont("trebu"));
	showMatureFlyText.setCharacterSize(11.5);
	showMatureFlyText.setFillColor(sf::Color::White);
	showMatureFlyText.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyText.setPosition(sf::Vector2f(1080, 160));
	showMatureFlyText.setString("Ilosc doroslych much:");

	plusSpriteMature.setTexture(manager->GetTexture("plus"));
	plusSpriteMature.setOrigin(1, 1);
	plusSpriteMature.setPosition(sf::Vector2f(1190, 153));

	minusSpriteMature.setTexture(manager->GetTexture("minus"));
	minusSpriteMature.setOrigin(1, 1);
	minusSpriteMature.setPosition(sf::Vector2f(1210, 153));

	showMatureFlyNumber.setFont(manager->GetFont("trebu"));
	showMatureFlyNumber.setCharacterSize(11.5);
	showMatureFlyNumber.setFillColor(sf::Color::Yellow);
	showMatureFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureFlyNumber.setPosition(sf::Vector2f(1200, 160));
	////
	showOldFlyText.setFont(manager->GetFont("trebu"));
	showOldFlyText.setCharacterSize(11.5);
	showOldFlyText.setFillColor(sf::Color::White);
	showOldFlyText.setOrigin(sf::Vector2f(50, 10));
	showOldFlyText.setPosition(sf::Vector2f(1080, 180));
	showOldFlyText.setString("Ilosc starszych much:");

	plusSpriteOld.setTexture(manager->GetTexture("plus"));
	plusSpriteOld.setOrigin(1, 1);
	plusSpriteOld.setPosition(sf::Vector2f(1190, 173));

	minusSpriteOld.setTexture(manager->GetTexture("minus"));
	minusSpriteOld.setOrigin(1, 1);
	minusSpriteOld.setPosition(sf::Vector2f(1210, 173));

	showOldFlyNumber.setFont(manager->GetFont("trebu"));
	showOldFlyNumber.setCharacterSize(11.5);
	showOldFlyNumber.setFillColor(sf::Color::Yellow);
	showOldFlyNumber.setOrigin(sf::Vector2f(50, 10));
	showOldFlyNumber.setPosition(sf::Vector2f(1200, 180));
	////////
	showKidRespText.setFont(manager->GetFont("trebu"));
	showKidRespText.setCharacterSize(11.5);
	showKidRespText.setFillColor(sf::Color::White);
	showKidRespText.setOrigin(sf::Vector2f(50, 10));
	showKidRespText.setPosition(sf::Vector2f(1080, 200));
	showKidRespText.setString("Muchy z jednego legu:");

	plusSpriteKidResp.setTexture(manager->GetTexture("plus"));
	plusSpriteKidResp.setOrigin(1, 1);
	plusSpriteKidResp.setPosition(sf::Vector2f(1190, 193));

	minusSpriteKidResp.setTexture(manager->GetTexture("minus"));
	minusSpriteKidResp.setOrigin(1, 1);
	minusSpriteKidResp.setPosition(sf::Vector2f(1210, 193));

	showKidRespNumber.setFont(manager->GetFont("trebu"));
	showKidRespNumber.setCharacterSize(11.5);
	showKidRespNumber.setFillColor(sf::Color::Yellow);
	showKidRespNumber.setOrigin(sf::Vector2f(50, 10));
	showKidRespNumber.setPosition(sf::Vector2f(1200, 200));
	////
	showKidDpsText.setFont(manager->GetFont("trebu"));
	showKidDpsText.setCharacterSize(11.5);
	showKidDpsText.setFillColor(sf::Color::White);
	showKidDpsText.setOrigin(sf::Vector2f(50, 10));
	showKidDpsText.setPosition(sf::Vector2f(1080, 220));
	showKidDpsText.setString("Nieodpornosc mlodej: ");

	plusKidDps.setTexture(manager->GetTexture("plus"));
	plusKidDps.setOrigin(1, 1);
	plusKidDps.setPosition(sf::Vector2f(1190, 213));

	minusKidDps.setTexture(manager->GetTexture("minus"));
	minusKidDps.setOrigin(1, 1);
	minusKidDps.setPosition(sf::Vector2f(1210, 213));

	showKidDpsNumber.setFont(manager->GetFont("trebu"));
	showKidDpsNumber.setCharacterSize(11.5);
	showKidDpsNumber.setFillColor(sf::Color::Yellow);
	showKidDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showKidDpsNumber.setPosition(sf::Vector2f(1200, 220));
	////
	showMatureDpsText.setFont(manager->GetFont("trebu"));
	showMatureDpsText.setCharacterSize(11.5);
	showMatureDpsText.setFillColor(sf::Color::White);
	showMatureDpsText.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsText.setPosition(sf::Vector2f(1080, 240));
	showMatureDpsText.setString("Nieodpornosc doroslej:");

	plusMatureDps.setTexture(manager->GetTexture("plus"));
	plusMatureDps.setOrigin(1, 1);
	plusMatureDps.setPosition(sf::Vector2f(1190, 233));

	minusMatureDps.setTexture(manager->GetTexture("minus"));
	minusMatureDps.setOrigin(1, 1);
	minusMatureDps.setPosition(sf::Vector2f(1210, 233));

	showMatureDpsNumber.setFont(manager->GetFont("trebu"));
	showMatureDpsNumber.setCharacterSize(11.5);
	showMatureDpsNumber.setFillColor(sf::Color::Yellow);
	showMatureDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureDpsNumber.setPosition(sf::Vector2f(1200, 240));
	////
	showOldDpsText.setFont(manager->GetFont("trebu"));
	showOldDpsText.setCharacterSize(11.5);
	showOldDpsText.setFillColor(sf::Color::White);
	showOldDpsText.setOrigin(sf::Vector2f(50, 10));
	showOldDpsText.setPosition(sf::Vector2f(1080, 260));
	showOldDpsText.setString("Nieodpornosc starszej:");

	plusOldDps.setTexture(manager->GetTexture("plus"));
	plusOldDps.setOrigin(1, 1);
	plusOldDps.setPosition(sf::Vector2f(1190, 253));

	minusOldDps.setTexture(manager->GetTexture("minus"));
	minusOldDps.setOrigin(1, 1);
	minusOldDps.setPosition(sf::Vector2f(1210, 253));

	showOldDpsNumber.setFont(manager->GetFont("trebu"));
	showOldDpsNumber.setCharacterSize(11.5);
	showOldDpsNumber.setFillColor(sf::Color::Yellow);
	showOldDpsNumber.setOrigin(sf::Vector2f(50, 10));
	showOldDpsNumber.setPosition(sf::Vector2f(1200, 260));
	////
	showEggRespText.setFont(manager->GetFont("trebu"));
	showEggRespText.setCharacterSize(11.5);
	showEggRespText.setFillColor(sf::Color::White);
	showEggRespText.setOrigin(sf::Vector2f(50, 10));
	showEggRespText.setPosition(sf::Vector2f(1080, 280));
	showEggRespText.setString("Jaja generuja sie co:");

	plusEggResp.setTexture(manager->GetTexture("plus"));
	plusEggResp.setOrigin(1, 1);
	plusEggResp.setPosition(sf::Vector2f(1190, 273));

	minusEggResp.setTexture(manager->GetTexture("minus"));
	minusEggResp.setOrigin(1, 1);
	minusEggResp.setPosition(sf::Vector2f(1210, 273));

	showEggRespNumber.setFont(manager->GetFont("trebu"));
	showEggRespNumber.setCharacterSize(11.5);
	showEggRespNumber.setFillColor(sf::Color::Yellow);
	showEggRespNumber.setOrigin(sf::Vector2f(50, 10));
	showEggRespNumber.setPosition(sf::Vector2f(1200, 280));
	////
	showCoinRespText.setFont(manager->GetFont("trebu"));
	showCoinRespText.setCharacterSize(11.5);
	showCoinRespText.setFillColor(sf::Color::White);
	showCoinRespText.setOrigin(sf::Vector2f(50, 10));
	showCoinRespText.setPosition(sf::Vector2f(1080, 300));
	showCoinRespText.setString("Monety generuja sie co:");

	plusCoinResp.setTexture(manager->GetTexture("plus"));
	plusCoinResp.setOrigin(1, 1);
	plusCoinResp.setPosition(sf::Vector2f(1190, 293));

	minusCoinResp.setTexture(manager->GetTexture("minus"));
	minusCoinResp.setOrigin(1, 1);
	minusCoinResp.setPosition(sf::Vector2f(1210, 293));

	showCoinRespNumber.setFont(manager->GetFont("trebu"));
	showCoinRespNumber.setCharacterSize(11.5);
	showCoinRespNumber.setFillColor(sf::Color::Yellow);
	showCoinRespNumber.setOrigin(sf::Vector2f(50, 10));
	showCoinRespNumber.setPosition(sf::Vector2f(1200, 300));
	////


	showKidLifeText.setFont(manager->GetFont("trebu"));
	showKidLifeText.setCharacterSize(11.5);
	showKidLifeText.setFillColor(sf::Color::White);
	showKidLifeText.setOrigin(sf::Vector2f(50, 10));
	showKidLifeText.setPosition(sf::Vector2f(1080, 320));
	showKidLifeText.setString("Ilosc zycia mlodej:");

	plusKidLife.setTexture(manager->GetTexture("plus"));
	plusKidLife.setOrigin(1, 1);
	plusKidLife.setPosition(sf::Vector2f(1190, 313));

	minusKidLife.setTexture(manager->GetTexture("minus"));
	minusKidLife.setOrigin(1, 1);
	minusKidLife.setPosition(sf::Vector2f(1210, 313));

	showKidLifeNumber.setFont(manager->GetFont("trebu"));
	showKidLifeNumber.setCharacterSize(11.5);
	showKidLifeNumber.setFillColor(sf::Color::Yellow);
	showKidLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showKidLifeNumber.setPosition(sf::Vector2f(1200, 320));
	////
	showMatureLifeText.setFont(manager->GetFont("trebu"));
	showMatureLifeText.setCharacterSize(11.5);
	showMatureLifeText.setFillColor(sf::Color::White);
	showMatureLifeText.setOrigin(sf::Vector2f(50, 10));
	showMatureLifeText.setPosition(sf::Vector2f(1080, 340));
	showMatureLifeText.setString("Ilosc zycia doroslej:");

	plusMatureLife.setTexture(manager->GetTexture("plus"));
	plusMatureLife.setOrigin(1, 1);
	plusMatureLife.setPosition(sf::Vector2f(1190, 333));

	minusMatureLife.setTexture(manager->GetTexture("minus"));
	minusMatureLife.setOrigin(1, 1);
	minusMatureLife.setPosition(sf::Vector2f(1210, 333));

	showMatureLifeNumber.setFont(manager->GetFont("trebu"));
	showMatureLifeNumber.setCharacterSize(11.5);
	showMatureLifeNumber.setFillColor(sf::Color::Yellow);
	showMatureLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureLifeNumber.setPosition(sf::Vector2f(1200, 340));
	////
	showOldLifeText.setFont(manager->GetFont("trebu"));
	showOldLifeText.setCharacterSize(11.5);
	showOldLifeText.setFillColor(sf::Color::White);
	showOldLifeText.setOrigin(sf::Vector2f(50, 10));
	showOldLifeText.setPosition(sf::Vector2f(1080, 360));
	showOldLifeText.setString("Ilosc zycia starszej:");

	plusOldLife.setTexture(manager->GetTexture("plus"));
	plusOldLife.setOrigin(1, 1);
	plusOldLife.setPosition(sf::Vector2f(1190, 353));

	minusOldLife.setTexture(manager->GetTexture("minus"));
	minusOldLife.setOrigin(1, 1);
	minusOldLife.setPosition(sf::Vector2f(1210, 353));

	showOldLifeNumber.setFont(manager->GetFont("trebu"));
	showOldLifeNumber.setCharacterSize(11.5);
	showOldLifeNumber.setFillColor(sf::Color::Yellow);
	showOldLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showOldLifeNumber.setPosition(sf::Vector2f(1200, 360));
	////
	showKidProductText.setFont(manager->GetFont("trebu"));
	showKidProductText.setCharacterSize(11.5);
	showKidProductText.setFillColor(sf::Color::White);
	showKidProductText.setOrigin(sf::Vector2f(50, 10));
	showKidProductText.setPosition(sf::Vector2f(1080, 380));
	showKidProductText.setString("Dlugosc zycia mlodej:");

	plusKidProduct.setTexture(manager->GetTexture("plus"));
	plusKidProduct.setOrigin(1, 1);
	plusKidProduct.setPosition(sf::Vector2f(1190, 373));

	minusKidProduct.setTexture(manager->GetTexture("minus"));
	minusKidProduct.setOrigin(1, 1);
	minusKidProduct.setPosition(sf::Vector2f(1210, 373));

	showKidProductNumber.setFont(manager->GetFont("trebu"));
	showKidProductNumber.setCharacterSize(11.5);
	showKidProductNumber.setFillColor(sf::Color::Yellow);
	showKidProductNumber.setOrigin(sf::Vector2f(50, 10));
	showKidProductNumber.setPosition(sf::Vector2f(1200, 380));
	////
	showMatureProductText.setFont(manager->GetFont("trebu"));
	showMatureProductText.setCharacterSize(11.5);
	showMatureProductText.setFillColor(sf::Color::White);
	showMatureProductText.setOrigin(sf::Vector2f(50, 10));
	showMatureProductText.setPosition(sf::Vector2f(1080, 400));
	showMatureProductText.setString("Dlugosc zycia doroslej:");

	plusMatureProduct.setTexture(manager->GetTexture("plus"));
	plusMatureProduct.setOrigin(1, 1);
	plusMatureProduct.setPosition(sf::Vector2f(1190, 393));

	minusMatureProduct.setTexture(manager->GetTexture("minus"));
	minusMatureProduct.setOrigin(1, 1);
	minusMatureProduct.setPosition(sf::Vector2f(1210, 393));

	showMatureProductNumber.setFont(manager->GetFont("trebu"));
	showMatureProductNumber.setCharacterSize(11.5);
	showMatureProductNumber.setFillColor(sf::Color::Yellow);
	showMatureProductNumber.setOrigin(sf::Vector2f(50, 10));
	showMatureProductNumber.setPosition(sf::Vector2f(1200, 400));
	////
	showOldProductText.setFont(manager->GetFont("trebu"));
	showOldProductText.setCharacterSize(11.5);
	showOldProductText.setFillColor(sf::Color::White);
	showOldProductText.setOrigin(sf::Vector2f(50, 10));
	showOldProductText.setPosition(sf::Vector2f(1080, 420));
	showOldProductText.setString("Dlugosc zycia starszej:");

	plusOldProduct.setTexture(manager->GetTexture("plus"));
	plusOldProduct.setOrigin(1, 1);
	plusOldProduct.setPosition(sf::Vector2f(1190, 413));

	minusOldProduct.setTexture(manager->GetTexture("minus"));
	minusOldProduct.setOrigin(1, 1);
	minusOldProduct.setPosition(sf::Vector2f(1210, 413));

	showOldProductNumber.setFont(manager->GetFont("trebu"));
	showOldProductNumber.setCharacterSize(11.5);
	showOldProductNumber.setFillColor(sf::Color::Yellow);
	showOldProductNumber.setOrigin(sf::Vector2f(50, 10));
	showOldProductNumber.setPosition(sf::Vector2f(1200, 420));
	////
	showRespawnText.setFont(manager->GetFont("trebu"));
	showRespawnText.setCharacterSize(11.5);
	showRespawnText.setFillColor(sf::Color::White);
	showRespawnText.setOrigin(sf::Vector2f(50, 10));
	showRespawnText.setPosition(sf::Vector2f(1080, 440));
	showRespawnText.setString("Nowy leg much co:");

	plusRespawn.setTexture(manager->GetTexture("plus"));
	plusRespawn.setOrigin(1, 1);
	plusRespawn.setPosition(sf::Vector2f(1190, 433));

	minusRespawn.setTexture(manager->GetTexture("minus"));
	minusRespawn.setOrigin(1, 1);
	minusRespawn.setPosition(sf::Vector2f(1210, 433));

	showRespawnNumber.setFont(manager->GetFont("trebu"));
	showRespawnNumber.setCharacterSize(11.5);
	showRespawnNumber.setFillColor(sf::Color::Yellow);
	showRespawnNumber.setOrigin(sf::Vector2f(50, 10));
	showRespawnNumber.setPosition(sf::Vector2f(1200, 440));
	////
	showEggText.setFont(manager->GetFont("trebu"));
	showEggText.setCharacterSize(11.5);
	showEggText.setFillColor(sf::Color::White);
	showEggText.setOrigin(sf::Vector2f(50, 10));
	showEggText.setPosition(sf::Vector2f(1080, 460));
	showEggText.setString("Jedzenie z jajka:");

	plusEgg.setTexture(manager->GetTexture("plus"));
	plusEgg.setOrigin(1, 1);
	plusEgg.setPosition(sf::Vector2f(1190, 453));

	minusEgg.setTexture(manager->GetTexture("minus"));
	minusEgg.setOrigin(1, 1);
	minusEgg.setPosition(sf::Vector2f(1210, 453));

	showEggNumber.setFont(manager->GetFont("trebu"));
	showEggNumber.setCharacterSize(11.5);
	showEggNumber.setFillColor(sf::Color::Yellow);
	showEggNumber.setOrigin(sf::Vector2f(50, 10));
	showEggNumber.setPosition(sf::Vector2f(1200, 460));
	////
	showFlyTypeText.setFont(manager->GetFont("trebu"));
	showFlyTypeText.setCharacterSize(14);
	showFlyTypeText.Bold;
	showFlyTypeText.setFillColor(sf::Color::Red);
	showFlyTypeText.setOrigin(sf::Vector2f(1, 1));
	showFlyTypeText.setPosition(sf::Vector2f(1090, 625));

	Fly.setOrigin(1, 1);
	Fly.setPosition(sf::Vector2f(1030, 615));

	showFlyPositionNumber.setFont(manager->GetFont("trebu"));
	showFlyPositionNumber.setCharacterSize(11.5);
	showFlyPositionNumber.setFillColor(sf::Color::Yellow);
	showFlyPositionNumber.setOrigin(sf::Vector2f(50, 10));
	showFlyPositionNumber.setPosition(sf::Vector2f(1080, 675));
	showFlyLifeNumber.setFont(manager->GetFont("trebu"));
	showFlyLifeNumber.setCharacterSize(11.5);
	showFlyLifeNumber.setFillColor(sf::Color::Yellow);
	showFlyLifeNumber.setOrigin(sf::Vector2f(50, 10));
	showFlyLifeNumber.setPosition(sf::Vector2f(1080, 660));

	showFlySpeedNumber.setFont(manager->GetFont("trebu"));
	showFlySpeedNumber.setCharacterSize(11.5);
	showFlySpeedNumber.setFillColor(sf::Color::Yellow);
	showFlySpeedNumber.setOrigin(sf::Vector2f(50, 10));
	showFlySpeedNumber.setPosition(sf::Vector2f(1080, 690));

	showFlySizeNumber.setFont(manager->GetFont("trebu"));
	showFlySizeNumber.setCharacterSize(11.5);
	showFlySizeNumber.setFillColor(sf::Color::Yellow);
	showFlySizeNumber.setOrigin(sf::Vector2f(50, 10));
	showFlySizeNumber.setPosition(sf::Vector2f(1080, 705));

	showFlyBornNumber.setFont(manager->GetFont("trebu"));
	showFlyBornNumber.setCharacterSize(11.5);
	showFlyBornNumber.setFillColor(sf::Color::Yellow);
	showFlyBornNumber.setOrigin(sf::Vector2f(50, 10));
	showFlyBornNumber.setPosition(sf::Vector2f(1080, 720));

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
	target.draw(btnGenerate);
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
	target.draw(plusKidProduct);
	target.draw(minusKidProduct);
	target.draw(plusMatureProduct);
	target.draw(minusMatureProduct);
	target.draw(plusOldProduct);
	target.draw(minusOldProduct);
	target.draw(plusRespawn);
	target.draw(minusRespawn);
	target.draw(showKidProductText);
	target.draw(showMatureProductText);
	target.draw(showOldProductText);
	target.draw(showKidProductNumber);
	target.draw(showMatureProductNumber);
	target.draw(showOldProductNumber);
	target.draw(showRespawnText);
	target.draw(showRespawnNumber);
	target.draw(showEggText);
	target.draw(showEggNumber);
	target.draw(plusEgg);
	target.draw(minusEgg);
	target.draw(showFlyPositionNumber);
	target.draw(showFlyLifeNumber);
	target.draw(showFlySpeedNumber);
	target.draw(showFlySizeNumber);
	target.draw(showFlyBornNumber);
	target.draw(showFlyTypeText);
	target.draw(Fly);
	target.draw(foot);
	target.draw(head);
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
		timeElapsed.setString(m + " m, " + s + " s");
	}
	p_Time = k;
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
void Menu::showKidProduct(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showKidProductNumber.setString(s+" s");
	KidProduct = k/30;
}
void Menu::showMatureProduct(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showMatureProductNumber.setString(s+" s");
	MatureProduct = k / 30;
}
void Menu::showOldProduct(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showOldProductNumber.setString(s+" s");
	OldProduct = k / 30;
}
void Menu::showRespawnTime(int k)
{
	int time = k / 30;
	std::string s = std::to_string(time);
	showRespawnNumber.setString(s+" s");
}
void Menu::showEggFood(int k)
{
	std::string s = std::to_string(k);
	showEggNumber.setString(s);
}
void Menu::showFly(Kid & fly, int k)
{
	kid = &fly;
	FlyNumber = k;
	Show = true;
}
void Menu::updateFly()
{
	if (FlyNumber != 0 && Show == true)
	{
		if (kid->isDead == false )
		{

			if (FlyNumber == 1)
			{
				Fly.setPosition(sf::Vector2f(1035, 625));
				Fly.setTexture(manager->GetTexture("kid"), true);
				
				showFlyTypeText.setString("Dziecko");
				int x = kid->getPosition().x;
				int y = kid->getPosition().y;
				std::string xx = std::to_string(x);
				std::string yy = std::to_string(y);
				showFlyPositionNumber.setString("Pozycja: X: " + xx + " Y: " + yy);
				int life = kid->life;
				std::string lifestr = std::to_string(life);
				std::string lifeCap = std::to_string(kid->startLife);
				showFlyLifeNumber.setString("Zycie: " + lifestr + " /" + lifeCap);
				int speed = kid->predkosc * 30;
				std::string speedstr = std::to_string(speed);
				showFlySpeedNumber.setString("Obecna predkosc muchy: " + speedstr + " px/s");
				int size = kid->getSize() / 30;
				std::string sizestr = std::to_string(size);
				std::string sizeNow = std::to_string(KidProduct);
				showFlySizeNumber.setString("Czas zycia: " + sizestr + " /" + sizeNow);


				std::string s = std::to_string((p_Time / 30 - kid->bornTime / 30) % 60);
				std::string m = std::to_string((p_Time / 30 - kid->bornTime / 30) / 60);
				if (((p_Time / 30) / 60) < 1)
				{

					showFlyBornNumber.setString("Stworzona: " + s + " s temu");
				}
				else
				{
					showFlyBornNumber.setString("Stworzona: " + m + " m, " + s + " s temu");
				}
			}

			else if (FlyNumber == 2)
			{
				Fly.setPosition(sf::Vector2f(1030, 620));
				Fly.setTexture(manager->GetTexture("fly-mature"), true);

				showFlyTypeText.setString("Dorosla");
				int x = kid->getPosition().x;
				int y = kid->getPosition().y;
				std::string xx = std::to_string(x);
				std::string yy = std::to_string(y);
				showFlyPositionNumber.setString("Pozycja: X: " + xx + " Y: " + yy);
				int life = kid->life;
				std::string lifestr = std::to_string(life);
				std::string lifeCap = std::to_string(kid->startLife);
				showFlyLifeNumber.setString("Zycie: " + lifestr + " /" + lifeCap);
				int speed = kid->predkosc * 30;
				std::string speedstr = std::to_string(speed);
				showFlySpeedNumber.setString("Obecna predkosc muchy: " + speedstr + " px/s");
				int size = kid->getSize() / 30;
				std::string sizestr = std::to_string(size);
				std::string sizeNow = std::to_string(MatureProduct);
				showFlySizeNumber.setString("Czas zycia: " + sizestr + " /" + sizeNow);


				std::string s = std::to_string((p_Time / 30 - kid->bornTime / 30) % 60);
				std::string m = std::to_string((p_Time / 30 - kid->bornTime / 30) / 60);
				if (((p_Time / 30) / 60) < 1)
				{

					showFlyBornNumber.setString("Stworzona: " + s + " s temu");
				}
				else
				{
					showFlyBornNumber.setString("Stworzona: " + m + " m, " + s + " s temu");
				}
			}
			else if (FlyNumber == 3)
			{
				Fly.setPosition(sf::Vector2f(1030, 615));
				Fly.setTexture(manager->GetTexture("fly-old"), true);

				showFlyTypeText.setString("Starsza");
				int x = kid->getPosition().x;
				int y = kid->getPosition().y;
				std::string xx = std::to_string(x);
				std::string yy = std::to_string(y);
				showFlyPositionNumber.setString("Pozycja: X: " + xx + " Y: " + yy);
				int life = kid->life;
				std::string lifestr = std::to_string(life);
				std::string lifeCap = std::to_string(kid->startLife);
				showFlyLifeNumber.setString("Zycie: " + lifestr + " /" + lifeCap);
				int speed = kid->predkosc * 30;
				std::string speedstr = std::to_string(speed);
				showFlySpeedNumber.setString("Obecna predkosc muchy: " + speedstr + " px/s");
				int size = kid->getSize() / 30;
				std::string sizestr = std::to_string(size);
				std::string sizeNow = std::to_string(OldProduct);
				showFlySizeNumber.setString("Czas zycia: " + sizestr + " /" + sizeNow);


				std::string s = std::to_string((p_Time / 30 - kid->bornTime / 30) % 60);
				std::string m = std::to_string((p_Time / 30 - kid->bornTime / 30) / 60);
				if (((p_Time / 30) / 60) < 1)
				{

					showFlyBornNumber.setString("Stworzona: " + s + " s temu");
				}
				else
				{
					showFlyBornNumber.setString("Stworzona: " + m + " m, " + s + " s temu");
				}
			}
		}
		else 
		{
		Show = false;
		kid = nullptr;
		showFlyTypeText.setString("[*]");
		showFlyPositionNumber.setString("");
		showFlyLifeNumber.setString("");
		showFlySpeedNumber.setString("");
		showFlySizeNumber.setString("");
		showFlyBornNumber.setString("");
		}
	}
	
	

}
sf::Sprite * Menu::getSprite(int k)
{
	if (k == 1)
	{
		return &this->plusSpriteKid;
	}
	else if (k == 2)
	{
		return &this->minusSpriteKid;
	}
	else if (k == 3)
	{
		return &this->plusSpriteMature;
	}
	else if (k == 4)
	{
		return &this->minusSpriteMature;
	}
	else if (k == 5)
	{
		return &this->plusSpriteOld;
	}
	else if (k == 6)
	{
		return &this->minusSpriteOld;
	}
	else if (k == 7)
	{
		return &this->plusSpriteNestFood;
	}
	else if (k == 8)
	{
		return &this->minusSpriteNestFood;
	}
	else if (k == 9)
	{
		return &this->plusSpriteNestMoney;
	}
	else if (k == 10)
	{
		return &this->minusSpriteNestMoney;
	}
	else if (k == 11)
	{
		return &this->plusSpriteKidResp;
	}
	else if (k == 12)
	{
		return &this->minusSpriteKidResp;
	}
	else if (k == 13)
	{
		return &this->plusKidDps;
	}
	else if (k == 14)
	{
		return &this->minusKidDps;
	}
	else if (k == 15)
	{
		return &this->plusMatureDps;
	}
	else if (k == 16)
	{
		return &this->minusMatureDps;
	}
	else if (k == 17)
	{
		return &this->plusOldDps;
	}
	else if (k == 18)
	{
		return &this->minusOldDps;
	}
	else if (k == 19)
	{
		return &this->plusCoinResp;
	}
	else if (k == 20)
	{
		return &this->minusCoinResp;
	}
	else if (k == 21)
	{
		return &this->plusEggResp;
	}
	else if (k == 22)
	{
		return &this->minusEggResp;
	}
	else if (k == 23)
	{
		return &this->btnPause;
	}
	else if (k == 24)
	{
		return &this->plusKidLife;
	}
	else if (k == 25)
	{
		return &this->minusKidLife;
	}
	else if (k == 26)
	{
		return &this->plusMatureLife;
	}
	else if (k == 27)
	{
		return &this->minusMatureLife;
	}
	else if (k == 28)
	{
		return &this->plusOldLife;
	}
	else if (k == 29)
	{
		return &this->minusOldLife;
	}
	else if (k == 30)
	{
		return &this->btnGenerate;
	}
	else if (k == 31)
	{
		return &this->plusKidProduct;
	}
	else if (k == 32)
	{
		return &this->minusKidProduct;
	}
	else if (k == 33)
	{
		return &this->plusMatureProduct;
	}
	else if (k == 34)
	{
		return &this->minusMatureProduct;
	}
	else if (k == 35)
	{
		return &this->plusOldProduct;
	}
	else if (k == 36)
	{
		return &this->minusOldProduct;
	}
	else if (k == 37)
	{
		return &this->plusRespawn;
	}
	else if (k == 38)
	{
		return &this->minusRespawn;
	}
	else if (k == 39)
	{
		return &this->plusEgg;
	}
	else if (k == 40)
	{
		return &this->minusEgg;
	}
}
