#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
    ~Game();

    static Game* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new Game();
        }

        return s_pInstance;
    }

    bool init(const char* title, int w, int h);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }
    SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
    Game();

    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    std::vector<GameObject*> m_gameObjects;
    int m_currentFrame;
    bool m_bRunning;
};

typedef Game TheGame;

#endif