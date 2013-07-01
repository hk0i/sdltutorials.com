#include "TicTacToe.h"

TicTacToe::TicTacToe(void)
    : currentPlayer(0)
{
    resetBoard();
}

TicTacToe::~TicTacToe(void)
{

}

void TicTacToe::resetBoard(void)
{
    for (int i = 0; i < 9; ++i) {
        gameBoard[i] = GRID_NONE;
    }
}

void TicTacToe::setCell(int index, GridType type)
{
    if (index < 0 || index >= 9) {
        return;
    }

    if (type < 0 || type > GRID_O) {
        return;
    }

    gameBoard[index] = type;
}

const TicTacToe::GridType TicTacToe::getCell(int index) const
{
    return (GridType) gameBoard[index];
}

void TicTacToe::takeTurn(int index)
{
    //cast int to GridType
    setCell(index, (GridType) (currentPlayer + 1));
    currentPlayer = !currentPlayer;
}
