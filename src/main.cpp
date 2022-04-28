#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
    // Create Game object
    Game* game = new Game();

    // initialize SDL
    game->init("My First SDL Game", 640, 480);

    //Succeeded; Begin game loop
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
        //Add delay
        SDL_Delay(10);
    }

    //Exit game
    delete game;

    return 0;
}