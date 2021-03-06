#ifndef __PLAYSTATE_H__
#define __PLAYSTATE_H__

#include "GameState.h"

class PlayState : public GameState
{
public:
    virtual ~PlayState() {}
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const { return s_playID; }

private:
    static const std::string s_playID;
};

#endif //__PLAYSTATE_H__