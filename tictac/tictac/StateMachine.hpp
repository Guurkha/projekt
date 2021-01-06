#pragma once

//state machines - np jak jest okno logowania, okno gameover itd - different stage of game

#include <memory>
#include <stack> //bazuje na stack 
#include "State.hpp"

namespace Sonar
{
	typedef std::unique_ptr<State> StateRef;  //jakis pointer

	class StateMachine         //ona wszysto bedzie trzymac, state input
	{
	public:
		StateMachine() {}  //konstruktor
		~StateMachine() {} //destruktor

		void AddState(StateRef newState, bool isReplacing = true); //add state on stack, this will be running, 
																	//main menu, klick play to play a menu will pause. popy
		void RemoveState(); //manualy remove
		void ProcessStateChanges(); //start on each loop 



		StateRef& GetActiveState(); //zwraca top state, na ktorym bedziemy rysowac itd
	private:
		std::stack<StateRef> _states; //unique pointer to states
		StateRef _newState;
		
		bool _isRemoving;     // te monitoruj¹ czy dodajemy czy co robimy
		bool _isAdding;
		bool _isReplacing;
	};
}