#include "Game.h"
#include <iostream>

Game::Game() {
}

void Game::loop() {
    // see the gameprogrammingpatterns book on game loops
    bool running = true;
    while ( running && display->IsRunning() ) {
        // update the display
        display->Update();
        update( this, 0.0f );
        render( this );
    }
}

void Game::start() {
    // create the display and such first
    display = new Display( 800, 600, "Test Game: Plat" );
    // call the load function to set up game stuff.
    // level, entities, etc. 
    load( this );
    // start the game loop
    loop();
}
