#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

//okno gameover

namespace Sonar
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data); // konstruktor -> to zawiera  AssetManager, Input manager, state, window i uzyjemy to w naszym state

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;

	};
}
