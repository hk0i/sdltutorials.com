#include "GApp.h"

void GApp::onEvent(SDL_Event *event)
{
    Event::onEvent(event);
}

void GApp::onQuit(void)
{
    isRunning = false;
}

void GApp::onMouseDown(Uint8 button, int mouseX, int mouseY)
{
    if (button == SDL_BUTTON_LEFT) {
        int index = mouseX / 200;
        index += (mouseY / 200) * 3;

        std::cerr << "Player " << currentPlayer << " Click! Index: " << index << std::endl;

        //if the spot is taken, exit
        if (gameBoard[index] != GRID_NONE) {
            return;
        }

        if (currentPlayer == 0) {
            setCell(index, GRID_X);
            currentPlayer = 1;
        }
        else {
            setCell(index, GRID_O);
            currentPlayer = 0;
        }
    }
}