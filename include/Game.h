#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <vector>
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:

    static Game* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new Game();
            return s_pInstance;
        }

        return s_pInstance;
    }

    bool init(const char* title, int w, int h);
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit() { m_bRunning = false; }
    bool running() { return m_bRunning; }
    SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
    Game();
    ~Game();
    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    std::vector<GameObject*> m_gameObjects;
    int m_currentFrame;
    bool m_bRunning;
    GameStateMachine* m_pGameStateMachine;

};

typedef Game TheGame;

#endif //__GAME_H__