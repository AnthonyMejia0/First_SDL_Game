#include <iostream>
#include "Game.h"

int main(int argc, char* argv[])
{
    // Create Game object
    std::cout << "Game initializing...\n";
    if (TheGame::Instance()->init("My First SDL Game", 640, 480)) {
        //Succeeded; Begin game loop
        while (TheGame::Instance()->running()) {
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            //Add delay
            SDL_Delay(10);
        }
    }
    else {
        std::cout << "Game failed to initialize.\n";
        return -1;
    }

    std::cout << "Game initialized successfully\n";

    //Exit game
    delete TheGame::Instance();

    return 0;
}