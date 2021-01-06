// tictac.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Game.hpp"
#include "DEFINITIONS.hpp"


int main()
{
	Sonar::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Piekna gra ");

	return EXIT_SUCCESS;
}
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

//state machines - np jak jest okno logowania, okno gameover itd - different stage of game
//asset manager - pozwala uzyc jakies grafiki wiele razy i ogolnie 
//Input manager - klikniecia ogarnia itd
//gameloop -> bedzie zbieral wszystkie managery w sobie i bedzie 
//definition ma wysokosc i rozmiar okna, animacje, itd settings file :) tak jakby, wszystko sie tam ustawia itd
//Game state -> tutaj bedziemy grać, tutaj cała logika kompa bedzie itd
//game over state -> okienko gameover
//splash state -> rysowanie, grafiki itd ale tez np okno ladowania
//puase state -> co sie pokaze co w pausie sie pokaze :)
//Game over -> pojawi sie jak jest remis, przegrana albo zwyciestwo :) 
//grid system -> gra -> jak czlowiek klika itd.
//Ai -> komputer 

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
