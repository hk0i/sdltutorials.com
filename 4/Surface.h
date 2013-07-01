#ifndef _SURFACE_H
#define _SURFACE_H

#include <SDL/SDL.h>
#include <SDL/SDL_Image.h>

class Surface
{
    public:
        Surface();
        ~Surface();

        static SDL_Surface *load(const char *file);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int x, int y);
        static bool draw(SDL_Surface *dest, SDL_Surface *src, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight);
        static bool transparent(SDL_Surface *dest, int red, int green, int blue);
};

#endif