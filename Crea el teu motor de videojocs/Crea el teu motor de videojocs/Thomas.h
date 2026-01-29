#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Thomas : public Character {
public:
    Thomas(float x, float y);
    void handleInput() override;
};
