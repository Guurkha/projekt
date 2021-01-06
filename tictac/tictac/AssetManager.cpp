
#include "AssetManager.hpp"

namespace Sonar
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name); //zwraca teksture na konkretny klucz ktore jest referencj� na to imie ^ = tex
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name); //zwraca czcionke na konkretny klucz ktore jest referencj� na to imie ^ = tex
	}
}