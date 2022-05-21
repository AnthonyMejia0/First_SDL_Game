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

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
        m_velocity.setX(1);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
        m_velocity.setY(-2);

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
        m_velocity.setX(-2);

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
        m_velocity.setY(2);

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
        m_velocity.setX(2);

    //Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    //m_velocity = (*vec - m_position) / 100;
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
