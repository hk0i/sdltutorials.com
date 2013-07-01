#include "GApp.h"

void GApp::onRender(void)
{
    SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
    Surface::draw(test, display, 290, 220, 0, animYoshi.getCurrentFrame() * 64, 64, 64);

    SDL_Flip(display);
}