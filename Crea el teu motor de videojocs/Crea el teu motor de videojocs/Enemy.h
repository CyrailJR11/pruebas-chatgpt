#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy : public Character {
public:
    Enemy(float x, float y);
    void handleInput() override;
    void ai();
};
