#include "Game/Game.h"

//using callback_t = void (*)(void);
typedef void (* callback_t)(void);
typedef void (* callback_f_t)(float);

void load() {

}

void update( float dt ) {

}

void render() {

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

    // register the callbacks
    // game.start() // start the game loop running

    return 0;
}
