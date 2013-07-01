#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <SDL/SDL.h>

class Animation
{
    public:
        Animation();
        ~Animation();

        void onAnimate(void);

        void setFramerate(int newFramerate);
        void setCurrentFrame(int frame);
        const int getCurrentFrame(void) const;

        int maxFrames;
        bool oscillate;

    private:
        int currentFrame;
        int frameIncrement;
        int framerate;
        long oldTime;
};

#endif