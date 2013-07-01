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

        // std::cerr << "Player " << currentPlayer << " Click! Index: " << index << std::endl;

        //if the spot is taken, exit
        if (gameBoard.getCell(index) != TicTacToe::GRID_NONE) {
            return;
        }

        gameBoard.takeTurn(index);
    }
}