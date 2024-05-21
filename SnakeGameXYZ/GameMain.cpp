#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace SnakeGame;

int main()
{
    unsigned int seed = (unsigned int)time(nullptr);

    sf::Clock gameClock;
    sf::Time lastTime = gameClock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game");
 
    Game* game = new Game();
    InitGame(*game);

    // game loop
    while (window.isOpen())
    {
        sf::Time currentTime = gameClock.getElapsedTime();
        float timeDelta = currentTime.asSeconds() - lastTime.asSeconds();
        lastTime = currentTime;

        HandleWindowEvents(*game, window);

        if (!window.isOpen())
        {
            break;
        }

        if (UpdateGame(*game, timeDelta))
        {
            window.clear();
            DrawGame(*game, window);
            window.display();
        }
    }

    ShutdownGame(*game);
    delete game;
    game = nullptr;

    return 0;
}