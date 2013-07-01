#include "TicTacToe.h"

TicTacToe::TicTacToe(void)
{
    resetBoard();
}

TicTacToe::~TicTacToe(void)
{

}

void TicTacToe::resetBoard(void)
{
    gameOver = false;
    currentPlayer = 0;

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

const TicTacToe::GridType TicTacToe::takeTurn(int index)
{
    //cast int to GridType
    if (!gameOver) {
        setCell(index, (GridType) (currentPlayer + 1));
    }

    if (checkForWin()) {
        std::cout << "Player " << currentPlayer + 1 << " WINS!" << std::endl;
        return (GridType) (currentPlayer + 1);
    }

    currentPlayer = !currentPlayer;

    return GRID_NONE;
}

/**
 * Checks for a winner and sets gameOver flag if there is one.
 * @return  [description]
 */
const bool TicTacToe::checkForWin(void)
{
    //across
    std::cout << gameBoard[0] << gameBoard[1] << gameBoard[2] << std::endl;
    std::cout << gameBoard[3] << gameBoard[4] << gameBoard[5] << std::endl;
    std::cout << gameBoard[6] << gameBoard[7] << gameBoard[8] << std::endl;
    std::cout << std::endl;

    if (gameBoard[0] > 0
        && gameBoard[0] == gameBoard[1]
        && gameBoard[1] == gameBoard[2]) {
        gameOver = true;
    }

    return gameOver;

}

const bool TicTacToe::isGameOver(void) const
{
    return gameOver;
}