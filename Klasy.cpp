/*!
* \file
* \brief Ciala metod klas
*
* Plik zawiera ciala metod klas.
*
*/

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#include "Klasy.hpp"
#include "Connector.hpp"
#define MAX_NUMBER_OF_ITEMS 12

using namespace sf;
using namespace std;
/*!
* \brief size
* Zmienna w przechowujaca rozmiar
*/
int size = 56;

/*!
* \brief offset
* Obiekt typu Vector2f ktory sluzy jako wektor przechowujacy pare liczb typu float
*
*/
Vector2f offset(28,28);
/*!
* \brief Figury
* Tablica obiektow typu Sprite sluzaca do rysowania figur
*
*/
Sprite Figury[32];
/*!
* \brief pozycja
* Deklaracja zmiennej typu string o nazwie pozycja
*
*/
string pozycja="";

/*!
** @brief Menu
*   Konstruktor klasy Menu. Tworzy w oknie o przekazanej przez parametry szerokosci i wysokosci menu glowne. Najpierw laduje z pliku
*   czcionke jaka maja byc pisane poszczegolne opcje menu. Nastepnie wybiera kolor jakim maja byc rysowane. Pierwsza opcja w menu
*   jest rysowana kolorem czerwonym, natomiast pozostale czarnym, ma to umozliwic poruszanie sie za pomoca klawiatury po menu
*   glownym. Nastepnie jest podawany rozmiar czcionki, nazwa opcji oraz jej umieszczenie w odpowiednim miejscu na ekranie. Na sam koniec
*   metoda przypisuje zmiennej prywatnej zaznaczenie wartosc 0.
* @param[in] width - szerokosc okna
* @param[in] height - wysokosc okna
* @return Niczego nie zwraca
*/

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Northwood.ttf"))
	{
		// error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setCharacterSize(36);
	menu[0].setString("Nowa Gra");
	menu[0].setPosition(sf::Vector2f(width / 2.75, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Black);
	menu[1].setCharacterSize(36);
	menu[1].setString("Instrukcja");
	menu[1].setPosition(sf::Vector2f(width / 2.75, height / (MAX_NUMBER_OF_ITEMS + 1) * 5.25));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Black);
	menu[2].setCharacterSize(36);
	menu[2].setString("Wyjscie");
	menu[2].setPosition(sf::Vector2f(width / 2.75, height / (MAX_NUMBER_OF_ITEMS + 1) * 8.75));

	zaznaczenie = 0;
}


/*!
** @brief Instrukcja
*   Metoda klasy Menu. Tworzy w oknie o przekazanej przez parametry szerokosci i wysokosci instrukcje poruszania sie bierek.
*   Najpierw laduje z pliku czcionke jaka maja byc pisane opisy poruszania sie poszczegolnych bierek. Nastepnie wybiera kolor jakim maja
*   byc rysowane. Cala instrukcja jest rysowana kolorem czarnym. Nastepnie jest podawany rozmiar czcionki, nazwa opcji oraz jej
*   umieszczenie w odpowiednim miejscu na ekranie.
* @param[in] width - szerokosc okna
* @param[in] height - wysokosc okna
* @return Metoda niczego nie zwraca
*/

