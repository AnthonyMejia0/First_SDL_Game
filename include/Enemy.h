#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "GameObject.h"

class Enemy: public GameObject {
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};

#endif // __ENEMY_H__