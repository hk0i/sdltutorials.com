#ifndef _EVENT_H
#define _EVENT_H

#include <SDL/SDL.h>

class Event
{
    public:
        Event();
        virtual ~Event();

        virtual void onEvent(SDL_Event *event);

        virtual void onInputFocus();
        virtual void onInputBlur();

        virtual void onKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
        virtual void onKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);

        virtual void onMouseFocus();
        virtual void onMouseBlur();
        virtual void onMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle);
        virtual void onMouseWheel(bool up, bool down);
        virtual void onMouseDown(Uint8 button, int mouseX, int mouseY);
        virtual void onMouseUp(Uint8 button, int mouseX, int mouseY);

        virtual void onJoyAxis(Uint8 deviceIndex, Uint8 axis, Sint16 value);
        virtual void onJoyButtonDown(Uint8 deviceIndex, Uint8 button);
        virtual void onJoyButtonUp(Uint8 deviceIndex, Uint8 button);
        virtual void onJoyHat(Uint8 deviceIndex, Uint8 hat, Uint8 value);
        virtual void onJoyBall(Uint8 deviceIndex, Uint8 ball, Sint16 relX, Sint16 relY);

        virtual void onMinimize();
        virtual void onRestore();
        virtual void onResize(int width, int height);
        virtual void onExpose();
        virtual void onExit(); //convenience function for onQuit();
        virtual void onQuit();
        virtual void onUser(Uint8 type, int code, void *data1, void *data2);

};
#endif
