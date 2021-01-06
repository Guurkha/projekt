#pragma once
#include "InputManager.hpp"

namespace Sonar
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button)) //jesli jest klikniety to
		{
			sf::IntRect tempRect(object.getPosition().x, 
			object.getPosition().y, object.getGlobalBounds().width,
			object.getGlobalBounds().height); //tymczasowy obszar i sprawdzamy czy zawiera mysz w polu x, y 
												//oraz deklarujemy obszar tego kwadratu
			if (tempRect.contains(sf::Mouse::getPosition(window))) //pobiera pozycje myszki
			{
				return true; //jak wszystko gro to zwraca true
			}
		}
		return false; //jesli myszka nie jest w tym obszarze to zwraca false :)
	}
	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}
}
