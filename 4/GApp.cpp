#include "GApp.h"

GApp::GApp()
 : isRunning(true),
   display(NULL),
   surfGrid(NULL),
   surfX(NULL),
   surfO(NULL),
   surfXWins(NULL),
   surfOWins(NULL)
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

        }
        onLoop();
        onRender();
      }

    onCleanup();
    return 0;
}

void GApp::setPVM(void)
{
    gameBoard.setPVM(true);
}

GApp::~GApp()
{

}

int main(int argc, char *argv[])
{
    GApp app;
    if (argc > 1 && argv[1] == std::string("-ai")) {
        app.setPVM();
    }


    return app.onExecute();
}
