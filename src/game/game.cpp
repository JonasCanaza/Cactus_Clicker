#include "game/game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game/game_settings.h"
#include "screens/gameplay_screen.h"
#include "audio/audio_manager.h"

using namespace GameSettings;

namespace CactusClicker
{
    Screens currentScreen;

    static void Init();
    static void Input();
    static void Update();
    static void Draw(sf::RenderWindow& window);

    void Play()
    {
        sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
        currentScreen = Screens::Gameplay;

        Init();

        while (window.isOpen())
        {
            while (auto event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            Input();
            Update();

            window.clear(sf::Color::Black);
            Draw(window);
            window.display();
        }
	}

    static void Init()
    {
        AudioManager::background.setLooping(true);
        AudioManager::background.play();

        Gameplay::Init();
    }

    static void Input()
    {
        switch (currentScreen)
        {
        case Screens::Gameplay:

            Gameplay::Input();

            break;
        default:

            // NO MORE SCREENS

            break;
        }
    }

    static void Update()
    {
        switch (currentScreen)
        {
        case Screens::Gameplay:

            Gameplay::Update();

            break;
        default:

            // NO MORE SCREENS

            break;
        }
    }

    static void Draw(sf::RenderWindow& window)
    {
        switch (currentScreen)
        {
        case Screens::Gameplay:

            Gameplay::Draw(window);

            break;
        default:

            // NO MORE SCREENS

            break;
        }
    }
}