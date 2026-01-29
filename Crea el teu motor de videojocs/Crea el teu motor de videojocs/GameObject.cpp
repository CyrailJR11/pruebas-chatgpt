#include "GameObject.h"
#include <SFML/Graphics.hpp>
using namespace sf;

GameObject::GameObject(float x, float y, float w, float h) {
    position = { x, y };
    shape.setSize({ w, h });
    shape.setPosition(position);
}

void GameObject::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect GameObject::getBounds() {
    return shape.getGlobalBounds();
}

void GameObject::setPosition(float x, float y) {
    position = { x, y };
    shape.setPosition(position);
}
