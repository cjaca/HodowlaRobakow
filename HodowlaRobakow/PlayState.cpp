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
				kid = new Kid(sf::Vector2f(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT));
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
	evolution(); //sprawdzanie ewolucji malej muchy
	//randomGen();
	//cleanUp(); //sprzatanie doniesionych jaj
	if(dorosli.size()>0)
	{
		for (int i = 0; i < dorosli.size(); i++) 
		{
			dorosli[i].updateMove(*dorosli[i].getSprite()); //poruszanie doroslymi
			dorosli[i].setSize(); // zwiekszanie wieku doroslych 

			if (dorosli[i].flagaKolizja == true)
			{
				//dorosli[i].kolizja(*gniazdo->getSprite()); //sprawdzanie kolizji dorosly-gniazdo
				if (collision.CheckCollision(*dorosli[i].getSprite(), *gniazdo->getSprite()) == true) // kolizja dorosly gniazdo
				{
					dorosli[i].kolizja();
				}

				for (int k = 0; k < dzieci.size(); k++) //kolizja dorosly - dziecko
				{
					if (collision.CheckCollision(*dorosli[i].getSprite(), *dzieci[k].getSprite()) == true)
					{
						dorosli[i].kolizja();
						dzieci[k].kolizja();
					}
				}

				for (int l = 0; l < jaja.size(); l++) //kolizja dorosly - jajko
				{
					if (collision.CheckCollision(*dorosli[i].getSprite(), *jaja[l].getSprite()) == true)
					{
						if (jaja[l].flaga == false) {
							dorosli[i].collect(jaja[l]);
						}
						break;
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
				}
			}
		}
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


		if (dzieci[i].getSize() % 1000 == 0 && dzieci[i].getSize() < 4001 && dzieci[i].getSize() > 1)
		{
			dzieci[i].sleep(dt);
		}

		//check to wakeUp

		if (dzieci[i].getSize() == dzieci[i].wakeUp)
		{
			dzieci[i].isAsleep = false;
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
			jaja.erase(jaja.begin()+i);
			i--;
		}
	}
}

void PlayState::randomGen()
{
	if (dt%300 == 0)
	{
		Egg *egg;
		egg = new Egg(sf::Vector2f(rand() % 700, rand() % 500));
		jaja.push_back(*egg);
	}
}
