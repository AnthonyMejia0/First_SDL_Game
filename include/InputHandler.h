#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include "SDL2/SDL.h"
#include "Vector2d.h"
#include <vector>

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

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
    bool isKeyDown(SDL_Scancode key);

    bool getMouseButtonState(int buttonNumber) {
        return m_mouseButtonStates[buttonNumber];
    }

    Vector2D* getMousePosition() {
        return m_mousePosition;
    }

private:
    InputHandler();
    ~InputHandler();
    static InputHandler* s_pInstance;
    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    std::vector<bool> m_mouseButtonStates;
    bool m_bJoysticksInitialised;
    static const int m_joystickDeadZone = 10000;
    Vector2D* m_mousePosition;
    const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;

#endif //__INPUTHANDLER_H__