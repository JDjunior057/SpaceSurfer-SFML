#include "Game.hpp"

int main()
{
    Game *game = new Game();
    game->init();
    while (game->isRunning)
    {
        game->run();
    }
    delete game;
}