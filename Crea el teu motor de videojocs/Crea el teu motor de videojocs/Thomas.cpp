#include "Thomas.h"

Thomas::Thomas(float x, float y)
    : Character(x, y, 250, -450) {
    shape.setFillColor(sf::Color::Green);
}

void Thomas::handleInput() {
    velocity.x = 0;

    if (sf::Keyboard::isKeyPressed(Keyboard::Key::Left)
        velocity.x = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x = speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}
