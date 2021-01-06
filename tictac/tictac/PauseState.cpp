#include "PauseState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Sonar
{
	PauseState::PauseState(GameDataRef data) : _data(data) //to bierze z _data
	{

	}

	void PauseState::Init() //te rzeczy musz¹ byc spozycjonowane
	{
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2),
			(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));

	}

	void PauseState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event)) //dopuki polling na tym 
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			
			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left,
				this->_data->window))//jesli jest klikniety, to sprawdzamy co jest klikniete
			{
				this->_data->machine.RemoveState(); //usuwa pause state
			}
			
			if (this->_data->input.IsSpriteClicked(this->_homeButton, sf::Mouse::Left,
				this->_data->window))//jesli jest klikniety, to sprawdzamy co jest klikniete
			{
				this->_data->machine.RemoveState();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			
		}
	}

	void PauseState::Update(float dt)
	{
		//mozna dodac jakas animacje
	}
	void PauseState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background); // to ma byc najpierw no bo tlo. te potem nie maja znaczenia
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_homeButton);

		this->_data->window.display(); //wyswietl
	}
}
