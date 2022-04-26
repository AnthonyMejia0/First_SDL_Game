#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include "TextureManager.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int w, int h);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }

private:
    TextureManager m_textureManager;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    int m_currentFrame;
    bool m_bRunning;
};

#endif