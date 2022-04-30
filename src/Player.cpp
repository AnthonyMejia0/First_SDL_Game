#include "Player.h"

void Player::draw() {
    SDLGameObject::draw();
}

void Player::update() {
    m_x -= 1;
    m_currentFrame = 5 - (int(SDL_GetTicks64() / 100) % 6);
}

void Player::clean() {
    SDLGameObject::clean();
}
