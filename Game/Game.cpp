#include "Game.h"
#include "../Graphics/Renderer.h"
#include "../Util/LTimer.h"
#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <GL/glew.h>


const int SCREEN_FPS = 60;
const int MS_PER_FRAME = 1000/SCREEN_FPS;

Game::Game() {
}

void Game::Loop() {
    // see the gameprogrammingpatterns book on game loops
    bool running = true;
    // The optimized game loop
    // locked to 60fps
    // we can simply run the calculations then sleep until it's time to 
    // loop again. 
    //
    // In the future we can also consider the more complex but arguably better
    // technique of having a fixed timestep for updates and a variable step for rendering
    // coupled with rendering extrapolation.
    LTimer fpsTimer;
    LTimer capTimer;
    std::stringstream timeText;

    int countedFrames = 0;
    fpsTimer.start();
    while ( display->IsRunning() ) {
        // Start cap timer
        capTimer.start();

        this->Input();

        // Calculate and correct fps
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if ( avgFPS > 2000000 ) {
            avgFPS = 0;        
        }

        // Set text to be rendered
        timeText.str( "" );
        timeText << "Average FPS (w/ cap) " << avgFPS;
        std::cout << timeText.str() << std::endl;

        this->Update();

        this->Render();
        ++countedFrames;

        // If frame finished early
        int frameTicks = capTimer.getTicks();
        if ( frameTicks < MS_PER_FRAME ) {
            // wait remaining time
            SDL_Delay( MS_PER_FRAME - frameTicks );
        }
    }
}

void Game::Load() {
    // preliminary work

    // call the load callback
    load( this );
}

void Game::Input() {
    // preliminary work
    
    // call the input callback
    input( this );
}

void Game::Update() {
    // preliminary work

    // call the update callback
    GLfloat dt = 0.0f;
    update( this, dt );
}

void Game::Render() {
    // preliminary work
    
    // call the render callback
    render( this );
    // double buffer the window
    this->display->Update();
}

void Game::Start() {
    // create the display and such first
    display = new Display( 800, 600, "Test Game: Plat" );
    // call the load function to set up game stuff.
    // level, entities, etc. 
    this->Load();
    // start the game loop
    Loop();
}
