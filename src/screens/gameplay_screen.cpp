#include "screens/gameplay_screen.h"

#include <iostream>

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	static bool leftWasPressed;

	void Init()
	{
		leftWasPressed = false;
	}

	void Input()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (!leftWasPressed)
			{
				std::cout << "Click!" << std::endl;

				leftWasPressed = true;
			}
		}
		else
		{
			leftWasPressed = false;
		}

	}

	void Update()
	{

	}

	void Draw()
	{

	}
}