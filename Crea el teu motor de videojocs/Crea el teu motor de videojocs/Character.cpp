#include "Character.h"

Character::Character(float x, float y, float spd, float jmp)
    : GameObject(x, y, 40, 60) {
    velocity = { 0,0 };
    isJumping = false;
    speed = spd;
    jumpForce = jmp;
}

void Character::update(float dt, int MaxX, int MaxY) {

    velocity.y += GRAVITY * dt;

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    float terra = shape.getSize().y;
    float ample = shape.getSize().x;

    // SUELO
    if (position.y > MaxY - terra) {
        position.y = MaxY - terra;
        velocity.y = 0;
        isJumping = false;
    }

    // LÍMITES
    if (position.x < 0) position.x = 0;

    if (position.x > MaxX - ample)
        position.x = MaxX - ample;

    shape.setPosition(position);
}
