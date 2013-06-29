#ifndef _GAPP_H
#define _GAPP_H

#include <SDL/SDL.h>
#include "Surface.h"

class GApp
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

    private:

        bool isRunning;
        SDL_Surface *display;
        SDL_Surface *test;

};

#endif