void Menu::instrukcja(float width, float height)
{
    if (!font.loadFromFile("Northwood.ttf"))
    {
        //ERROR
    }



    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Black);
    menu[0].setCharacterSize(18);
    menu[0].setString("INSTRUKCJA PORUSZANIA SIE BIEREK");
    menu[0].setPosition(sf::Vector2f(width / 6, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setCharacterSize(18);
    menu[1].setString("1. Krol porusza sie o jedno pole w dowolnym kierunku.");
    menu[1].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Black);
    menu[2].setCharacterSize(18);
    menu[2].setString("2. Goniec porusza sie po przekatnych o dowolna ilosc pol.");
    menu[2].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::Black);
    menu[3].setCharacterSize(18);
    menu[3].setString("3. Hetman porusza sie po liniach prostych i przekatnych o dowolna ilosc pol.");
    menu[3].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::Black);
    menu[4].setCharacterSize(18);
    menu[4].setString("4. Wieza porusza sie po liniach prostych o dowolna ilosc pol.");
    menu[4].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::Black);
    menu[5].setCharacterSize(18);
    menu[5].setString("5. Wieza porusza sie po liniach prostych o dowolna ilosc pol.");
    menu[5].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 6));

    menu[6].setFont(font);
    menu[6].setColor(sf::Color::Black);
    menu[6].setCharacterSize(18);
    menu[6].setString("6. Skoczek porusza sie w specyficzny sposob po szachownicy.");
    menu[6].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 7));

    menu[7].setFont(font);
    menu[7].setColor(sf::Color::Black);
    menu[7].setCharacterSize(18);
    menu[7].setString("Skoczek jako jedyna figura moze przeskakiwac inne bierki zarowno ");
    menu[7].setPosition(sf::Vector2f(width / 12, height / (MAX_NUMBER_OF_ITEMS + 1) * 8));

    menu[8].setFont(font);
    menu[8].setColor(sf::Color::Black);
    menu[8].setCharacterSize(18);
    menu[8].setString("wlasne jak i przeciwnika ");
    menu[8].setPosition(sf::Vector2f(width / 12, height / (MAX_NUMBER_OF_ITEMS + 1) * 9));

    menu[9].setFont(font);
    menu[9].setColor(sf::Color::Black);
    menu[9].setCharacterSize(18);
    menu[9].setString("7. Pionki moga poruszac sie wylacznie do przodu po liniach prostych, ");
    menu[9].setPosition(sf::Vector2f(width / 20, height / (MAX_NUMBER_OF_ITEMS + 1) * 10));

    menu[10].setFont(font);
    menu[10].setColor(sf::Color::Black);
    menu[10].setCharacterSize(18);
    menu[10].setString("jednak bija o jedno pole na ukos i nie moga sie cofac. ");
    menu[10].setPosition(sf::Vector2f(width / 12, height / (MAX_NUMBER_OF_ITEMS + 1) * 11));

    menu[11].setFont(font);
    menu[11].setColor(sf::Color::Black);
    menu[11].setCharacterSize(18);
    menu[11].setString("Kliknij INSTRUKCJA PORUSZANIA SIE BIEREK aby rozpoczac gre!");
    menu[11].setPosition(sf::Vector2f(width / 25 , height / (MAX_NUMBER_OF_ITEMS + 1) * 12));

}

