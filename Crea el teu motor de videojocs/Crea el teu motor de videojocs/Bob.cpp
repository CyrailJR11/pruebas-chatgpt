#include "Bob.h"

Bob::Bob(float x, float y)
    : Character(x, y, 180, -400) {
    shape.setFillColor(Color::Blue);
}

void Bob::handleInput() {
    velocity.x = 0;

    if (Keyboard::isKeyPressed(Keyboard::Key::Left)
        velocity.x = -speed;

    if (Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x = speed;

    if (Keyboard::isKeyPressed(Keyboard::Up) && !isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}
