#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "SDLGameObject.h"

class Player: public SDLGameObject {
public:
    Player(const LoaderParams* pParams): SDLGameObject(pParams) {}
    void draw();
    void update();
    void clean();
};

#endif //__PLAYER_H__