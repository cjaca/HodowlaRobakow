#include "PlayState.h"
#include <cstdlib>
#include <ctime>
#include <time.h>

PlayState::PlayState(sf::RenderWindow * window)
{
	this->window = window;
	this->state = state;
}

PlayState::~PlayState()
{
}

void PlayState::Init()
{
	assets = new AssetManager();
	
	srand(time(NULL));
	assets->Load_Texture("kid", KIDFLY_FILEPATH);
	assets->Load_Texture("fly-mature", MATUREFLY_FILEPATH);
	assets->Load_Texture("fly-egg", MATUREFLYEGG_FILEPATH);
	assets->Load_Texture("fly-old", OLDFLY_FILEPATH);
	assets->Load_Texture("nest", NEST_FILEPATH);
	assets->Load_Texture("egg", EGG_FILEPATH);
	assets->Load_Texture("coin", COIN_FILEPATH);
	assets->Load_Texture("fly-coin", FLYCOIN_FILEPATH);
	assets->Load_Texture("plus", PLUS_FILEPATH);
	assets->Load_Texture("minus", MINUS_FILEPATH);
	assets->Load_Texture("pause", BTNPAUSE_FILEPATH);
	assets->Load_Texture("start", BTNSTART_FILEPATH);
	assets->Load_Texture("gen", BTNGEN_FILEPATH);
	assets->LoadFont("trebu", TREBU_FILEPATH);

	menu = new Menu(*assets);
	gniazdo = new Nest(*assets);
}

void PlayState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) window->close();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 1; i < 31; i++)
			{
				menu->getSprite(i)->getPosition().x;
				sf::IntRect tempRect(menu->getSprite(i)->getPosition().x, menu->getSprite(i)->getPosition().y, menu->getSprite(i)->getGlobalBounds().width, menu->getSprite(i)->getGlobalBounds().height);
				if (tempRect.contains(sf::Mouse::getPosition(*window)))
				{
					if (i == 1)
					{
						std::cout << "Dodano kid muche" << std::endl;
						Kid *kid;
						kid = new Kid(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Kid_Life);
						v_Kids.push_back(*kid);
					}
					if (i == 2)
					{
						if (v_Kids.size() > 0) {
							v_Kids.erase(v_Kids.begin());
						}
					}
					if (i == 3)
					{
						std::cout << "Dodano dorosla muche" << std::endl;
						Mature *mature;
						mature = new Mature(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Mature_Life);
						v_Mature.push_back(*mature);
					}
					if (i == 4)
					{
						if (v_Mature.size() > 0) {
							v_Mature.erase(v_Mature.begin());
						}
					}
					if (i == 5)
					{
						std::cout << "Dodano starsza muche" << std::endl;
						Old *old;
						old = new Old(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Old_Life);
						v_Old.push_back(*old);
					}
					if (i == 6)
					{
						if (v_Old.size() > 0) {
							v_Old.erase(v_Old.begin());
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
						m_Kid_Ammount += 1;
					}
					if (i == 12)
					{
						if (m_Kid_Ammount > 0) {
							m_Kid_Ammount -= 1;
						}
					}
					if (i == 13)
					{
						std::cout << "Zmniejszono przezywalnosc mlodej muchy" << std::endl;
						m_Kid_DPS += 0.02;
					}
					if (i == 14)
					{
						if (m_Kid_DPS > 0.02) {
							m_Kid_DPS -= 0.02;
						}
					}
					if (i == 15)
					{
						std::cout << "Zmniejszono przezywalnosc doroslej muchy" << std::endl;
						m_Mature_DPS += 0.02;
					}
					if (i == 16)
					{
						if (m_Mature_DPS > 0.02) {
							m_Mature_DPS -= 0.02;
						}
						else std::cout << "nie mozna juz zmniejszyc przezywalnosci muchy" << std::endl;
					}
					if (i == 17)
					{
						std::cout << "Zmniejszono przezywalnosc starszej muchy" << std::endl;
						m_Old_DPS += 0.02;
					}
					if (i == 18)
					{
						if (m_Old_DPS > 0.02) {
							m_Old_DPS -= 0.02;
						}
						else std::cout << "nie mozna juz zmniejszyc przezywalnosci muchy" << std::endl;
					}
					if (i == 19)
					{
						std::cout << "Zwiekszono czas respawnu monetek o sekunde" << std::endl;
						m_Coin_Time_Respawn += 30;
					}
					if (i == 20)
					{
						if (m_Coin_Time_Respawn > 30) {
							m_Coin_Time_Respawn -= 30;
						}
					}
					if (i == 21)
					{
						std::cout << "Zwiekszono czas respawnu jajek o sekunde" << std::endl;
						m_Egg_Time_Respawn += 30;
					}
					if (i == 22)
					{
						if (m_Egg_Time_Respawn > 30) {
							m_Egg_Time_Respawn -= 30;
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
						m_Kid_Life +=1;
					}
					if (i == 25)
					{
						m_Kid_Life-=1;
					}
					if (i == 26)
					{
						std::cout<<"zwiekszono zycie doroslej muchy"<<std::endl;
						m_Mature_Life +=1;
					}
					if (i == 27)
					{
						m_Mature_Life -=1;
					}
					if (i == 28)
					{
						std::cout<<"zwiekszono zycie starszej muchy"<<std::endl;
						m_Old_Life +=1;
					}
					if (i == 29)
					{
						m_Old_Life -=1;
					}
					if (i == 30)
					{
						std::cout << "generowanie" << std::endl;
						Generate();
					}
				}
			}
		}
	}
}



