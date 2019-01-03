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
	srand(time(NULL));

	for (int i = 0; i < iloscMuch; i++)
	{
		Mature *mature;
		Kid *kid;
		Egg *egg;
		mature = new Mature(sf::Vector2f(rand() % 800, rand() % 600));
		kid = new Kid(sf::Vector2f(rand() % 800, rand() % 600));
		egg = new Egg(sf::Vector2f(rand() % 700, rand() % 500));
		dorosli.push_back(*mature);
		dzieci.push_back(*kid);
		jaja.push_back(*egg);
	}
	menu = new Menu();
	gniazdo = new Nest();


}

void PlayState::HandleInput()
{
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) window->close();


		if (event.type == sf::Event::KeyPressed) {

			switch (event.key.code) {

			case sf::Keyboard::Escape: window->close(); break;


			case sf::Keyboard::Space:
				std::cout << "Dodano kid muche" << std::endl;
				Kid *kid;
				kid = new Kid(sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
				dzieci.push_back(*kid);
				break;
			case sf::Keyboard::X:
				if (dorosli.size() > 0) {
					std::cout << "Usunieto jedna dorosla muche" << std::endl;
					dorosli.erase(dorosli.begin());
					std::cout << dorosli.size() << std::endl;
				}
				else std::cout << "Nie ma juz much do usuniecia" << std::endl;
				break;
			case sf::Keyboard::E:
				std::cout << "Dodano jajko" << std::endl;
				Egg *egg;
				egg = new Egg(sf::Vector2f(rand() % RESPAWN_WIDTH, rand() % RESPAWN_HEIGHT));
				jaja.push_back(*egg);
				break;
			case sf::Keyboard::D:
				if (jaja.size() > 0) {
					std::cout << "usunieto jajo" << std::endl;
					jaja.erase(jaja.begin());
				}
				else std::cout << "Nie ma juz jaj do usuniecia" << std::endl;
				break;
			}
		}
	}




}

void PlayState::Update()
{
	menu->showTimer(this->dt);
	menu->showTotalFly(IloscMuch());
	menu->showKidFly(dzieci.size());
	menu->showMatureFly(dorosli.size());
	menu->showNestAttributes(gniazdo->getNestFood());
	evolution(); //sprawdzanie ewolucji malej muchy
	randomGen();
	//cleanUp(); //sprzatanie doniesionych jaj
	if (dorosli.size() > 0)
	{
		for (int i = 0; i < dorosli.size(); i++)
		{
			if (dorosli[i].updateMove(*dorosli[i].getSprite()) == 1) //poruszanie doroslymi, jezeli zostala zwrocona jedynka, to dodaje do gniazda jedzenie (bo zostalo odniesione jajko)
			{
				gniazdo->setNestFood(30);
			}
			dorosli[i].setSize(); // zwiekszanie wieku doroslych 

				//dorosli[i].kolizja(*gniazdo->getSprite()); //sprawdzanie kolizji dorosly-gniazdo
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
 							dorosli[i].goGetIt(dzieci[k].eggPosition);
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
							if (jaja[l].flaga == false) {
								dorosli[i].collect();
								jaja.erase(jaja.begin() + l);
								l -= l;
							}
							break;
						}

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

	if (dzieci.size() > 0)
	{
		for (int i = 0; i < dzieci.size(); i++)
		{
			dzieci[i].setSize(); //zwiekszanie ich wieku
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
						if (collision.CheckCollision(*dzieci[i].getSprite(), *jaja[j].getSprite()) == true) // kolizja dziecko-gniazdo
						{
							dzieci[i].gatherInfo(jaja[j].getPosition());
							dzieci[i].kolizja();
						}
					}
				}
			}
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
	countTime();


}

void PlayState::Draw()
{
	if (dorosli.size() > 0) {
		for (int i = 0; i < dorosli.size(); i++) {
			dorosli[i].draw(*window);
		}
	}
	for (int i = 0; i < dzieci.size(); i++) {
		dzieci[i].draw(*window);
	}
	for (int i = 0; i < jaja.size(); i++) {
		jaja[i].draw(*window);
	}

	gniazdo->draw(*window);
	menu->draw(*window);

}

int PlayState::IloscMuch()
{
	int iloscDzieci = dzieci.size();
	int iloscDoroslych = dorosli.size();
	iloscMuch = iloscDzieci + iloscDoroslych;
	return iloscMuch;
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


		if (dzieci[i].getSize() % 900 == 0 && dzieci[i].getSize() < 4301 && dzieci[i].getSize() > 1)
		{
			dzieci[i].sleep(dt);
		}

		//check to wakeUp

		if (dzieci[i].getSize() == dzieci[i].wakeUp) //wybudza dzieci ze snu XD
		{
			dzieci[i].isAsleep = false;
			dzieci[i].setPosition(sf::Vector2f(512,520)); // ustawia muche w podanym miejscu po snie
		}
		if (dzieci[i].getSize() > 5000) {
			iks = (dzieci[i].getPosition()).x;
			igrek = (dzieci[i].getPosition()).y;

			Mature *mature;
			mature = new Mature(sf::Vector2f(iks, igrek));
			dorosli.push_back(*mature);
			dzieci.erase(dzieci.begin() + i);

			iks = 0;
			igrek = 0;
		}
	}
}

void PlayState::cleanUp()
{
	for (int i = 0; i < jaja.size(); i++) {
		if (jaja[i].doZniszczenia == true) {
			jaja.erase(jaja.begin() + i);
			i--;
		}
	}
}

void PlayState::randomGen()
{
	if (dt % 300 == 0)
	{
		Egg *egg;
		egg = new Egg(sf::Vector2f(rand() % 700, rand() % 500));
		jaja.push_back(*egg);
	}
}