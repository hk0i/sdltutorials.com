#ifndef _GAPP_H
#define _GAPP_H

#include <SDL/SDL.h>

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

};

#endif
