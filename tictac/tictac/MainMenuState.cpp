#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Sonar
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) //to bierze z _data
	{

	}

	void MainMenuState::Init() //te rzeczy musz¹ byc spozycjonowane
	{
		
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		//dlatego teraz pozycjonujemy
		//zawsze jest top left, a my przenosimy to na lewo przez po³owe d³ugosci
		//pierwsze przed przecinkiem to jak x a drugie to jak y
		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

		this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));

		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2),
			(this->_title.getGlobalBounds().height * 0,1)); //mnozymy zeby byl lekko w lewo

	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event)) //dopuki polling na tym 
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left,
				this->_data->window))//jesli jest klikniety, to sprawdzamy co jest klikniete
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)),true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		//mozna dodac jakas animacje
	}
	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background); // to ma byc najpierw no bo tlo. te potem nie maja znaczenia
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_playButtonOuter);
		this->_data->window.draw(this->_title);

		this->_data->window.display(); //wyswietl
	}
}
