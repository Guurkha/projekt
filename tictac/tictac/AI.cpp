#include "AI.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

using namespace std;

namespace Sonar
{
	AI::AI(int playerPiece, GameDataRef data)
	{
		this->_data = data;
		this->playerPiece = playerPiece;

		if (O_PIECE == playerPiece)
		{
			aiPiece = X_PIECE;
		}
		else
		{
			aiPiece = O_PIECE;
		}

		checkMatchVector.push_back({ 0, 2, 1, 2, 2, 2 });
		checkMatchVector.push_back({ 0, 2, 0, 1, 0, 0 });
		checkMatchVector.push_back({ 0, 2, 1, 1, 2, 0 });
		checkMatchVector.push_back({ 2, 2, 1, 2, 0, 2 });
		checkMatchVector.push_back({ 2, 2, 2, 1, 2, 0 });
		checkMatchVector.push_back({ 2, 2, 1, 1, 0, 0 });
		checkMatchVector.push_back({ 0, 0, 0, 1, 0, 2 });
		checkMatchVector.push_back({ 0, 0, 1, 0, 2, 0 });
		checkMatchVector.push_back({ 0, 0, 1, 1, 2, 2 });
		checkMatchVector.push_back({ 2, 0, 2, 1, 2, 2 });
		checkMatchVector.push_back({ 2, 0, 1, 0, 0, 0 });
		checkMatchVector.push_back({ 2, 0, 1, 1, 0, 2 });
		checkMatchVector.push_back({ 0, 1, 1, 1, 2, 1 });
		checkMatchVector.push_back({ 1, 2, 1, 1, 1, 0 });
		checkMatchVector.push_back({ 2, 1, 1, 1, 0, 1 });
		checkMatchVector.push_back({ 1, 0, 1, 1, 1, 2 });
		checkMatchVector.push_back({ 0, 1, 2, 1, 1, 1 });
		checkMatchVector.push_back({ 1, 2, 1, 0, 1, 1 });
		checkMatchVector.push_back({ 0, 2, 2, 0, 1, 1 });
		checkMatchVector.push_back({ 2, 2, 0, 0, 1, 1 });
		checkMatchVector.push_back({ 0, 2, 2, 2, 1, 2 });
		checkMatchVector.push_back({ 0, 0, 2, 0, 1, 0 });
		checkMatchVector.push_back({ 0, 2, 0, 0, 0, 1 });
		checkMatchVector.push_back({ 2, 2, 2, 0, 2, 1 });

	}

	void AI::PlacePiece(int(*gridArray)[3][3], sf::Sprite gridPieces[3][3], int* gameState)
	{
		try 
		{
			for (int i = 0; i < checkMatchVector.size(); i++) //to sprawdza czy player moze wygrac i go blokuje
			{
				CheckSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2],
					checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], PLAYER_PIECE, gridArray, gridPieces);

			}

			for (int i = 0; i < checkMatchVector.size(); i++) //to sprawdza czy komp moze wygrac i tam daje
			{
				CheckSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2],
					checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], AI_PIECE, gridArray, gridPieces);

			}

			
			//a teraz sprawdzamy czy srodkowy jest wolny
			CheckIfPieceIsEmpty(1, 1, gridArray, gridPieces);
			//teraz sprawdzamy kornery
			CheckIfPieceIsEmpty(0, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(0, 0, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 0, gridArray, gridPieces);
			//a teraz reszte
			CheckIfPieceIsEmpty(1, 2, gridArray, gridPieces);
			CheckIfPieceIsEmpty(0, 1, gridArray, gridPieces);
			CheckIfPieceIsEmpty(2, 1, gridArray, gridPieces);
			CheckIfPieceIsEmpty(1, 0, gridArray, gridPieces);

		}
		catch (int error)
		{

		}
		*gameState = STATE_PLAYING; //runda kompa sie skonczyla i gracz sie rusza.
	}
	void AI::CheckSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck,
		int(*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		if ((*gridArray)[x1][y1] == pieceToCheck && (*gridArray)[x2][y2] == pieceToCheck) //jesli sie zgadzaja wspolrzedne
		{
			if (EMPTY_PIECE == (*gridArray)[X][Y])
			{
				(*gridArray)[X][Y]= AI_PIECE; //jak jest wolne to stawiamy
				gridPieces[X][Y].setTexture(this->_data->assets.GetTexture("O piece"));

				gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255));
				throw -1;
			}
		}
	}

	void AI::CheckIfPieceIsEmpty(int X, int Y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		if (EMPTY_PIECE == (*gridArray)[X][Y])
		{
			(*gridArray)[X][Y] = AI_PIECE;
			gridPieces[X][Y].setTexture(this->_data->assets.GetTexture("O piece"));

			gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255));
			throw - 2;

		}
	}
}