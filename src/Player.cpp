#include "Player.h"

void Player::handleInput() {
    //x/yvalue(contoller number, stick number)
    if (TheInputHandler::Instance()->joysticksInitialised()) {
        if (TheInputHandler::Instance()->xvalue(0,1) > 0 || TheInputHandler::Instance()->xvalue(0,1) < 0) {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,1));
        }

        if (TheInputHandler::Instance()->yvalue(0, 1) > 0 || TheInputHandler::Instance()->yvalue(0, 1) < 0)
        {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,1));
        }
        /*
        if (TheInputHandler::Instance()->xvalue(0, 2) > 0 || TheInputHandler::Instance()->xvalue(0, 2) < 0)
        {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,2));
        }

        if (TheInputHandler::Instance()->yvalue(0, 2) > 0 || TheInputHandler::Instance()->yvalue(0, 2) < 0)
        {
         m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,2));
        }*/

        //Button input
        if (TheInputHandler::Instance()->getButtonState(0, 3)) {
            m_velocity.setX(1);
        }
    }
}

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    m_currentFrame = int(((SDL_GetTicks64() / 100) % 6));
    SDLGameObject::update();
}

void Player::clean() {
    SDLGameObject::clean();
}
