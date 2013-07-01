#ifndef _TICTACTOE_H
#define _TICTACTOE_H

#include <iostream>
#include <cstdlib>

class TicTacToe
{
    public:
        TicTacToe();
        ~TicTacToe();

        enum GridType {
            GRID_NONE = 0,
            GRID_X,
            GRID_O
        };

        //app functions
        void resetBoard(void);
        //sets player vs machine (ai)
        void setPVM(bool);
        void setCell(int index, GridType type);

        //assumes X or O based on current player, returns gridtype of winner
        const GridType takeTurn(int index);
        const GridType getCell(int index) const;
        //return winner
        const GridType getWinner(void) const;
        const int getCurrentPlayer(void) const;

        //returns gameOver flag
        const bool isGameOver(void) const;
        const bool isPVM(void) const;


    private:

        //isPVM is set to true when playing vs AI
        bool pvm;
        bool gameOver;

        int gameBoard[9];
        int currentPlayer;

        GridType winner;

        //
        const bool checkForWin(void);

        void aiTurn(void);

};
#endif
