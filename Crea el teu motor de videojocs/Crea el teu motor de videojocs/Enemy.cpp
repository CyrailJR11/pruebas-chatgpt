#include "Enemy.h"

Enemy::Enemy(float x, float y)
    : Character(x, y, 120, -300) {
    shape.setFillColor(Color::Red);
}

void Enemy::handleInput() {}

void Enemy::ai() {
    velocity.x = speed;
    if (position.x < 50 || position.x > 700)
        speed = -speed;
}
