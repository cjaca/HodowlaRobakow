#include "PlayState.h"
#include <cstdlib>
#include <ctime>
#include <time.h>

PlayState::PlayState(sf::RenderWindow * window, GameStates * state)
{
	this->window = window;
	this->state = state;
	this->isGameStarted = false;

}

PlayState::~PlayState()
{
}

void PlayState::Init()
{
	assets = new AssetManager();
	
	srand(time(NULL));
	assets->LoadTexture("kid", KIDFLY_FILEPATH);
	assets->LoadTexture("fly-mature", MATUREFLY_FILEPATH);
	assets->LoadTexture("fly-egg", MATUREFLYEGG_FILEPATH);
	assets->LoadTexture("fly-old", OLDFLY_FILEPATH);
	assets->LoadTexture("nest", NEST_FILEPATH);
	assets->LoadTexture("egg", EGG_FILEPATH);
	assets->LoadTexture("coin", COIN_FILEPATH);
	assets->LoadTexture("fly-coin", FLYCOIN_FILEPATH);
	assets->LoadTexture("plus", PLUS_FILEPATH);
	assets->LoadTexture("minus", MINUS_FILEPATH);
	assets->LoadTexture("pause", BTNPAUSE_FILEPATH);
	assets->LoadTexture("start", BTNSTART_FILEPATH);
	assets->LoadFont("trebu", TREBU_FILEPATH);



	for (int i = 0; i < iloscMuch; i++)
	{
		Mature *mature;
		Kid *kid;
		Egg *egg;
		Coin *coin;
		Old *old;
		mature = new Mature(*assets,sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), matureLife);
		kid = new Kid(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), kidLife);
		egg = new Egg(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		coin = new Coin(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		old = new Old(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), oldLife);
		dorosli.push_back(*mature);
		dzieci.push_back(*kid);
		jaja.push_back(*egg);
		kasa.push_back(*coin);
		stare.push_back(*old);
	}
	menu = new Menu(*assets);
	gniazdo = new Nest(*assets);

	

}

