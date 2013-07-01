#include "GApp.h"

bool GApp::onInit(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if ((display = SDL_SetVideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    int imgInit = IMG_Init(imgFlags);
    if ((imgInit & imgFlags) != imgFlags) {
        return false;
    }

    INIT_SURFACE(surfGrid, img/grid.png)
    INIT_SURFACE(surfX, img/x.png)
    INIT_SURFACE(surfO, img/o.png)
    INIT_SURFACE_ALPHA(surfXWins, img/win-x.png)
    INIT_SURFACE_ALPHA(surfOWins, img/win-o.png)

    Surface::transparent(surfX, 255, 0, 255);
    Surface::transparent(surfO, 255, 0, 255);

    return true;
}