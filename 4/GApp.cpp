#include "GApp.h"

GApp::GApp()
 : isRunning(true),
   display(NULL),
   surfGrid(NULL),
   surfX(NULL),
   surfO(NULL),
   currentPlayer(0)
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

void GApp::resetBoard(void)
{
    for (int i = 0; i < 9; ++i) {
        gameBoard[i] = GRID_NONE;
    }
}

void GApp::setCell(int index, int type)
{
    if (index < 0 || index >= 9) {
        return;
    }

    if (type < 0 || type > GRID_O) {
        return;
    }

    gameBoard[index] = type;
}

int main(int argc, char *argv[])
{
    GApp app;

    return app.onExecute();
}