/*!
** @brief ~Menu
*   Destruktor klasy menu.
*
*/
Menu::~Menu()
{
}
/*!
** @brief Rysowanie menu.
*   W metodzie wykorzystywana jest petla, oraz metoda draw dla obiektu window sluzaca do rysowania menu glownego badz instrukcji
*   w zaleznosci od miejsca w ktorym zostanie wywolana.
* @param[in] jako parametr pobiera obiekt typu RenderWindow
* @return Metoda niczego nie zwraca
*/
void Menu::rysuj(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

/*!
** @brief Poruszanie sie do gory po menu
*   W metodzie sprawdzany jest warunek czy wartosc zmiennej zaznaczenie zmniejszonej o jeden jest wieksza badz rowna zero, jezeli tak jest
*   to do tablicy menu jest przekazywana ta zmienna i odpowiednia opcja w menu jest kolorowana na kolor czarny, nastepnie nastepuje
*   dekrementacja zmiennej zaznaczenie oraz przekazanie jej na nowo do tablicy menu w celu zmiany koloru odpowiedniej opcji na czerwony.
*
* @return Metoda niczego nie zwraca
*/
void Menu::ruch_gora()
{
	if (zaznaczenie - 1 >= 0)
	{
		menu[zaznaczenie].setColor(sf::Color::Black);
		zaznaczenie--;
		menu[zaznaczenie].setColor(sf::Color::Red);
	}
}
/*!
** @brief Poruszanie sie na dol po menu
*   W metodzie sprawdzany jest warunek czy wartosc zmiennej zaznaczenie zwiekszonej o jeden jest mniejsza od stalej MAX_NUMBER_OF_ITEMS,
*   jezeli tak jest to do tablicy menu jest przekazywana ta zmienna i odpowiednia opcja w menu jest kolorowana na kolor czarny,
*   nastepnie nastepuje inkrementacja zmiennej zaznaczenie oraz przekazanie jej na nowo do tablicy menu w celu zmiany koloru
*   odpowiedniej opcji na czerwony.
*
* @return Metoda niczego nie zwraca
*/
void Menu::ruch_dol()
{
	if (zaznaczenie + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[zaznaczenie].setColor(sf::Color::Black);
		zaznaczenie++;
		menu[zaznaczenie].setColor(sf::Color::Red);
	}
}

/*!
* \brief szachownica
* Tablica o wymiarach 8x8 w ktorej zapamietywane sa poszczegolne pola szachownicy
*
*/
int szachownica[8][8] =
    {-1,-2,-3,-4,-5,-3,-2,-1,
	 -6,-6,-6,-6,-6,-6,-6,-6,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  6, 6, 6, 6, 6, 6, 6, 6,
	  1, 2, 3, 4, 5, 3, 2, 1};

/*!
** @brief toCheesNote
*   Metoda klasy Game. Jest wykorzystywana w funkcji gra() w celu wyliczenia sumy starej i nowej pozycji bierki po wykonaniu ruchu
* @param[in] Metoda przyjmuje jako parametr obiekt typu Vector2f o nazwie p
* @return Metoda zwraca zmienna typu string
*/


string Game::toChessNote(Vector2f p)
{
    string s = "";
    s += char(p.x/size+97);
    s += char(7 - p.y/size+49);
    return s;
}

/*!
** @brief toCoord
*   Metoda klasy Game. Jest wykorzystywana w funkcji gra() oraz w funkcji move()
*   w celu zapamietania starej i nowej pozycji bierki po wykonaniu ruchu
*   przez komputer
* @param[in] Metoda przyjmuje jako parametr zmienna typu char o nazwie a
* @param[in] Metoda przyjmuje jako parametr zmienna typu char o nazwie b
* @return Metoda zwraca obiekt typu Vector2f
*/

Vector2f Game::toCoord(char a,char b)
{
   int x = int(a) - 97;
   int y = 7-int(b)+49;
   return Vector2f(x*size,y*size);
}

/*!
** @brief Ruch
*   Metoda klasy Game. Na poczatku tworzone sa dwa obiekty typu Vector2f w ktorych zapamietywana jest stara i nowa pozycja bierki.
*   Nastepnie tworzona jest petla for w ktorej sprawdzany jest warunek czy aktualna pozycja kazdej bierki jest rowna nowej pozycji.
*   Jezeli tak jest to kazda bierka jest ustawiona na odpowiedniej pozycji. Analogiczna petla for oraz warunek jest stworzony dla starej
*   pozycji. Nastepnie sprawdzane sa warunki czy aby krol nie moze wykonac ruchu, jezeli tak jest wtedy szukane sa nowe pola na ktore
*   krol moze sie poruszyc.
* @param[in] Metoda przyjmuje jako parametr zmienna typu string o nazwie str
* @return Metoda niczego nie zwraca
*/

void Game::move(string str)
{
    Vector2f stara_pozycja = toCoord(str[0],str[1]);
    Vector2f nowa_pozycja = toCoord(str[2],str[3]);

	for(int i=0;i<32;i++)
     if (Figury[i].getPosition()==nowa_pozycja)
        Figury[i].setPosition(-100,-100);

    for(int i=0;i<32;i++)
     if (Figury[i].getPosition()==stara_pozycja)
        Figury[i].setPosition(nowa_pozycja);

	//Szach, jesli krol nie moze wykonac ruchu
	if (str=="e1g1") if (pozycja.find("e1")==-1) move("h1f1");
	if (str=="e8g8") if (pozycja.find("e8")==-1) move("h8f8");
	if (str=="e1c1") if (pozycja.find("e1")==-1) move("a1d1");
	if (str=="e8c8") if (pozycja.find("e8")==-1) move("a8d8");
}

/*!
** @brief wczytywanie pozycji
*   Metoda klasy Game, sluzy do wczytania pozycji poszczegolnych bierek na szachownicy, tworzone sa dwie petle for w ktorych nastepuja
*   obliczenia sluzace do ustawienia pozycji kazdej bierki.
*
* @return Metoda niczego nie zwraca
*/
void Game::wczytaj_pozycje()
{
	int k=0;
  	for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            int n = szachownica[i][j];
            if (!n) continue;
            int x = abs(n)-1;
            int y = n>0?1:0;
            Figury[k].setTextureRect( IntRect(size*x,size*y,size,size) );
            Figury[k].setPosition(size*j,size*i);
            k++;
        }
    for(int i=0; i<pozycja.length(); i+= 5)
        move(pozycja.substr(i,4));

}

