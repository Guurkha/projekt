#pragma once

#include <SFML\Graphics.hpp>
//wykrywa klikniecie uzytkownika

namespace Sonar
{
	class InputManager
	{
	public:
		InputManager() {} //konstruktor
		~InputManager() {} //dekonstruktor
		
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window); //sprite klikniety, myszka, i okno gdzie to jest
		sf::Vector2i GetMousePosition(sf::RenderWindow& window); //myszka + okno gdzie ta myszka jest
	};
}