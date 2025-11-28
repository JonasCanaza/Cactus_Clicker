#include "screens/gameplay_screen.h"

#include <iostream>

#include <SFML/Graphics.hpp>

#include "game/game_settings.h"
#include "interface/font.h"

using namespace GameSettings;

namespace Gameplay
{
	static sf::Text textCounter(MyFont::font);
	static int counter;

	static const int TEXT_COUNTER_POS_Y = 50;
	static const int FONT_SIZE = 48;

	static bool leftWasPressed;

	static void InitCounter();
	static void UpdateCounter();
	static void DrawCounter(sf::RenderWindow& window);

	void Init()
	{
		InitCounter();

		leftWasPressed = false;
	}

	void Input()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (!leftWasPressed)
			{
				UpdateCounter();

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


	void Draw(sf::RenderWindow& window)
	{
		DrawCounter(window);
	}

	static void InitCounter()
	{
		textCounter.setCharacterSize(FONT_SIZE);
		textCounter.setFillColor(sf::Color::White);
		textCounter.setString("Clicks: 0");

		sf::FloatRect bounds = textCounter.getLocalBounds();
		textCounter.setOrigin(sf::Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f));
		textCounter.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, TEXT_COUNTER_POS_Y));
	}

	static void UpdateCounter()
	{
		counter++;
		textCounter.setString("Clicks: " + std::to_string(counter));

		sf::FloatRect bounds = textCounter.getLocalBounds();
		textCounter.setOrigin(sf::Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f));
		textCounter.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, TEXT_COUNTER_POS_Y));
	}

	static void DrawCounter(sf::RenderWindow& window)
	{
		window.draw(textCounter);
	}
}