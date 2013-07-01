#include "TicTacToe.h"

TicTacToe::TicTacToe(void)
    : pvm(true)
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
    winner = GRID_NONE;

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

void TicTacToe::aiTurn(void)
{
    int randomSlot = -1;
    do {
        randomSlot = rand() % 9;
    } while(gameBoard[randomSlot] != GRID_NONE);

    gameBoard[randomSlot] = GRID_O;
}

const TicTacToe::GridType TicTacToe::takeTurn(int index)
{
    //cast int to GridType
    if (!gameOver) {
        if (pvm && currentPlayer == 1) {
            aiTurn();
        }
        else {
            setCell(index, (GridType) (currentPlayer + 1));
        }
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
    //debug print board
    std::cout << gameBoard[0] << gameBoard[1] << gameBoard[2] << std::endl;
    std::cout << gameBoard[3] << gameBoard[4] << gameBoard[5] << std::endl;
    std::cout << gameBoard[6] << gameBoard[7] << gameBoard[8] << std::endl;
    std::cout << std::endl;

    //check exception cases before looping
    //top left/bottom right diagonal
    if (gameBoard[0] > 0
        && gameBoard[0] == gameBoard[4]
        && gameBoard[4] == gameBoard[8]) {
        winner = (GridType) (currentPlayer + 1);
        gameOver = true;
        return true;
    }

    //top right/bottom left diagonal
    if (gameBoard[2] > 0
        && gameBoard[2] == gameBoard[4]
        && gameBoard[4] == gameBoard[6]) {
        winner = (GridType) (currentPlayer + 1);
        gameOver = true;
        return true;
    }

    //scan possibilities down col1
    for (int i = 0; i < 7; i+=3) {
        if (gameBoard[i] > 0) {
            //across
            if (gameBoard[i] == gameBoard[i+1]
                && gameBoard[i+1] == gameBoard[i+2]) {
                winner = (GridType) (currentPlayer + 1);
                gameOver = true;
                return true;
            }
        }
    }

    //check columns
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i] > 0) {
            if (gameBoard[i] == gameBoard[i+3]
                && gameBoard[i+3] == gameBoard[i+6]) {
                winner = (GridType) (currentPlayer + 1);
                gameOver = true;
                return true;
            }
        }
    }

    return gameOver;

}

const bool TicTacToe::isGameOver(void) const
{
    return gameOver;
}

const TicTacToe::GridType TicTacToe::getWinner(void) const
{
    return winner;
}

const int TicTacToe::getCurrentPlayer(void) const
{
    return currentPlayer;
}

const bool TicTacToe::isPVM(void) const
{
    return pvm;
}