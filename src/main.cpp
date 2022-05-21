#include <iostream>
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;

    // Create Game object
    std::cout << "Game initializing...\n";
    if (TheGame::Instance()->init("My First SDL Game", 640, 480)) {
        //Succeeded; Begin game loop
        while (TheGame::Instance()->running()) {
            //Get start frame time
            frameStart = SDL_GetTicks64();

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            //Get end frame time
            frameTime = SDL_GetTicks64() - frameStart;

            //Add delay if necessary
            if (frameTime < DELAY_TIME) {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else {
        std::cout << "Game failed to initialize.\n";
        return -1;
    }

    std::cout << "Game initialized successfully\n";

    //Exit game
    //delete TheGame::Instance();

    return 0;
}