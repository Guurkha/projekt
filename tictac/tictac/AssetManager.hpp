#pragma once

#include <map>
#include <SFML\Graphics.hpp>

//³adowanie struktury -> na mapie 

namespace Sonar
{
	class AssetManager
	{
	public:
		AssetManager(){} //konstruktor
		~AssetManager(){} //dekonstruktor
		
		void LoadTexture(std::string name, std::string fileName); //nazwa jak bede nazywal i sciezka
		sf::Texture& GetTexture(std::string name); //bierze imie z metody wyzej ^ i zwraca referencje do tej textury

		void LoadFont(std::string name, std::string fileName); //nazwa jak bede nazywal i sciezka czcionka 
		sf::Font& GetFont(std::string name); //bierze imie z metody wyzej ^ i zwraca referencje do tej czcionki

	private:
		std::map<std::string, sf::Texture> _textures; //klucz do mapy to string i trzyma textury
		std::map<std::string, sf::Font> _fonts; //to samo tylko ze dla czcionki
	};
}