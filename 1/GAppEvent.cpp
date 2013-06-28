#include "GApp.h"

void GApp::onEvent(SDL_Event *event)
{
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
}