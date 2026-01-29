#include "Game.h"

Game::Game()
    : window(VideoMode(800, 600), "Motor"),
    player(100, 100),
    bob(200, 100) {

    window.setFramerateLimit(60);

    enemies.push_back(new Enemy(300, 300));
    enemies.push_back(new Enemy(500, 300));

    font.loadFromFile("KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setCharacterSize(16);
    hud.setFillColor(Color::Black);


    load();
}

Game::~Game() {
    for (auto e : enemies) delete e;
    save();
}

int Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        handleEvents();
        update(dt);
        draw();
    }
    return 0;
}

void Game::handleEvents() {
    while (const optional event = window.pollEvent()) {

        if (event->is<Event::Closed>())
            window.close();

        if (const auto* key = event->getIf<Event::KeyPressed>()) {
            if (key->scancode == Keyboard::Scancode::P)
                paused = !paused;
        }
    }
}

void Game::update(float dt) {

    if (paused) return;

    gameTime += dt;

    player.handleInput();
    bob.handleInput();

    player.update(dt, window.getSize().x, window.getSize().y);
    bob.update(dt, window.getSize().x, window.getSize().y);

    for (auto e : enemies) {
        e->ai();
        e->update(dt, window.getSize().x, window.getSize().y);
    }

    hud.setString(
        "Score: " + to_string(score) +
        " Time: " + to_string((int)gameTime)
    );
}

void Game::draw() {

    window.clear(Color::White);



    player.draw(window);
    bob.draw(window);

    for (auto e : enemies) e->draw(window);

    window.draw(hud);

    if (paused) {
        Text t("PAUSA", font, 40);
        t.setPosition(300, 250);
        window.draw(t);
    }

    window.display();
}

void Game::save() {
    ofstream f("save.txt");
    f << score;
}

void Game::load() {
    ifstream f("save.txt");
    if (f.is_open()) f >> score;
}
