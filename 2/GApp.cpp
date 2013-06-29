#include "GApp.h"

GApp::GApp()
 : isRunning(true),
   display(NULL),
   test(NULL)
{

}

int GApp::onExecute(void)
{
    if (onInit() == false) {
        return -1;
    }

    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            onEvent(&event);

            onLoop();
            onRender();
        }
    }

    onCleanup();
    return 0;
}

GApp::~GApp()
{

}

int main(int argc, char *argv[])
{
    GApp app;

    return app.onExecute();
}
