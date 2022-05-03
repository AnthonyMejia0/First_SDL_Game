#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include "SDL2/SDL.h"
#include <vector>

class InputHandler {
public:
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void initialiseJoysticks();
    bool joysticksInitialised() { return m_bJoysticksInitialised; }

    void update();
    void clean();

private:
    InputHandler() {}
    ~InputHandler() {}
    static InputHandler* s_pInstance;
    std::vector<SDL_Joystick*> m_joysticks;
    bool m_bJoysticksInitialised;
};

typedef InputHandler TheInputHandler;

#endif //__INPUTHANDLER_H__