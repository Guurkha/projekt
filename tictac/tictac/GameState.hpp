#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "AI.hpp"

//okno gry 

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data); // konstruktor -> to zawiera  AssetManager, Input manager, state, window i uzyjemy to w naszym state

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		void InitGridPieces(); //inicjalizacja planszy

		void CheckAndPlacePiece(); //funkcja ktora sprawdza czy jest klikniete i daje krzyzyk
		
		void CheckPlayerHasWon(int turn); //sprawdza kto wygra³, na podstawie tury
		
										  //tu sprawdzamy czy rz¹d, szereg albo przekatna sie zgadzaja
		void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);  

		GameDataRef _data;

		sf::Sprite _background;
		
		sf::Sprite _pauseButton;
		
		sf::Sprite _gridSprite;

		sf::Sprite _gridPieces[3][3];
		int gridArray[3][3]; //sprawdza co jest

		int turn; //czyja tura -> to definy z X_piece O_piece itd
		int gameState; // a State won, lose itd

		AI* ai;

		sf::Clock _clock; //czyma czas jak dlugo przegralismy lub wygralismy


	};
}
