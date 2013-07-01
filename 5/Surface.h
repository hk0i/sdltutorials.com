#ifndef _SURFACE_H
#define _SURFACE_H

#include <SDL/SDL.h>

class Surface
{
    public:
        Surface();
        ~Surface();

        static SDL_Surface *load(char *file);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int x, int y);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight);
};

#endif