void PlayState::Update()
{
	menu->showTimer(this->m_dt);
	menu->showTotalFly(v_Kids.size()+ v_Mature.size()+ v_Old.size());
	menu->showKidFly(v_Kids.size());
	menu->showMatureFly(v_Mature.size());
	menu->showOldFly(v_Old.size());
	menu->showNestAttributes(gniazdo->getNestFood());
	menu->showNestMoney(gniazdo->getMoney());
	menu->showKidRespAmmount(m_Kid_Ammount);
	menu->showKidDps(m_Kid_DPS*50);
	menu->showMatureDps(m_Mature_DPS*50);
	menu->showOldDps(m_Old_DPS*50);
	menu->showCoinResp(m_Coin_Time_Respawn);
	menu->showEggResp(m_Egg_Time_Respawn);
	menu->buttonPause(pause);
	menu->showKidLife(m_Kid_Life);
	menu->showMatureLife(m_Mature_Life);
	menu->showOldLife(m_Old_Life);
	if (pause == false)
	{
	Evolution(); //sprawdzanie ewolucji much
	RandomGen(); //tworzenie nowych jajek i monetek na mapie
	CleanUp(); //sprzatanie zmarlych much
	if (v_Mature.size() > 0)
	{
		for (int i = 0; i < v_Mature.size(); i++)
		{
			v_Mature[i].setSize(m_Mature_DPS); // zwiekszanie wieku doroslych much

			if (v_Mature[i].isAsleep == false)
			{
				v_Mature[i].Update_Move();//poruszanie doroslymi
				if (v_Mature[i].m_Mission_Complete == true) //dodaje do gniazda jedzenie (bo zostalo odniesione jajko)
				{
					gniazdo->setNestFood(200);
					v_Mature[i].m_Mission_Complete = false;
				}

				if (collision.CheckCollision(*v_Mature[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dorosly gniazdo
				{
					v_Mature[i].kolizja();
				}

				for (int k = 0; k < v_Kids.size(); k++) //kolizja dorosly - dziecko
				{
					if (collision.CheckCollision(*v_Mature[i].getSprite(), *v_Kids[k].getSprite()) == true)
					{
						if (v_Kids[k].collectedInfo == true && v_Mature[i].flagaKolizja == true)
						{
							v_Mature[i].Go_Get_It(v_Kids[k].itemPosition);
							v_Kids[k].collectedInfo = false;
							v_Kids[k].kolizja();
						}
						else
						{
							v_Mature[i].kolizja();
							v_Kids[k].kolizja();
						}

					}
				}

				for (int l = 0; l < v_Eggs.size(); l++) //kolizja dorosly - jajko
				{
					if (collision.CheckCollision(*v_Mature[i].getSprite(), *v_Eggs[l].getSprite()) == true)
					{
						if (v_Mature[i].flagaKolizja == true)
						{
							if (v_Eggs[l].flaga == false) 
							{
								v_Mature[i].Collect();
								v_Eggs.erase(v_Eggs.begin() + l);
								l -= l;
							}
							break;
						}
						if (v_Mature[i].flagaKolizja == false && v_Mature[i].m_Go_To_Egg == true)
						{
							v_Mature[i].instrukcja = 0;
							v_Mature[i].m_Go_To_Egg = false;
							v_Mature[i].Collect();
							v_Eggs.erase(v_Eggs.begin() + l);
							l -= l;
						}

					}
				}
				for (int j = 0; j < v_Coins.size(); j++) // kolizja dorosly-v_Coins, zbieranie informacji
				{
					if (collision.CheckCollision(*v_Mature[i].getSprite(), *v_Coins[j].getSprite()) == true)
					{
						if (v_Mature[i].collectedInfo == false)
						{
							v_Mature[i].gatherInfo(v_Coins[j].getPosition());
							v_Mature[i].kolizja();
						}
						else
						{
							v_Mature[i].kolizja();
						}
					}
				}
				for (int j = 0; j < v_Mature.size() - 1; j++)
				{
					if (i != j)
					{
						if (collision.CheckCollision(*v_Mature[i].getSprite(), *v_Mature[j].getSprite()) == true) //sprawdzanie kolizji dorosly - dorosly
						{
							v_Mature[i].kolizja();
						}
					}
				}
			}
		}
	}

	if (v_Kids.size() > 0)
	{
		for (int i = 0; i < v_Kids.size(); i++)
		{
			v_Kids[i].setSize(m_Kid_DPS); //zwiekszanie ich wieku
			if (v_Kids[i].isAsleep == false)
			{
				v_Kids[i].Update_Move(*v_Kids[i].getSprite()); //poruszanie dziecmi

				if (v_Kids[i].flagaKolizja == true)
				{
					for (int j = 0; j < v_Kids.size() - 1; j++)
					{
						if (i != j)
						{
							if (collision.CheckCollision(*v_Kids[i].getSprite(), *v_Kids[j].getSprite()) == true) // kolizja v_Kids-v_Kids
							{
								v_Kids[i].kolizja();
							}
						}
					}
					if (collision.CheckCollision(*v_Kids[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dziecko-gniazdo
					{
						v_Kids[i].kolizja();
					}
					for (int j = 0; j < v_Eggs.size(); j++)
					{
						if (collision.CheckCollision(*v_Kids[i].getSprite(), *v_Eggs[j].getSprite()) == true) // kolizja dziecko-jajo zbieranie informacji
						{
							if (v_Kids[i].collectedInfo == false)
							{
								v_Kids[i].gatherInfo(v_Eggs[j].getPosition());
								v_Kids[i].kolizja();
							}
							else
							{
								v_Kids[i].kolizja();
							}
						}
					}
					for (int j = 0; j < v_Coins.size(); j++)
					{
						if (collision.CheckCollision(*v_Kids[i].getSprite(), *v_Coins[j].getSprite()) == true) //kolizja dziecko-v_Coins
						{
							v_Kids[i].kolizja();
						}
					}
					for (int j = 0; j < v_Old.size(); j++)
					{
						if (collision.CheckCollision(*v_Kids[i].getSprite(), *v_Old[j].getSprite()) == true) //kolizja dziecko-stary
						{
							v_Kids[i].kolizja();
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < v_Old.size(); i++)
	{
		v_Old[i].setSize(m_Old_DPS); // zwiekszanie wieku doroslych 

		if (v_Old[i].isAsleep == false)
		{
			v_Old[i].Update_Move(*v_Old[i].getSprite());

			if (v_Old[i].m_Mission_Complete == true) //poruszanie doroslymi, jezeli zostala zwrocona jedynka, to dodaje do gniazda jedzenie (bo zostalo odniesione jajko)
			{
				gniazdo->setMoney(1);
				v_Old[i].m_Mission_Complete = false;
			}
			if (collision.CheckCollision(*v_Old[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja starsza-gniazdo
			{
				v_Old[i].kolizja();
			}
			for (int k = 0; k < v_Mature.size(); k++) //kolizja starszy-dorosly
			{
				if (collision.CheckCollision(*v_Old[i].getSprite(), *v_Mature[k].getSprite()) == true)
				{
					if (v_Mature[k].collectedInfo == true && v_Old[i].flagaKolizja == true)
					{
						v_Old[i].Go_Get_It(v_Mature[k].itemPosition);
						v_Mature[k].collectedInfo = false;
						v_Mature[k].kolizja();
					}
					else
					{
						v_Old[i].kolizja();
						v_Mature[k].kolizja();
					}
				}
			}
			for (int k = 0; k < v_Eggs.size(); k++) //kolizja stary - v_Eggs
			{
				if (collision.CheckCollision(*v_Old[i].getSprite(), *v_Eggs[k].getSprite()) == true)
				{
						v_Old[i].kolizja();
				}
			}

			for (int l = 0; l < v_Coins.size(); l++) //kolizja stary - v_Coins
			{
				if (collision.CheckCollision(*v_Old[i].getSprite(), *v_Coins[l].getSprite()) == true)
				{
					if (v_Old[i].flagaKolizja == true)
					{
						if (v_Coins[l].flaga == false)
						{
							v_Old[i].loadCoinTexture();
							v_Old[i].Collect();
							v_Coins.erase(v_Coins.begin() + l);
							l -= l;
						}
						break;
					}
					if (v_Old[i].flagaKolizja == false && v_Old[i].m_Go_To_Egg == true)
					{
						v_Old[i].loadCoinTexture();
						v_Old[i].instrukcja = 0;
						v_Old[i].m_Go_To_Egg = false;
						v_Old[i].Collect();
						v_Coins.erase(v_Coins.begin() + l);
						l -= l;
					}

				}
			}
			for (int j = 0; j < v_Old.size() - 1; j++)
			{
				if (i != j)
				{
					if (collision.CheckCollision(*v_Old[i].getSprite(), *v_Old[j].getSprite()) == true) //sprawdzanie kolizji starsza-starsza
					{
						v_Old[i].kolizja();
					}
				}
			}
		}
	}
	CountTime();
	}
}

void PlayState::Draw()
{
	for (int i = 0; i < v_Old.size(); i++)
	{
		v_Old[i].draw(*window);
	}
	for (int i = 0; i < v_Mature.size(); i++) 
	{
		v_Mature[i].draw(*window);
	}
	for (int i = 0; i < v_Kids.size(); i++) {
		v_Kids[i].draw(*window);
	}
	for (int i = 0; i < v_Eggs.size(); i++) {
		v_Eggs[i].draw(*window);
	}
	for (int i = 0; i < v_Coins.size(); i++) {
		v_Coins[i].draw(*window);
	}

	gniazdo->draw(*window);
	menu->draw(*window);
}


int PlayState::CountTime()
{
	m_dt++;
	return m_dt;
}

void PlayState::Evolution()
{
	for (int i = 0; i < v_Kids.size(); i++) 
	{

		if (v_Kids[i].life <= (m_Kid_Life * 0.3) && v_Kids[i].flagaKolizja == true)
		{
			v_Kids[i].sleep(m_dt);
		}

		if (v_Kids[i].getSize() == v_Kids[i].wakeUp && v_Kids[i].isAsleep == true) //wybudza v_Kids ze snu
		{
			if (gniazdo->getNestFood() >= 10)
			{
				gniazdo->setNestFood(-10);
				v_Kids[i].life = m_Kid_Life; //ustawienie zycia na 100
			}
			v_Kids[i].isAsleep = false; //zdjecie flagi ze mucha spi
			v_Kids[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			v_Kids[i].Random_Respawn_Position();
		}
		if (v_Kids[i].getSize() > 1800) //ewolucja muchy mlodej
		{
			Mature *mature;
			mature = new Mature(*assets,sf::Vector2f((v_Kids[i].getPosition()).x, (v_Kids[i].getPosition()).y), m_Mature_Life);
			v_Mature.push_back(*mature);
			v_Kids.erase(v_Kids.begin() + i);
		}
	}

	for (int i = 0; i < v_Mature.size(); i++)
	{
		if (v_Mature[i].life <= (m_Mature_Life*0.25) && v_Mature[i].flagaKolizja == true)
		{
			v_Mature[i].m_Go_To_Sleep = true;
			v_Mature[i].sleep(m_dt);
		}
		if (v_Mature[i].getSize() == v_Mature[i].wakeUp && v_Mature[i].isAsleep == true)
		{
			if (gniazdo->getNestFood() >= 20)
			{
				gniazdo->setNestFood(-20);
				v_Mature[i].life = m_Mature_Life;
			}

			v_Mature[i].isAsleep = false; //zdjecie flagi ze mucha spi
			v_Mature[i].flagaKolizja = true; //nadanie flagi ze mucha musi sie juz odbijac od otoczenia
			v_Mature[i].Random_Respawn_Position();
		}
		if (v_Mature[i].getSize() > 3600) //ewolucja muchy MATURE
		{
			Old *old;
			old = new Old(*assets, sf::Vector2f((v_Mature[i].getPosition()).x, (v_Mature[i].getPosition()).y), m_Old_Life);
			v_Old.push_back(*old);
			v_Mature.erase(v_Mature.begin() + i);
		}
	}

	for (int i = 0; i < v_Old.size(); i++)
	{
		if (v_Old[i].getSize() > 5400) //smierc najstarszej muchy!
		{
			v_Old.erase(v_Old.begin() + i);
			i--;
		}
		if (v_Old[i].life <= (m_Old_Life*0.26) && v_Old[i].flagaKolizja == true)
		{
			v_Old[i].m_Go_To_Sleep = true;
			v_Old[i].sleep(m_dt);
		}
		if (v_Old[i].getSize() == v_Old[i].wakeUp && v_Old[i].givingBirth == false && v_Old[i].isAsleep == true)
		{
			if (gniazdo->getNestFood() >= 15)
			{
				gniazdo->setNestFood(-15);
				v_Old[i].life = m_Old_Life;
			}

			v_Old[i].isAsleep = false; 
			v_Old[i].flagaKolizja = true; 
			v_Old[i].Random_Respawn_Position();
		}

		if (v_Old[i].getSize() % 1800 == 0 && v_Old[i].getSize() > 0 && v_Old[i].givingBirth == false)
		{
			float x = v_Old[i].getPosition().x;
			float y = v_Old[i].getPosition().y;
			v_Old[i].givingBirth = true;
			v_Old[i].isAsleep = true;
			v_Old[i].flagaKolizja = false;
			v_Old[i].wakeUp = v_Old[i].getSize() + 150;
			for (i = 0; i < m_Kid_Ammount; i++)
			{
				Kid *kid;
				kid = new Kid(*assets, sf::Vector2f(x+rand()%5,y+rand()%5), m_Kid_Life);
				v_Kids.push_back(*kid);
			}
		}
		if (v_Old[i].getSize() == v_Old[i].wakeUp && v_Old[i].givingBirth == true)
		{
			if (v_Old[i].m_Carry_Item == false)
			{
				v_Old[i].flagaKolizja = true; 
			}
			v_Old[i].givingBirth = false;
			v_Old[i].isAsleep = false; 
			
		}
	}
}

void PlayState::CleanUp()
{

	for (int i = 0; i < v_Kids.size(); i++)
	{
		if (v_Kids[i].isDead == true)
		{
			v_Kids.erase(v_Kids.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < v_Mature.size(); i++)
	{
		if (v_Mature[i].isDead == true)
		{
			v_Mature.erase(v_Mature.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < v_Old.size(); i++)
	{
		if (v_Old[i].isDead == true)
		{
			v_Old.erase(v_Old.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < v_Eggs.size(); i++)
	{
		if (v_Eggs[i].getSize() == 900)
		{
			v_Eggs.erase(v_Eggs.begin() + i);
			i--;
		}
		else v_Eggs[i].setSize();
	}

	for (int i = 0; i < v_Coins.size(); i++)
	{
		if (v_Coins[i].getSize() == 900)
		{
			v_Coins.erase(v_Coins.begin() + i);
			i--;
		}
		else v_Coins[i].setSize();
	}
}

void PlayState::RandomGen()
{
	if (v_Mature.size() > 0)
	{
		if (m_dt % m_Egg_Time_Respawn == 0)
		{
			Egg *egg;
			egg = new Egg(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
			v_Eggs.push_back(*egg);
		}
	}

	if (v_Old.size() > 0)
	{
		if (m_dt % m_Coin_Time_Respawn == 0)
		{
			Coin *coin;
			coin = new Coin(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
			v_Coins.push_back(*coin);
		}
	}
}

void PlayState::Generate()
{
	for (int i=0; i < rand() % 10; i++)
	{
		Mature *mature;
		mature = new Mature(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Mature_Life);
		v_Mature.push_back(*mature);
	}
	for (int i = 0; i < rand() % 10; i++)
	{
		Kid *kid;
		kid = new Kid(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Kid_Life);
		v_Kids.push_back(*kid);
	}
	for (int i = 0; i < rand() % 10; i++)
	{
		Old *old;
		old = new Old(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT), m_Old_Life);
		v_Old.push_back(*old);
	}
	for (int i = 0; i < rand() % 5; i++)
	{
		Egg *egg;
		egg = new Egg(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		v_Eggs.push_back(*egg);
	}

	for (int i = 0; i < rand() % 5; i++)
	{
		Coin *coin;
		coin = new Coin(*assets, sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
		v_Coins.push_back(*coin);
	}
}
