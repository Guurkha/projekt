#pragma once

#include <memory>
#include <string>
#include <SFML\Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

//to jak okno gry dzial¹, wsyzstkie textury, inputy itd

namespace Sonar
{
	struct GameData
	{
	
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	
	};

	typedef std::shared_ptr<GameData> GameDataRef; //tego bedziemy uzywac do tego powyzej ^

	class Game
	{
	public:
		Game(int width, int height, std::string title); //konstruktor ma szerokosc, wysokosc i tytul gry
	
	private:
		const float dt = 1.0f / 60.0f; // klatki na sekunde :D 
		sf::Clock _clock; //potrzeba zeby utrzymac klatki
		
		GameDataRef _data = std::make_shared<GameData>(); //to bedziemy uzywac w statech zeby miec dostep to tego structa

		void Run();
	};

}