#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class SplashState : public State //to jest dziecko State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput(); //wszystkie inputy 
		void Update(float dt); //sprawdza czy nikt nic nie kliknal
		void Draw(float dt); //rysuje

	private:
		GameDataRef _data;

		sf::Clock _clock; //jak dlugo dziala
		sf::Sprite _background; //sprite dla t³a

	};
}
