#pragma once

namespace Sonar
{
	class State
	{
	public:
		virtual void Init() = 0; //initialize the state
		virtual void HandleInput() = 0; //all input in particular state
		virtual void Update(float dt) = 0; //anything input from user -> np jak klawisz czy cos
		virtual void Draw(float dt) = 0; //after ingput it will drwa -> z frame per second. 
		virtual void Pause() {} // pausa jak dzia³a
		virtual void Resume() {} // jak dziala wznowienie
	};
}