/*!
** @brief Gra
*   Metoda klasy Game. Na poczatku renderowane jest okno w ktorym toczyc sie bedzie gra, oraz nastepuje polaczenie z silnikiem, w ktorym
*   wyliczane sa ruchy komputera. Nastepnie tworzone sa dwie zmienne typu Texture do ktorych ladowane sa obrazki figur oraz szachownicy.
*   Za pomoca petli for oraz funkcji wczytaj_pozycje() ustawiane sa bierki na szachownicy. Nastepnie tworzone sa odpowiednie zmienne ktore
*   zostana wykorzystane w petli glownej gry to jest zmienna typu bool sprawdzajaca czy jest ruch, zmienne pomocnicze typu float
*   okreslajace rozmiar planszy oraz dwa obiekty typu Vector2f oznaczajace stara pozycje bierki i nowa pozycje bierki. Dopoki okno jest
*   otwarte tworzone jest zdarzenie odpowiedzialne za interakcje z oknem. Na poczatku sprawdzane jest zdarzenie, czy uzytkownik nie chce
*   zamknac okna, jezeli tak to okno zostaje zamkniete. Nastepnie sprawdzane jest czy uzytkownik nie wcisnal przycisku Backspace, jesli tak
*   to ruch jest cofany. Jezeli gracz wcisnal i przytrzymal lewy przycisk myszy na polu w ktorym znajduje sie bierka to moze ja przemiescic
*   w inne miejsce, natomiast jezeli lewy przycisk myszy zostanie puszczony, to bierka zostaje upuszczona na odpowiednie miejsce na szachownicy.
*   Mozliwy jest tryb gry gracz vs gracz, gracz vs komputer oraz komputer vs komputer. W ostatnim przypadku wystarczy wciskac klawisz
*   spacji, natomiast jezeli chcemy osobiscie zagrac z komputerem to ruchy komputera wywolujemy rowniez naciskajac spacje. Na samym koncu
*   metody rysowane sa bierki oraz szachownica. Zamykane jest polaczenie z silnikiem odpowiedzialnym za wykonywanie ruchu przez komputer.
* @return Metoda niczego nie zwraca
*/

