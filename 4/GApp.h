#ifndef _GAPP_H
#define _GAPP_H

#include <iostream>

#include <SDL/SDL.h>
#include "Surface.h"
#include "Event.h"

#define INIT_SURFACE(surf, img) if ((surf = Surface::load(#img)) == NULL) { \
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

        //app functions
        void resetBoard(void);
        void setCell(int index, int type);


    private:

        bool isRunning;
        SDL_Surface *display;

        SDL_Surface *surfGrid;
        SDL_Surface *surfX;
        SDL_Surface *surfO;

        int gameBoard[9];
        int currentPlayer;

        enum {
            GRID_NONE = 0,
            GRID_X,
            GRID_O
        };


};

#endif
