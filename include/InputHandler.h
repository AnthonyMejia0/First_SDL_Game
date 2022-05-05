#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include "SDL2/SDL.h"
#include "Vector2d.h"
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
    bool getButtonState(int joy, int button) { return m_buttonStates[joy][button]; }
    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);
    void update();
    void clean();

private:
    InputHandler() {}
    ~InputHandler() {}
    static InputHandler* s_pInstance;
    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    bool m_bJoysticksInitialised;
    static const int m_joystickDeadZone = 10000;
};

typedef InputHandler TheInputHandler;

#endif //__INPUTHANDLER_H__