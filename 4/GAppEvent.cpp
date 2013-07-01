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
    if (winner == TicTacToe::GRID_X) {
        Surface::draw(surfXWins, display, 0, 236);
    }
    else {
        Surface::draw(surfOWins, display, 0, 236);
    }

}

void GApp::onMouseDown(Uint8 button, int mouseX, int mouseY)
{
    if (button == SDL_BUTTON_LEFT) {
        int index = mouseX / 200;
        index += (mouseY / 200) * 3;

        if (!gameBoard.isGameOver()) {
            TicTacToe::GridType winner = gameBoard.takeTurn(index);
            if (gameBoard.isPVM() && gameBoard.getCurrentPlayer() == 1) {
                TicTacToe::GridType winner = gameBoard.takeTurn(index);
            }

        }
        else {
            gameBoard.resetBoard();
        }
    }
}