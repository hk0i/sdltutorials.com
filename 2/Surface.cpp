#include "Surface.h"

Surface::Surface()
{

}

SDL_Surface *Surface::load(char *file)
{
    SDL_Surface *temp = NULL;
    SDL_Surface *ret  = NULL;

    if ((temp = SDL_LoadBMP(file)) == NULL) {
        return NULL;
    }

    ret = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    return ret;
}

bool Surface::draw(SDL_Surface *src, SDL_Surface *dest, int x, int y)
{
    if (src == NULL || dest == NULL) {
        return false;
    }

    SDL_Rect destRect;

    destRect.x = x;
    destRect.y = y;

    SDL_BlitSurface(src, NULL, dest, &destRect);

    return true;
}