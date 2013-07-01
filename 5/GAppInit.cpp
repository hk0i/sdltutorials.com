#include "GApp.h"

bool GApp::onInit(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if ((test = Surface::load("yoshi.bmp")) == NULL) {
        std::cerr << "Could not load surface " << SDL_GetError() << std::endl;
        return false;
    }

    animYoshi.maxFrames = 8;

    Surface::transparent(test, 255, 0, 255);

    return true;
}