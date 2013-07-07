#ifndef _ANIMATION_H
#define _ANIMATION_H

#include <SDL/SDL.h>

class Animation
{
    public:
        Animation();
        ~Animation();

        void onAnimate(void);

        void setFrameDuration(int newDurationMs); //set frame length in ms
        void setCurrentFrame(int frame);
        const int getCurrentFrame(void) const;

        int maxFrames;
        bool oscillate;

    private:
        int currentFrame;
        int frameIncrement;
        int frameDuration;
        long oldTime;
};

#endif
