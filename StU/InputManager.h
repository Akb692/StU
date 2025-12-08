#pragma once

#include "SDL.h"
#include <iostream>
#include <map>


class InputManager
{
	struct State
	{
		bool isDown;
		bool isHeld;
		bool isUp;
	};

	State m_states[SDL_NUM_SCANCODES];

	//BONUS
	//const Uint8* m_keyboardState;
	//Uint8 m_previousKeyboardState[SDL_NUM_SCANCODES] = { 0 };


private:
	
public:
	static InputManager* Get()
	{
		static InputManager instance;
		return &instance;
	}

	InputManager()
	{
		//BONUS
		//m_keyboardState = SDL_GetKeyboardState(NULL);
	}

	void Update()
	{
		for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
		{
			State& state = m_states[i];

			if (state.isDown)
				state.isHeld = true;

			if (state.isUp)
				state.isHeld = false;

			state.isDown = false;
			state.isUp = false;
		}

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
			{
				if (event.key.repeat)
					break;

				m_states[event.key.keysym.scancode].isDown = true;
				break;
			}
			case SDL_KEYUP:
			{
				m_states[event.key.keysym.scancode].isUp = true;
				break;
			}
			}
		}

		//std::memcpy(m_previousKeyboardState, m_keyboardState, SDL_NUM_SCANCODES * sizeof(Uint8));
		//SDL_PumpEvents();
	}

	/*
	bool IsDown(SDL_Scancode key)
	{
		return m_previousKeyboardState[key] == 0 && m_keyboardState[key] == 1;
	}

	bool IsHeld(SDL_Scancode key)
	{
		return m_keyboardState[key];
	}

	bool IsUp(SDL_Scancode key)
	{
		return m_previousKeyboardState[key] == 1 && m_keyboardState[key] == 0;
	}
	*/

	bool IsDown(SDL_KeyCode key)
	{
		SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

		return m_states[scancode].isDown;
	}

	bool IsHeld(SDL_KeyCode key)
	{
		SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

		return m_states[scancode].isHeld;
	}

	bool IsUp(SDL_KeyCode key)
	{
		SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

		return m_states[scancode].isUp;
	}
};
