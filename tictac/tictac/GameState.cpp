#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"

#include <iostream>

#include "PauseState.hpp"
#include "GameOverState.hpp"

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data) //to bierze z _data
	{

	}

	void GameState::Init() //te rzeczy musz¹ byc spozycjonowane
	{
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->ai = new AI(turn, this->_data);

		this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		this->_data->assets.LoadTexture("X piece", X_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O piece", O_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
		this->_data->assets.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Pause Button"));
		_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));

		_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width,
			_pauseButton.getPosition().y);//przesuwamy na prawo bo by za ekran wyszli jak nie odejmiemy

		_gridSprite.setPosition((SCREEN_WIDTH/2)-(_gridSprite.getGlobalBounds().width/2),
			(SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));

		InitGridPieces();
		
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				gridArray[x][y] = EMPTY_PIECE; //ustawiamy na puste no bo po prostu poczatek
			}
		}
	}

	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event)) //dopuki polling na tym 
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left,
				this->_data->window))//jesli jest klikniety, to sprawdzamy co jest klikniete
			{
				this->_data->machine.AddState(StateRef(new PauseState(_data)), false); //nie chcemy zamienic
																			//tylko zatrzymac i dodac na stos
				
				
			}
			else if (this->_data->input.IsSpriteClicked(this->_gridSprite, sf::Mouse::Left,
				this->_data->window)) //sprawdzamy na calej planszy czy jest klikniete
			{
				if (STATE_PLAYING == gameState) //jesli rusza komp to nie moze gracz wybierac pozycji na krzyzyk
				{
					this->CheckAndPlacePiece(); 
				}
			}
		}
	}
	void GameState::Update(float dt)
	{
		//mozna dodac jakas animacje
		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER)
			{
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background); // to ma byc najpierw no bo tlo. te potem nie maja znaczenia
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.draw(this->_gridSprite);

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				this->_data->window.draw(this->_gridPieces[x][y]);
			}
		}
		this->_data->window.display(); //wyswietl
	}

	void GameState::InitGridPieces()
	{
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("X piece").getSize();
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				_gridPieces[x][y].setTexture(this->_data->assets.GetTexture("X piece"));
				_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7,
					_gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
				_gridPieces[x][y].setColor(sf::Color(255, 255, 2555, 0));
			}
		}
	}

	void GameState::CheckAndPlacePiece()
	{

		sf::Vector2i touchPoint = this->_data->input.GetMousePosition(this->_data->window); //przechowuje pozycje myszy
		sf::FloatRect gridSize = _gridSprite.getGlobalBounds(); //wielkosc grid
		sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
		sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);
		sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);
		//zajmujemy sie tylko szachownica a nie calym ekranem
		int column;
		int row;
		if (gridLocalTouchPos.x < gridSectionSize.x)
		{
			column = 1;
		}
		else if (gridLocalTouchPos.x < gridSectionSize.x * 2)
		{
			column = 2;
		}
		else if (gridLocalTouchPos.x < gridSize.width)
		{
			column = 3;
		}
		if (gridLocalTouchPos.y < gridSectionSize.y)
		{
			row = 1;
		}
		else if (gridLocalTouchPos.y < gridSectionSize.y * 2)
		{
			row = 2;
		}
		else if (gridLocalTouchPos.y < gridSize.height)
		{
			row = 3;
		}
		//jak juz wiemy gdzie kliknal to spradzamy czy jest to puste miejsce
		if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
		{
			gridArray[column - 1][row - 1] = turn; //czyja tura
			if (PLAYER_PIECE == turn)
			{
				_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.GetTexture("X piece"));

				this->CheckPlayerHasWon(turn);

			}

			_gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
		}

	}

	void GameState::CheckPlayerHasWon(int player)
	{
		//jest mozliwosc 8 kombinacji ze sie wygra/przegra, i to sa wspolrzedne x i y 
		Check3PiecesForMatch(0, 0, 1, 0, 2, 0, player);
		Check3PiecesForMatch(0, 1, 1, 1, 2, 1, player);
		Check3PiecesForMatch(0, 2, 1, 2, 2, 2, player);
		Check3PiecesForMatch(0, 0, 0, 1, 0, 2, player);
		Check3PiecesForMatch(1, 0, 1, 1, 1, 2, player);
		Check3PiecesForMatch(2, 0, 2, 1, 2, 2, player);
		Check3PiecesForMatch(0, 0, 1, 1, 2, 2, player);
		Check3PiecesForMatch(0, 2, 1, 1, 2, 0, player);

		if (STATE_WON != gameState)
		{
			gameState == STATE_AI_PLAYING;
			ai->PlacePiece(&gridArray, _gridPieces, &gameState);

			Check3PiecesForMatch(0, 0, 1, 0, 2, 0, AI_PIECE);
			Check3PiecesForMatch(0, 1, 1, 1, 2, 1, AI_PIECE);
			Check3PiecesForMatch(0, 2, 1, 2, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 0, 0, 1, 0, 2, AI_PIECE);
			Check3PiecesForMatch(1, 0, 1, 1, 1, 2, AI_PIECE);
			Check3PiecesForMatch(2, 0, 2, 1, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 0, 1, 1, 2, 2, AI_PIECE);
			Check3PiecesForMatch(0, 2, 1, 1, 2, 0, AI_PIECE);
		}

		int emptyNum = 9; //to sprawdza ile jest wolnych miejsc -> poczatkowo 9

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (EMPTY_PIECE != gridArray[x][y]) // jesli jakas przestrzen nie jest rowna 0 to odejmujemy
				{
					emptyNum--;
				}
			}
		}
		//tutaj jesli jest remis, to liczba wolnych przestrzeni to 0, i zarowno game won i lose nie jest rowny gamestate
		if (emptyNum == 0 && (STATE_WON != gameState) && (STATE_LOSE != gameState))
		{
			gameState = STATE_DRAW;
		}

		if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
		{
			//pokazemy gameover
			this->_clock.restart();
		}

		std::cout << gameState << std::endl;
	}
	
	//tutaj sprawdzamy czy te 3 wspolrzedne s¹ takie same w sensie czy ktos wygra³ -> komp albo ktos
	void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		if (pieceToCheck == gridArray[x1][y1] && pieceToCheck == gridArray[x2][y2] && pieceToCheck == gridArray[x3][y3])
		{
			std::string winningPieceStr;

			if (O_PIECE == pieceToCheck)
			{
				winningPieceStr = "O Winning Piece";
			}
			else
			{
				winningPieceStr = "X Winning Piece";
			}

			_gridPieces[x1][y1].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x2][y2].setTexture(this->_data->assets.GetTexture(winningPieceStr));
			_gridPieces[x3][y3].setTexture(this->_data->assets.GetTexture(winningPieceStr));

			if (PLAYER_PIECE == pieceToCheck) // to wygra³ gracz
			{
				gameState = STATE_WON;
			}
			else //to przegral
			{
				gameState = STATE_LOSE;
			}
		}
	}
}
