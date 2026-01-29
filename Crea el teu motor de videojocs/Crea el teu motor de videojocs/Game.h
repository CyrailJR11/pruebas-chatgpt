#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Thomas.h"
#include "Bob.h"
#include "Enemy.h"

using namespace sf;
using namespace std;

class Game {
private:
    RenderWindow window;
    Clock clock;

    Thomas player;
    Bob bob;

    vector<Enemy*> enemies;

    bool paused = false;

    Font font;
    Text hud;

    int score = 0;
    float gameTime = 0;



public:
    Game();
    ~Game();
    int run();

private:
    void handleEvents();
    void update(float dt);
    void draw();
    void save();
    void load();
};
