#include "screens/gameplay_screen.h"

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game/game_settings.h"
#include "interface/font.h"
#include "audio/audio_manager.h"
#include "background/background_manager.h"

using namespace GameSettings;

namespace Gameplay
{
	static sf::Text textCounter(MyFont::font);
	static int counter;

	static const int TEXT_COUNTER_POS_Y = 50;
	static const int FONT_SIZE = 48;

	static sf::Texture cactusTexture("res/textures/cactus.png");
	static sf::Sprite cactusSprite(cactusTexture);
	static float bounceOffset;
	static float bounceVelocity;
	static const float BOUNCE_HEIGHT = 10.0f;
	static const float BOUNCE_SPEED = 150.0f;
	static float rotationAngle;
	static float rotationVelocity;
	static const float ROTATION_AMOUNT = 5.0f;
	static const float ROTATION_SPEED = 100.0f;

	static bool leftWasPressed;

	static void InitCounter();
	static void UpdateCounter();
	static void DrawCounter(sf::RenderWindow& window);

	static void InitCactus();
	static void UpdateCactus(float deltaTime);
	static void DrawCactus(sf::RenderWindow& window);

	void Init()
	{
		BackgroundManager::Init();
		InitCounter();
		InitCactus();

		leftWasPressed = false;
	}

	void Input()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (!leftWasPressed)
			{
				UpdateCounter();

				bounceVelocity = -BOUNCE_SPEED;
				rotationVelocity = ROTATION_SPEED;
				rotationAngle += ROTATION_AMOUNT;

				AudioManager::clickSound.play();

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
		static sf::Clock clock;
		float deltaTime = clock.restart().asSeconds();

		BackgroundManager::Update(deltaTime);
		UpdateCactus(deltaTime);
	}

	void Draw(sf::RenderWindow& window)
	{
		BackgroundManager::Draw(window);
		DrawCounter(window);
		DrawCactus(window);
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

	static void InitCactus()
	{
		bounceOffset = 0.0f;
		bounceVelocity = 0.0f;
		rotationAngle = 0.0f;
		rotationVelocity = 0.0f;

		cactusSprite.setTexture(cactusTexture);

		sf::FloatRect bounds = cactusSprite.getLocalBounds();
		cactusSprite.setOrigin(sf::Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f));
		cactusSprite.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
	}

	static void UpdateCactus(float deltaTime)
	{
		if (bounceVelocity != 0.0f || bounceOffset != 0.0f)
		{
			bounceOffset += bounceVelocity * deltaTime;

			if (bounceOffset < -BOUNCE_HEIGHT)
			{
				bounceOffset = -BOUNCE_HEIGHT;
				bounceVelocity = BOUNCE_SPEED;
			}

			if (bounceVelocity > 0.0f && bounceOffset >= 0.0f)
			{
				bounceOffset = 0.0f;
				bounceVelocity = 0.0f;
			}
		}

		if (rotationAngle != 0.0f)
		{
			if (rotationAngle > 0.0f)
			{
				rotationAngle -= ROTATION_SPEED * deltaTime;

				if (rotationAngle < 0.0f)
				{
					rotationAngle = 0.0f;
				}
			}
			else if (rotationAngle < 0.0f)
			{
				rotationAngle += ROTATION_SPEED * deltaTime;

				if (rotationAngle > 0.0f)
				{
					rotationAngle = 0.0f;
				}
			}
		}

		cactusSprite.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f + bounceOffset));
		cactusSprite.setRotation(sf::degrees(rotationAngle));
	}

	static void DrawCactus(sf::RenderWindow& window)
	{
		window.draw(cactusSprite);
	}
}