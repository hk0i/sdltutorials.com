#include "GApp.h"

void GApp::onLoop(void)
{
    std::cerr << "Animating!!" << std::endl;
    animYoshi.onAnimate();
}