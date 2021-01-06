#pragma once

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data); // konstruktor -> to zawiera  AssetManager, Input manager, state, window i uzyjemy to w naszym state

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}
