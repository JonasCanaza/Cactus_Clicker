#include "game/game.h"

#include <SFML/Graphics.hpp>

#include "game/game_settings.h"
#include "screens/gameplay_screen.h"

using namespace GameSettings;

namespace CactusClicker
{
    Screens currentScreen;

    static void Init();
    static void Input();
    static void Update();
    static void Draw();

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
            Draw();
            window.display();
        }
	}

    static void Init()
    {
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

    static void Draw()
    {
        switch (currentScreen)
        {
        case Screens::Gameplay:

            Gameplay::Draw();

            break;
        default:

            // NO MORE SCREENS

            break;
        }
    }
}