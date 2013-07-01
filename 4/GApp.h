#ifndef _GAPP_H
#define _GAPP_H

#include <iostream>
#include <string>

#include <SDL/SDL.h>
#include <SDL/SDL_Image.h>

#include "Surface.h"
#include "Event.h"
#include "TicTacToe.h"

#define INIT_SURFACE(surf, img) if ((surf = Surface::load(#img)) == NULL) { \
    std::cerr << "Could not load surface: " << #surf << " (" << #img << ")" << std::endl; \
    return false; \
}

#define INIT_SURFACE_ALPHA(surf, img) if ((surf = Surface::loadAlpha(#img)) == NULL) { \
    std::cerr << "Could not load surface: " << #surf << " (" << #img << ")" << std::endl; \
    return false; \
}

#define DISPLAY_WIDTH 600
#define DISPLAY_HEIGHT 600

class GApp : public Event
{
    public:
        GApp();
        ~GApp();

        int onExecute(void);
        bool onInit(void);

        void onEvent(SDL_Event *event);
        void onLoop(void);
        void onRender(void);
        void onCleanup(void);

        //events
        void onQuit(void);
        void onMouseDown(Uint8 button, int mouseX, int mouseY);

        //misc functions
        void displayWinner(TicTacToe::GridType winner);

        void setPVM();

    private:

        bool isRunning;
        SDL_Surface *display;

        SDL_Surface *surfGrid;
        SDL_Surface *surfX;
        SDL_Surface *surfO;

        SDL_Surface *surfXWins;
        SDL_Surface *surfOWins;

        TicTacToe gameBoard;

};

#endif
