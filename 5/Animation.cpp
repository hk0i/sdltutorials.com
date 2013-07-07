#include "Animation.h"

Animation::Animation(void)
    : maxFrames(0),
      oscillate(false),
      currentFrame(0),
      frameIncrement(1),
      frameDuration(100), //milliseconds
      oldTime(0)
{

}

Animation::~Animation()
{

}

void Animation::onAnimate(void)
{
    if (oldTime + frameDuration > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();
    currentFrame += frameIncrement;

    if (oscillate) {
        if (frameIncrement > 0) {
            if (currentFrame >= maxFrames) {
                frameIncrement = -frameIncrement;
            }
            else {
                if (currentFrame <= maxFrames) {
                    frameIncrement = -frameIncrement;
                }
            }
        }
    }
    else {
        if (currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }
}

void Animation::setFrameDuration(int newDurationMs)
{
    frameDuration = newDurationMs;
}

void Animation::setCurrentFrame(int frame)
{
    if (frame >= 0 || frame < maxFrames) {
        currentFrame = frame;
    }
}

const int Animation::getCurrentFrame(void) const
{
    return currentFrame;
}