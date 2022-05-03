#include "Player.h"

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_currentFrame = int(((SDL_GetTicks64() / 100) % 6));
    m_acceleration.setX(1);
    SDLGameObject::update();
}

void Player::clean() {
    SDLGameObject::clean();
}
