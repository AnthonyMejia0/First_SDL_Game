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
    Game();
    ~Game();

    bool init(const char* title, int w, int h);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    GameObject* m_go;
    GameObject* m_player;
    GameObject* m_enemy;
    std::vector<GameObject*> m_gameObjects;
    int m_currentFrame;
    bool m_bRunning;
};

#endif