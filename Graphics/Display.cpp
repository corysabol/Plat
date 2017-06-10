#include "Display.h"

Display::Display( const int width, const int height, const std::string &title ) {
    this->width = width;
    this->height = height;
    this->title = title;

    //Create the SDL window
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );
    glContext = SDL_GL_CreateContext( window );
}

void Display::Update() {
    // double buffer and such
}
