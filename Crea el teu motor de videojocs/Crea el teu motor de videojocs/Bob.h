#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Bob : public Character {
public:
    Bob(float x, float y);
    void handleInput() override;
};
