#include "Event.h"

Event::Event()
{

}

Event::~Event()
{

}

void Event::onEvent(SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_ACTIVEEVENT:
            switch (event->active.state)
            {
                case SDL_APPMOUSEFOCUS:
                    if (event->active.gain) {
                        onMouseFocus();
                    }
                    else {
                        onMouseBlur();
                    }
                    break;

                case SDL_APPINPUTFOCUS:
                    if (event->active.gain) {
                        onInputFocus();
                    }
                    else {
                        onInputBlur();
                    }
                    break;

                case SDL_APPACTIVE:
                    if (event->active.gain) {
                        onRestore();
                    }
                    else {
                        onMinimize();
                    }
                    break;
            }
        break; //SDL_ACTIVEEVENT

        case SDL_KEYDOWN:
            onKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;

        case SDL_KEYUP:
            onKeyUp(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;

        case SDL_MOUSEBUTTONDOWN:
            onMouseDown(event->button.button, event->button.x, event->button.y);
            break;

        case SDL_MOUSEBUTTONUP:
            onMouseUp(event->button.button, event->button.x, event->button.y);
            break;

        case SDL_JOYAXISMOTION:
            onJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
            break;

        case SDL_JOYBALLMOTION:
            onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
            break;

        case SDL_JOYHATMOTION:
            onJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;

        case SDL_JOYBUTTONDOWN:
            onJoyButtonDown(event->jbutton.which, event->jbutton.button);
            break;

        case SDL_JOYBUTTONUP:
            onJoyButtonUp(event->jbutton.which, event->jbutton.button);
            break;

        case SDL_QUIT:
            onQuit();
            break;

        case SDL_VIDEORESIZE:
            onResize(event->resize.w, event->resize.h);
            break;

        default:
            onUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
            break;
    }
}

void Event::onExit()
{
    onQuit();
}

//purely virtual functions
void Event::onInputFocus() { }
void Event::onInputBlur() { }
void Event::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) { }
void Event::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) { }
void Event::onMouseFocus() { }
void Event::onMouseBlur() { }
void Event::onMouseMove(int mouseX, int mouseY, int relX, int relY, bool left, bool right, bool middle) { }
void Event::onMouseWheel(bool up, bool down) { }
void Event::onMouseDown(Uint8 button, int mouseX, int mouseY) { }
void Event::onMouseUp(Uint8 button, int mouseX, int mouseY) { }
void Event::onJoyAxis(Uint8 deviceIndex, Uint8 axis, Sint16 value) { }
void Event::onJoyButtonDown(Uint8 deviceIndex, Uint8 button) { }
void Event::onJoyButtonUp(Uint8 deviceIndex, Uint8 button) { }
void Event::onJoyHat(Uint8 deviceIndex, Uint8 hat, Uint8 value) { }
void Event::onJoyBall(Uint8 deviceIndex, Uint8 ball, Sint16 relX, Sint16 relY) { }
void Event::onMinimize() { }
void Event::onRestore() { }
void Event::onResize(int width, int height) { }
void Event::onExpose() { }
void Event::onQuit() { }
void Event::onUser(Uint8 type, int code, void *data1, void *data2) { }
