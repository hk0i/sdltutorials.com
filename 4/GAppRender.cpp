#include "GApp.h"

void GApp::onRender(void)
{
    Surface::draw(surfGrid, display, 0, 0);

    for (int i = 0; i < 9; ++i)
    {
        int x = (i % 3) * 200;
        int y = (i / 3) * 200;

        if (gameBoard.getCell(i) == TicTacToe::GRID_X) {
            Surface::draw(surfX, display, x, y);
        }
        else if (gameBoard.getCell(i) == TicTacToe::GRID_O) {
            Surface::draw(surfO, display, x, y);
        }
    }

    SDL_Flip(display);
}