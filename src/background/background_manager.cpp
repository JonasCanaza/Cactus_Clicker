#include "background/background_manager.h"

#include <SFML/Graphics.hpp>

#include "game/game_settings.h"

using namespace GameSettings;

namespace BackgroundManager
{
	static sf::Texture backgroundTexture("res/textures/background.png");
	static sf::Sprite backgroundSprite(backgroundTexture);

	static const float BACKGROUND_SPEED_X = 50.0f;
	static const float BACKGROUND_SPEED_Y = 30.0f;

	static const int EXTRA_SPRITES = 2;

	static sf::Vector2f backgroundOffset;

	void Init()
	{
		backgroundOffset = sf::Vector2f(0.0f, 0.0f);
		sf::Vector2u texSize = backgroundTexture.getSize();
		backgroundSprite.setOrigin(sf::Vector2f(texSize.x / 2.0f, texSize.y / 2.0f));
	}

	void Update(float deltaTime)
	{
		backgroundOffset.x += BACKGROUND_SPEED_X * deltaTime;
		backgroundOffset.y += BACKGROUND_SPEED_Y * deltaTime;

		sf::Vector2u texSize = backgroundTexture.getSize();

		if (backgroundOffset.x >= texSize.x)
		{
			backgroundOffset.x -= texSize.x;
		}

		if (backgroundOffset.y >= texSize.y)
		{
			backgroundOffset.y -= texSize.y;
		}
	}

	void Draw(sf::RenderWindow& window)
	{
		sf::Vector2u texSize = backgroundTexture.getSize();
		sf::Vector2f center(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);

		int xCount = static_cast<int>(WINDOW_WIDTH / texSize.x) + EXTRA_SPRITES;
		int yCount = static_cast<int>(WINDOW_HEIGHT / texSize.y) + EXTRA_SPRITES;

		for (int x = 0; x < xCount; x++)
		{
			for (int y = 0; y < yCount; y++)
			{
				float posX = center.x + x * texSize.x - backgroundOffset.x - texSize.x;
				float posY = center.y + y * texSize.y - backgroundOffset.y - texSize.y;

				backgroundSprite.setPosition(sf::Vector2f(posX, posY));
				window.draw(backgroundSprite);
			}
		}
	}
}