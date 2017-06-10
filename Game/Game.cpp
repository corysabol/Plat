#include "Game.h"
#include <iostream>

Game::Game() {}

void Game::loop() {
    // see the gameprogrammingpatterns book on game loops
    bool running = true;
    while (running) {
        update_p(0.0f);
        render_p();
    }
}

void Game::start() {
    load_p();
    // start the game loop
    loop();
}