void PlayState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) window->close();


		// if (event.type == sf::Event::KeyPressed) 
		// {
		// 	switch (event.key.code) {

		// 	case sf::Keyboard::Escape: window->close(); break;


		// 	case sf::Keyboard::Space:
		// 		std::cout << "Dodano kid muche" << std::endl;
		// 		Kid *kid;
		// 		kid = new Kid(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		// 		dzieci.push_back(*kid);
		// 		break;
		// 	case sf::Keyboard::X:
		// 		if (dorosli.size() > 0) {
		// 			std::cout << "Usunieto jedna dorosla muche" << std::endl;
		// 			dorosli.erase(dorosli.begin());
		// 			std::cout << dorosli.size() << std::endl;
		// 		}
		// 		else std::cout << "Nie ma juz much do usuniecia" << std::endl;
		// 		break;
		// 	case sf::Keyboard::E:
		// 		std::cout << "Dodano jajko" << std::endl;
		// 		Egg *egg;
		// 		egg = new Egg(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		// 		jaja.push_back(*egg);
		// 		break;
		// 	case sf::Keyboard::D:
		// 		if (jaja.size() > 0) {
		// 			std::cout << "usunieto jajo" << std::endl;
		// 			jaja.erase(jaja.begin());
		// 		}
		// 		else std::cout << "Nie ma juz jaj do usuniecia" << std::endl;
		// 		break;
		// 	}
		// }
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 1; i < 28; i++)
			{
				menu->getSprite(i)->getPosition().x;
				sf::IntRect tempRect(menu->getSprite(i)->getPosition().x, menu->getSprite(i)->getPosition().y, menu->getSprite(i)->getGlobalBounds().width, menu->getSprite(i)->getGlobalBounds().height);
				if (tempRect.contains(sf::Mouse::getPosition(*window)))
				{
					if (i == 1)
					{
						std::cout << "Dodano kid muche" << std::endl;
						Kid *kid;
						kid = new Kid(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), kidLife);
						dzieci.push_back(*kid);
					}
					if (i == 2)
					{
						if (dzieci.size() > 0) {
							dzieci.erase(dzieci.begin());
						}
					}
					if (i == 3)
					{
						std::cout << "Dodano dorosla muche" << std::endl;
						Mature *mature;
						mature = new Mature(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), matureLife);
						dorosli.push_back(*mature);
					}
					if (i == 4)
					{
						if (dorosli.size() > 0) {
							dorosli.erase(dorosli.begin());
						}
					}
					if (i == 5)
					{
						std::cout << "Dodano starsza muche" << std::endl;
						Old *old;
						old = new Old(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), oldLife);
						stare.push_back(*old);
					}
					if (i == 6)
					{
						if (stare.size() > 0) {
							stare.erase(stare.begin());
						}
					}
					if (i == 7)
					{
						std::cout << "Dodano jedzenie do gniazda" << std::endl;
						gniazdo->setNestFood(200);
					}
					if (i == 8)
					{
						if (gniazdo->getNestFood() > 0) {
							gniazdo->setNestFood(-200);
						}
					}
					if (i == 9)
					{
						std::cout << "Dodano monetke do gniazda" << std::endl;
						gniazdo->setMoney(1);
					}
					if (i == 10)
					{
						if (gniazdo->getMoney() > 0) {
							gniazdo->setMoney(-1);
						}
					}
					if (i == 11)
					{
						std::cout << "Dodano ilosc much z jednego legu" << std::endl;
						kidAmmount += 1;
					}
					if (i == 12)
					{
						if (kidAmmount > 0) {
							kidAmmount -= 1;
						}
					}
					if (i == 13)
					{
						std::cout << "Zmniejszono przezywalnosc mlodej muchy" << std::endl;
						kidDPS += 0.02;
					}
					if (i == 14)
					{
						if (kidDPS > 0.02) {
							kidDPS -= 0.02;
						}
					}
					if (i == 15)
					{
						std::cout << "Zmniejszono przezywalnosc doroslej muchy" << std::endl;
						matureDPS += 0.02;
					}
					if (i == 16)
					{
						if (matureDPS > 0.02) {
							matureDPS -= 0.02;
						}
						else std::cout << "nie mozna juz zmniejszyc przezywalnosci muchy" << std::endl;
					}
					if (i == 17)
					{
						std::cout << "Zmniejszono przezywalnosc starszej muchy" << std::endl;
						oldDPS += 0.02;
					}
					if (i == 18)
					{
						if (oldDPS > 0.02) {
							oldDPS -= 0.02;
						}
						else std::cout << "nie mozna juz zmniejszyc przezywalnosci muchy" << std::endl;
					}
					if (i == 19)
					{
						std::cout << "Zwiekszono czas respawnu monetek o sekunde" << std::endl;
						coinTR += 30;
					}
					if (i == 20)
					{
						if (coinTR > 30) {
							coinTR -= 30;
						}
					}
					if (i == 21)
					{
						std::cout << "Zwiekszono czas respawnu jajek o sekunde" << std::endl;
						eggTR += 30;
					}
					if (i == 22)
					{
						if (eggTR > 30) {
							eggTR -= 30;
						}
					}
					if (i == 23)
					{
						if (pause == true)
						{
							pause = false;
						}
						else if (pause == false)
						{
							pause = true;
						}
					}
					if (i == 24)
					{
						std::cout<<"zwiekszono zycie mlodej muchy"<<std::endl;
						kidLife +=1;
					}
					if (i == 25)
					{
						kidLife-=1;
					}
					if (i == 26)
					{
						std::cout<<"zwiekszono zycie doroslej muchy"<<std::endl;
						matureLife +=1;
					}
					if (i == 27)
					{
						matureLife -=1;
					}
				}
			}
		}
	}
}



