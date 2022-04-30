#include "Enemy.h"

void Enemy::draw() {
    SDLGameObject::draw();
}

void Enemy::update() {
    m_x += 1;
    m_y += 1;
    m_currentFrame = (int(SDL_GetTicks64() / 100) % 6);
}

void Enemy::clean() {
    SDLGameObject::clean();
}
