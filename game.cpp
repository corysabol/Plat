#include "Game/Game.h"
#include "Util/Types.h"
#include <iostream>


// This call back logic can be implemented into a Scene class
// which must define these functions and then pass them to the 
// Game instance to allow encapsulation of each scene/leve as it's 
// own set of states.
void load() {
    // load assets and shite here that is needed to set up the game.
    std::cout << "LOADING..." << std::endl;
}

void update( float dt ) {
    // Update things like entities and read input, etc.
    // This will be called every frame.
    // e.g. for e in Entities do e.update()
    std::cout << "UPDATING..." << std::endl;
}

void render() {
    // This will be called at the end of a frame after update
    // all rendering code should be defined in here.
    // e.g for d in Drawables do d.draw()
    std::cout << "RENDERING..." << std::endl;
}

int main () {

    /*
     * We want to define some callback functions which are then
     * registered to the Game which will execute them in the optimized game loop
     *
     * game.setLoad( pointerToLoadFunc )
     * game.setUpdate( pointerToUpdateFunc )
     * game.setRender( pointerToRenderFunc )
     */

    callback_t      load_p = &load;
    callback_f_t    update_p = &update;
    callback_t      render_p = &render;

    Game g;
    g.setLoad( load_p );
    g.setUpdate( update_p );
    g.setRender( render_p );
    g.start();

    return 0;
}
