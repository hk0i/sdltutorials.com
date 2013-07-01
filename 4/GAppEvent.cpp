#include "GApp.h"

void GApp::onEvent(SDL_Event *event)
{
    Event::onEvent(event);
}

void GApp::onQuit(void)
{
    isRunning = false;
}

void GApp::displayWinner(TicTacToe::GridType winner)
{
    std::cout << "WINNER IS PLAYER #" << winner << std::endl;
}

void GApp::onMouseDown(Uint8 button, int mouseX, int mouseY)
{
    if (button == SDL_BUTTON_LEFT) {
        int index = mouseX / 200;
        index += (mouseY / 200) * 3;

        if (!gameBoard.isGameOver()) {
            TicTacToe::GridType winner = gameBoard.takeTurn(index);
            //check for winner to display message
            if (winner != TicTacToe::GRID_NONE) {
                displayWinner(winner);
            }
        }
        else {
            gameBoard.resetBoard();
        }
    }
}