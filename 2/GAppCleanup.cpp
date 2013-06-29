#include "GApp.h"

void GApp::onCleanup(void)
{
    SDL_FreeSurface(test);
    SDL_FreeSurface(display);

    SDL_Quit();
}