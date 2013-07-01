#include "GApp.h"

void GApp::onCleanup(void)
{
    SDL_FreeSurface(surfX);
    SDL_FreeSurface(surfO);
    SDL_FreeSurface(surfGrid);

    SDL_FreeSurface(display);
    SDL_Quit();
}