#include "game/game.h"

#include <SFML/Graphics.hpp>

#include "game/game_settings.h"

using namespace GameSettings;

namespace CactusClicker
{
    void Play()
    {
        sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);

        // TEXT TEST
        sf::Font font("res/font/Nunito-SemiBold.ttf");
        sf::Text text(font);
        text.setString("Cactus Clicker!");
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setPosition({ 0.0f, 0.0f });

        while (window.isOpen())
        {
            while (auto event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear(sf::Color::Black);
            window.draw(text);
            window.display();
        }
	}
}