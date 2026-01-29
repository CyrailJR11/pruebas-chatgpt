#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameObject {
protected:
    sf::Vector2f position;
    sf::RectangleShape shape;

public:
    GameObject(float x, float y, float w, float h);
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds();
    void setPosition(float x, float y);
};
