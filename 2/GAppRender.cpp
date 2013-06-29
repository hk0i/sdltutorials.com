#include "GApp.h"

void GApp::onRender(void)
{
    Surface::draw(test, display, 0, 0);
    Surface::draw(test, display, 100, 100, 0, 0, 50, 50);

    SDL_Flip(display);
}