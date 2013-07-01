#include "Surface.h"

Surface::Surface()
{

}

SDL_Surface *Surface::load(const char *file)
{
    SDL_Surface *temp = NULL;
    SDL_Surface *ret  = NULL;

    if ((temp = IMG_Load(file)) == NULL) {
        return NULL;
    }

    ret = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    return ret;
}

SDL_Surface *Surface::loadAlpha(const char *file)
{
    SDL_Surface *temp = NULL;
    SDL_Surface *ret  = NULL;

    if ((temp = IMG_Load(file)) == NULL) {
        return NULL;
    }

    ret = SDL_DisplayFormatAlpha(temp);
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

bool Surface::draw(SDL_Surface *src, SDL_Surface *dest, int destX, int destY, int srcX, int srcY, int srcWidth, int srcHeight)
{
    if (src == NULL || dest == NULL) {
        return false;
    }

    SDL_Rect destRect;

    destRect.x = destX;
    destRect.y = destY;

    SDL_Rect srcRect;

    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcWidth;
    srcRect.h = srcHeight;


    SDL_BlitSurface(src, &srcRect, dest, &destRect);

    return true;
}

bool Surface::transparent(SDL_Surface *dest, int red, int green, int blue)
{
    if (dest == NULL) {
        return false;
    }

    SDL_SetColorKey(dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(dest->format, red, green, blue));

    return true;
}