void PlayState::Update()
{
	menu->showTimer(this->dt);
	menu->showTotalFly(dzieci.size()+ dorosli.size()+ stare.size());
	menu->showKidFly(dzieci.size());
	menu->showMatureFly(dorosli.size());
	menu->showOldFly(stare.size());
	menu->showNestAttributes(gniazdo->getNestFood());
	menu->showNestMoney(gniazdo->getMoney());
	menu->showKidRespAmmount(kidAmmount);
	menu->showKidDps(kidDPS*50);
	menu->showMatureDps(matureDPS*50);
	menu->showOldDps(oldDPS*50);
	menu->showCoinResp(coinTR);
	menu->showEggResp(eggTR);
	menu->buttonPause(pause);
	menu->showKidLife(kidLife);
	menu->showMatureLife(matureLife);
	menu->showOldLife(oldLife);
	if (pause == false)
	{
	evolution(); //sprawdzanie ewolucji malej muchy
	randomGen();
	cleanUp(); //sprzatanie zdechlych much
	if (dorosli.size() > 0)
	{
		for (int i = 0; i < dorosli.size(); i++)
		{
			dorosli[i].setSize(matureDPS); // zwiekszanie wieku doroslych 

			if (dorosli[i].isAsleep == false)
			{

				if (dorosli[i].updateMove(*dorosli[i].getSprite()) == 1) //poruszanie doroslymi, jezeli zostala zwrocona jedynka, to dodaje do gniazda jedzenie (bo zostalo odniesione jajko)
				{
					gniazdo->setNestFood(200);
				}

				if (collision.CheckCollision(*dorosli[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dorosly gniazdo
				{
					dorosli[i].kolizja();
				}

				for (int k = 0; k < dzieci.size(); k++) //kolizja dorosly - dziecko
				{
					if (collision.CheckCollision(*dorosli[i].getSprite(), *dzieci[k].getSprite()) == true)
					{
						if (dzieci[k].collectedInfo == true && dorosli[i].flagaKolizja == true)
						{
							dorosli[i].goGetIt(dzieci[k].itemPosition);
							dzieci[k].collectedInfo = false;
							dzieci[k].kolizja();
						}
						else
						{
							dorosli[i].kolizja();
							dzieci[k].kolizja();
						}

					}
				}
				


				for (int l = 0; l < jaja.size(); l++) //kolizja dorosly - jajko
				{
					if (collision.CheckCollision(*dorosli[i].getSprite(), *jaja[l].getSprite()) == true)
					{
						if (dorosli[i].flagaKolizja == true)
						{
							if (jaja[l].flaga == false) 
							{
								dorosli[i].collect();
								jaja.erase(jaja.begin() + l);
								l -= l;
							}
							break;
						}
						if (dorosli[i].flagaKolizja == false && dorosli[i].goToEgg == true)
						{
							//std::cout << "mucha zrezygnowala z pojscia po jajko i wziela pierwsze po drodze" << std::endl;
							dorosli[i].instrukcja = 0;
							dorosli[i].goToEgg = false;
							dorosli[i].collect();
							jaja.erase(jaja.begin() + l);
							l -= l;
						}

					}
				}
				for (int j = 0; j < kasa.size(); j++) // kolizja dorosly-kasa, zbieranie informacji
				{
					if (collision.CheckCollision(*dorosli[i].getSprite(), *kasa[j].getSprite()) == true)
					{
						//std::cout << "Mature zebrala info gdzie jest hajs" << std::endl;
						dorosli[i].gatherInfo(kasa[j].getPosition());
						dorosli[i].kolizja();
					}
				}
				for (int j = 0; j < dorosli.size() - 1; j++)
				{
					if (i != j)
					{
						if (collision.CheckCollision(*dorosli[i].getSprite(), *dorosli[j].getSprite()) == true) //sprawdzanie kolizji dorosly - dorosly
						{
							dorosli[i].kolizja();
						}
					}
				}
			}
		}
	}

	if (dzieci.size() > 0)
	{
		for (int i = 0; i < dzieci.size(); i++)
		{
			dzieci[i].setSize(kidDPS); //zwiekszanie ich wieku
			if (dzieci[i].isAsleep == false)
			{
				dzieci[i].updateMove(*dzieci[i].getSprite()); //poruszanie dziecmi

				if (dzieci[i].flagaKolizja == true)
				{
					for (int j = 0; j < dzieci.size() - 1; j++)
					{
						if (i != j)
						{
							if (collision.CheckCollision(*dzieci[i].getSprite(), *dzieci[j].getSprite()) == true) // kolizja dzieci-dzieci
							{
								dzieci[i].kolizja();
							}
						}
					}
					if (collision.CheckCollision(*dzieci[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dziecko-gniazdo
					{
						dzieci[i].kolizja();
					}
					for (int j = 0; j < jaja.size(); j++)
					{
						if (collision.CheckCollision(*dzieci[i].getSprite(), *jaja[j].getSprite()) == true) // kolizja dziecko-jajo zbieranie informacji
						{
							dzieci[i].gatherInfo(jaja[j].getPosition());
							dzieci[i].kolizja();
						}
					}
					for (int j = 0; j < kasa.size(); j++)
					{
						if (collision.CheckCollision(*dzieci[i].getSprite(), *kasa[j].getSprite()) == true) //kolizja dziecko-kasa
						{
							dzieci[i].kolizja();
						}
					for (int j = 0; j < stare.size(); j++)
						if (collision.CheckCollision(*dzieci[i].getSprite(), *stare[j].getSprite()) == true) //kolizja dziecko-stary
						{
							dzieci[i].kolizja();
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < stare.size(); i++)
	{
		stare[i].setSize(oldDPS); // zwiekszanie wieku doroslych 

		if (stare[i].isAsleep == false)
		{

			if (stare[i].updateMove(*stare[i].getSprite()) == 1) //poruszanie doroslymi, jezeli zostala zwrocona jedynka, to dodaje do gniazda jedzenie (bo zostalo odniesione jajko)
			{
				gniazdo->setMoney(1);
			}

			if (collision.CheckCollision(*stare[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dorosly gniazdo
			{
				stare[i].kolizja();
			}

			for (int k = 0; k < dorosli.size(); k++) //kolizja dorosly - stary
			{
				if (collision.CheckCollision(*stare[i].getSprite(), *dorosli[k].getSprite()) == true)
				{
					if (dorosli[k].collectedInfo == true && stare[i].flagaKolizja == true)
					{
						stare[i].goGetIt(dorosli[k].itemPosition);
						dorosli[k].collectedInfo = false;
						dorosli[k].kolizja();
					}
					else
					{
						stare[i].kolizja();
						dorosli[k].kolizja();
					}
				}
			}



			for (int l = 0; l < kasa.size(); l++) //kolizja stary - kasa
			{
				if (collision.CheckCollision(*stare[i].getSprite(), *kasa[l].getSprite()) == true)
				{
					if (stare[i].flagaKolizja == true)
					{
						if (kasa[l].flaga == false)
						{
							stare[i].loadCoinTexture();
							stare[i].collect();
							kasa.erase(kasa.begin() + l);
							l -= l;
						}
						break;
					}
					if (stare[i].flagaKolizja == false && stare[i].goToEgg == true)
					{
						std::cout << "mucha zrezygnowala z pojscia po COIN i wziela pierwsze po drodze" << std::endl;
						stare[i].loadCoinTexture();
						stare[i].instrukcja = 0;
						stare[i].goToEgg = false;
						stare[i].collect();
						kasa.erase(kasa.begin() + l);
						l -= l;
					}

				}
			}
			for (int j = 0; j < stare.size() - 1; j++)
			{
				if (i != j)
				{
					if (collision.CheckCollision(*stare[i].getSprite(), *stare[j].getSprite()) == true) //sprawdzanie kolizji dorosly - dorosly
					{
						stare[i].kolizja();
					}
				}
			}
		}
	}
	countTime();
}
}

void PlayState::Draw()
{
	for (int i = 0; i < stare.size(); i++)
	{
		stare[i].draw(*window);
	}
	for (int i = 0; i < dorosli.size(); i++) 
	{
		dorosli[i].draw(*window);
	}
	for (int i = 0; i < dzieci.size(); i++) {
		dzieci[i].draw(*window);
	}
	for (int i = 0; i < jaja.size(); i++) {
		jaja[i].draw(*window);
	}
	for (int i = 0; i < kasa.size(); i++) {
		kasa[i].draw(*window);
	}

	gniazdo->draw(*window);
	menu->draw(*window);
}


int PlayState::countTime()
{
	dt++;
	return dt;
}

void PlayState::evolution()
{
	float iks = 0;
	float igrek = 0;

	for (int i = 0; i < dzieci.size(); i++) {

		if (dzieci[i].life <= (kidLife * 0.3) && dzieci[i].flagaKolizja == true)
		{
			dzieci[i].sleep(dt);
		}

		//check to wakeUp

		if (dzieci[i].getSize() == dzieci[i].wakeUp && dzieci[i].isAsleep == true) //wybudza dzieci ze snu XD
		{
			if (gniazdo->getNestFood() >= 10)
			{
				gniazdo->setNestFood(-10);
				dzieci[i].life = 100; //ustawienie zycia na 100
			}

			dzieci[i].isAsleep = false; //zdjecie flagi ze mucha spi
			dzieci[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			dzieci[i].setPosition(sf::Vector2f(512,520)); // ustawia muche w podanym miejscu po snie
		}


		if (dzieci[i].getSize() > 1800) //ewolucja muchy mlodej
		{
			iks = (dzieci[i].getPosition()).x;
			igrek = (dzieci[i].getPosition()).y;

			Mature *mature;
			mature = new Mature(*assets,sf::Vector2f(iks, igrek), matureLife);
			dorosli.push_back(*mature);
			dzieci.erase(dzieci.begin() + i);

			iks = 0;
			igrek = 0;
		}
	}

	for (int i = 0; i < dorosli.size(); i++)
	{
		if (dorosli[i].life <= (matureLife*0.25) && dorosli[i].flagaKolizja == true)
		{
			dorosli[i].goToSleep = true;
			dorosli[i].sleep(dt);
		}
		if (dorosli[i].getSize() == dorosli[i].wakeUp && dorosli[i].isAsleep == true)
		{
			if (gniazdo->getNestFood() >= 20)
			{
				gniazdo->setNestFood(-20);
				dorosli[i].life = 200;
			}

			dorosli[i].isAsleep = false; //zdjecie flagi ze mucha spi
			dorosli[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			dorosli[i].setPosition(sf::Vector2f(512, 520)); // ustawia muche w podanym miejscu po snie
		}
		if (dorosli[i].getSize() > 3600) //ewolucja muchy MATURE
		{
			iks = (dorosli[i].getPosition()).x;
			igrek = (dorosli[i].getPosition()).y;

			Old *old;
			old = new Old(*assets, sf::Vector2f(iks, igrek), oldLife);
			stare.push_back(*old);
			dorosli.erase(dorosli.begin() + i);

			iks = 0;
			igrek = 0;
		}
	}

	for (int i = 0; i < stare.size(); i++)
	{
		if (stare[i].getSize() > 5400) //smierc najstarszej muchy!
		{
			stare.erase(stare.begin() + i);
			i--;
		}
		if (stare[i].life <= (oldLife*0.26) && stare[i].flagaKolizja == true)
		{
			stare[i].goToSleep = true;
			stare[i].sleep(dt);
		}
		if (stare[i].getSize() == stare[i].wakeUp && stare[i].givingBirth == false && stare[i].isAsleep == true)
		{
			if (gniazdo->getNestFood() >= 15)
			{
				gniazdo->setNestFood(-15);
				stare[i].life = 300;
			}

			stare[i].isAsleep = false; //zdjecie flagi ze mucha spi
			stare[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			stare[i].setPosition(sf::Vector2f(512, 520)); // ustawia muche w podanym miejscu po snie
		}

		if (stare[i].getSize() % 1800 == 0 && stare[i].getSize() > 0 && stare[i].givingBirth == false)
		{
			float x = stare[i].getPosition().x;
			float y = stare[i].getPosition().y;
			stare[i].givingBirth = true;
			stare[i].isAsleep = true;
			stare[i].flagaKolizja = false;
			stare[i].wakeUp = stare[i].getSize() + 150;
			for (i = 0; i < kidAmmount; i++)
			{
				Kid *kid;
				kid = new Kid(*assets, sf::Vector2f(x+rand()%5,y+rand()%5), kidLife);
				dzieci.push_back(*kid);
			}
		}
		if (stare[i].getSize() == stare[i].wakeUp && stare[i].givingBirth == true)
		{
			if (stare[i].carryItem == false)
			{
				stare[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			}
			stare[i].givingBirth = false;
			stare[i].isAsleep = false; //zdjecie flagi ze mucha spi
			
		}
	}
}

void PlayState::cleanUp()
{

	for (int i = 0; i < dzieci.size(); i++)
	{
		if (dzieci[i].isDead == true)
		{
			dzieci.erase(dzieci.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < dorosli.size(); i++)
	{
		if (dorosli[i].isDead == true)
		{
			dorosli.erase(dorosli.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < stare.size(); i++)
	{
		if (stare[i].isDead == true)
		{
			stare.erase(stare.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < jaja.size(); i++)
	{
		if (jaja[i].getSize() == 900)
		{
			jaja.erase(jaja.begin() + i);
			i--;
		}
		else jaja[i].setSize(); //increase egg size by 1 on every update of the simulation
	}

	for (int i = 0; i < kasa.size(); i++)
	{
		if (kasa[i].getSize() == 900)
		{
			kasa.erase(kasa.begin() + i);
			i--;
		}
		else kasa[i].setSize();
	}
}

void PlayState::randomGen()
{
	if (dorosli.size() > 0)
	{
		if (dt % eggTR == 0)
		{
			Egg *egg;
			egg = new Egg(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
			jaja.push_back(*egg);
		}
	}

	if (stare.size() > 0)
	{
		if (dt % coinTR == 0)
		{
			Coin *coin;
			coin = new Coin(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
			kasa.push_back(*coin);
		}
	}
}