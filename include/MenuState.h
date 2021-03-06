#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState: public GameState {
public:
    virtual ~MenuState() {}
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_menuID; }

private:
    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;
};

#endif //__MENUSTATE_H__