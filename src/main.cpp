#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
    //Game object
    Game* game;
    // initialize SDL
    game->init("My First SDL Game", 640, 480);

    //Succeeded; Begin game loop
    std::cout << "Running Game Loop.\n";
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    std::cout << "Game Loop Finished.\n";

    //Exit game
    game->clean();

    return 0;
}