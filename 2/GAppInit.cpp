#include "GApp.h"

bool GApp::onInit(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if ((test = Surface::load("test.bmp")) == NULL) {
        return false;
    }

    return true;
}