void Game::gra()
{
    RenderWindow Okno(VideoMode(504, 504), "Szachy (Jesli chcesz grac z komputerem nacisnij spacje)");

	ConnectToEngine("stockfish.exe");

	Texture t1,t2;
    t1.loadFromFile("images/figures.png");
	t2.loadFromFile("images/board.png");

	for(int i=0;i<32;i++) Figury[i].setTexture(t1);
	Sprite sSzachownica(t2);

	wczytaj_pozycje();

    bool jest_ruch = false;
	float vx = 0, vy = 0;
	Vector2f Stara_Pozycja, Nowa_Pozycja;
	std::string str;
	int n=0;
    while (Okno.isOpen())
    {
   	    Vector2i pos = Mouse::getPosition(Okno) - Vector2i(offset);
        Event e;

        while (Okno.pollEvent(e))
        {   if (e.type == Event::Closed)
            Okno.close();

			/*Ruch w tyl */
            if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::BackSpace)
                {
				    if (pozycja.length()>6) // Jezeli aktualna pozycja jest wieksza od 6
                    pozycja.erase(pozycja.length()-6,5); // to usuwamy aktualna pozycje
                    wczytaj_pozycje(); // i wczytujemy pozycje ktora teraz jest aktualna
                }

			/*Przeciagnac i zrzucic*/
			if (e.type == Event::MouseButtonPressed) // -> jezeli przycisk myszy jest wcisniety
				if (e.key.code == Mouse::Left) // -> i jezeli jest to lewy przycisk myszy
				  for(int i=0;i<32;i++)
				  if (Figury[i].getGlobalBounds().contains(pos.x,pos.y)) // -> jezeli jest na okreslonej pozycji narysowana figura
					  {
					   jest_ruch=true; n=i;
					   vx=pos.x - Figury[i].getPosition().x; // -> od x przechowywanego w wektorze odejmujemy x ze sprajta
					   vy=pos.y - Figury[i].getPosition().y;// -> to samo dla y
					   Stara_Pozycja  =  Figury[i].getPosition(); // teraz do starej poprzedniej pozycji przypisujemy nowa
                      }

             if (e.type == Event::MouseButtonReleased) // -> jezeli przycisk zostal puszczony
				if (e.key.code == Mouse::Left) // -> jezeli byl to lewy przycisk
				 {
				  jest_ruch=false; // -> wylaczamy mozliwosc ruchu
			      Vector2f p = Figury[n].getPosition() + Vector2f(size/2,size/2); // tworzymy obiekt klasy vector2f i sumujemy wartosci
			      // aktualnie pobranej pozycji i starego vectora dzielac jego wartosci x i y na pol
                  Nowa_Pozycja = Vector2f( size*int(p.x/size), size*int(p.y/size) ); // -> wczytujemy nowa pozycje
				  str = toChessNote(Stara_Pozycja)+toChessNote(Nowa_Pozycja); // -> zapamietujemy
				  move(str);// -> wysylamy zmienna str do funkcji ruchu
				  if (Stara_Pozycja!=Nowa_Pozycja) \
                  pozycja+=str+" "; // -> jezeli stara pozycja jest rozna od nowej pozycji
			      Figury[n].setPosition(Nowa_Pozycja);
			     }
		}

       //Ruchy komputera
	   if (Keyboard::isKeyPressed(Keyboard::Space)) // -> jezeli zostala wcisnieta spacja
       {
		 str =  getNextMove(pozycja);

         Stara_Pozycja = toCoord(str[0],str[1]);
         Nowa_Pozycja = toCoord(str[2],str[3]);

         for(int i=0;i<32;i++)
            if(Figury[i].getPosition()==Stara_Pozycja) n=i;

            for(int k=0;k<50;k++)
		  {
			Vector2f p = Nowa_Pozycja - Stara_Pozycja;
		    Figury[n].move(p.x/50, p.y/50);
			Okno.draw(sSzachownica);

			for(int i=0;i<32;i++)
                Figury[i].move(offset);

			for(int i=0;i<32;i++)
                Okno.draw(Figury[i]);
            Okno.draw(Figury[n]);

			for(int i=0;i<32;i++)
			Figury[i].move(-offset);
			Okno.display();
		  }

		move(str);  pozycja+=str+" ";
		Figury[n].setPosition(Nowa_Pozycja);
        }

		if (jest_ruch) Figury[n].setPosition(pos.x - vx, pos.y - vy);

	Okno.clear();
    Okno.draw(sSzachownica);
	for(int i=0;i<32;i++) Figury[i].move(offset);
    for(int i=0;i<32;i++) Okno.draw(Figury[i]); Okno.draw(Figury[n]);
	for(int i=0;i<32;i++) Figury[i].move(-offset);
 	Okno.display();
	}
	CloseConnection();
}

