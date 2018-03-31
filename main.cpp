/*!
* \file
* \brief Funkcja głowna
*
* Plik zawiera fukcję głowna programu
*
*/
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Klasy.hpp"

#define MAX_NUMBER_OF_ITEMS 12

using namespace sf;
using namespace std;

/*!
*@brief Funkcja głowna
*   Funkcja tworzy obiekt typu gra, okno o nazwie menu glowne oraz obiekt typu texture za pomocą ktorego laduje obrazek z folderu
*   images, nastepnie do obiektu typu Sprite przekazywany jest ten obrazek poprzez obiekt t1 jako parametr. Nastepnie tworzony
*   jest obiekt typu Menu o nazwie menu do ktorego sa przekazywane dwa parametry oznaczajace wysokosc i szerokosc wygenerowanego okna.
*   Petla while bedzie sie wykonywac tak dlugo dopoki okno bedzie otwarte. Wewnatrz ma miejsce deklaracja obiektu typu Event o nazwie event,
*   ktory słuzy do obslugi zdarzen. Nastepnie za pomocą instrukcji switch sprawdzane jest czy uzytkownik nacisnal przycisk gora czy dol.
*   Jezeli nacisnal odpowiednio ktorys z tych przyciskow to wywolywane sa metody o nazwach ruch_gora() lub ruch_dol(), co umozliwia
*   przemieszczanie sie po utworzonym menu. Nastepnie mamy kolejną instrukcje switch sprawdzajaca czy klawisz zostal wcisniety za pomoca
*   wywolania metody klawisz_zostal_wcisniety() z klasy menu. Teraz w zaleznosci od tego ktora opcje w menu wybral uzytkownik zostanie
*   uruchomiona gra, instrukcja poruszania sie bierek, lub gra zostanie zamknieta.
*@return Funkcja niczego nie zwraca
*/
int main(void)
{

	Game g1;
    sf::RenderWindow window(sf::VideoMode(504, 504), "Menu Glowne");
    sf::Texture t1;

    t1.loadFromFile("images/menu1.png");
    sf::Sprite menu1 (t1);

	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
        while (window.pollEvent(event))
		{
			switch (event.type)
			{
                case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.ruch_gora();
					break;

				case sf::Keyboard::Down:
					menu.ruch_dol();
					break;

				case sf::Keyboard::Return:
					switch (menu.klawisz_zostal_wcisniety())
					{
					case 0:
					    window.close();
					    g1.gra();
						break;
                    case 1:
						 menu.instrukcja(window.getSize().x, window.getSize().y);
                            switch(menu.klawisz_zostal_wcisniety())
                                case 12: g1.gra(); break;

                    break;
					case 2:
						window.close();
						break;
					}
                        break;
				}

				break;
			case sf::Event::Closed:
				window.close();
                break;
                }

        }
		window.clear();
        window.draw(menu1);
        menu.rysuj(window);
		window.display();
	}

    return 0;
}



