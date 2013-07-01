#ifndef _GAPP_H
#define _GAPP_H

#include <SDL/SDL.h>
#include <iostream>

#include "Surface.h"
#include "Event.h"
#include "Animation.h"

#define INIT_SURFACE(surf, img) if ((surf = Surface::load(#img)) == NULL) { \
    std::cerr << "Could not load surface: " << #surf << " (" << #img << ")" << std::endl; \
    return false; \
}

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

    private:

        bool isRunning;
        SDL_Surface *display;
        SDL_Surface *test;

        Animation animYoshi;
};

#endif
