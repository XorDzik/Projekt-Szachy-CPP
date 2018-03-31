#ifndef Klasy_hpp
#define Klasy_hpp

/*!
* \file
* \brief Definicja klas Game oraz Menu
*
* Plik zawiera definicje klasy Game, oraz definicje klasy Menu
*
*/
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 12

using namespace sf;
using namespace std;


/*!
* \brief Definicja klasy Game
*
*   Klasa sluzy do obslugi gry, wewnatrz znajduja sie metody umozliwiajace obsluge gry, w tym najwazniejsza z nich o nazwie gra()
*   w niej znajduje sie petla glowna gry.
*/

class Game
{
public:
/*!
** @brief Obliczanie pozycji bierek
*   Deklaracja metody toCheesNote()
* @param[in] jako parametr pobiera obiekt typu Vector2f
*
*/
    string toChessNote(Vector2f p);
/*!
** @brief toCoord
*   Deklaracja metody o nazwie toCoord
* @param[in] jako pierwszy parametr pobiera zmienna typu char o nazwie a
* @param[in] jako drugi parametr pobiera zmienna typu char o nazwie b
*
*/
    Vector2f toCoord(char a,char b);
/*!
** @brief Ruch
*   Deklaracja metody o nazwie move()
* @param[in] jako parametr pobiera zmienna typu string o nazwie str
*
*/
    void move(string str);
/*!
** @brief Wczytywanie pozycji
*   Deklaracja metody o nazwie wczytaj_pozycje()
*
*/
    void wczytaj_pozycje();
/*!
** @brief Gra
*   Deklaracja metody o nazwie gra()
*
*/
    void gra();
};

/*!
** \brief Definicja klasy Menu
*
*   Klasa sluzy do obslugi menu, wewnatrz znajduja sie metody oraz pola umozliwiajace obsluge menu
*/
class Menu
{
public:
/*!
** @brief Menu
*   Konstruktor klasy Menu. Tworzy menu glowne
* @param[in] width - szerokosc okna
* @param[in] height - wysokosc okna
*
*/
	Menu(float width, float height);
/*!
** @brief Instrukcja
*   Deklaracja metody o nazwie instrukcja()
* @param[in] width - szerokosc okna
* @param[in] height - wysokosc okna
*
*/

	void instrukcja(float width, float height);

/*!
** @brief Destruktor klasy Menu
*   Deklaracja destruktora klasy menu
*
*/
	~Menu();

/*!
** @brief rysuj
*   Deklaracja metody o nazwie rysuj()
* @param[in] jako parametr pobiera obiekt typu RenderWindow
*
*/

	void rysuj(sf::RenderWindow &window);

/*!
** @brief ruch w gore
*   Deklaracja metody o nazwie ruch_gora()
*
*/
	void ruch_gora();
/*!
** @brief ruch w dol
*   Deklaracja metody o nazwie instrukcja()
*
*/
	void ruch_dol();
/*!
** @brief wcisniecie klawisza
*   Deklaracja metody o nazwie klawisz_zostal_wcisniety()
* @return funkcja zwraca zmienna o nazwie zaznaczenie, ktora mowi nam ktora opcje wybral uzytkownik w menu glownym
*
*/
	int klawisz_zostal_wcisniety() { return zaznaczenie; }

private:
/*!
* \brief zaznaczenie
* Zmienna w ktorej zapisywany jest wybor uzytkownika w menu.
*
*/
	int zaznaczenie;

/*!
* \brief font
* Obiekt typu Font sluzacy do zaladowania czcionki z pliku
*
*/
	sf::Font font;
/*!
* \brief menu
* Tablica obiektow typu Text sluzaca do wygenerowania opcji znajdujacych sie w menu glownym, a takze wykorzystywana do stworzenia
* instrukcji poruszania sie bierek.
*
*/
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};



#endif
