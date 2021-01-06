#include "StateMachine.hpp"

namespace Sonar
{
	void StateMachine::AddState(StateRef newState, bool isReplacing) //dodawanie state
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState() //trzyme tylko any stage changes nastepnej metod
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty()) //sprawdza czy jest removing i czy nie jest puste
		{
			this->_states.pop(); //jako ze to na stack to popuje, 
			
			if (!this->_states.empty()) //sprawdza czy niepuste
			{
				this->_states.top()->Resume(); //z gory stacka bierze
			}

			this->_isRemoving = false; //ustawiamy na false
		}

		if (this->_isAdding) //jesli dodaje
		{
			if (!this->_states.empty()) //jesli nie puste
			{
				if (this->_isReplacing) //jesli podmienia to popuje
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause(); //jesli nie to paza
				}
			}
		this->_states.push(std::move(this->_newState)); //jak cos to push
		this->_states.top()->Init(); 
		this->_isAdding = false;
		}
	}
	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}