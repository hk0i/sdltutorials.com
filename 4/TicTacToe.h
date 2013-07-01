#ifndef _TICTACTOE_H
#define _TICTACTOE_H

#include <iostream>

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
        void setCell(int index, GridType type);

        //assumes X or O based on current player, returns gridtype of winner
        const GridType takeTurn(int index);
        const GridType getCell(int index) const;

        //returns gameOver flag
        const bool isGameOver(void) const;


    private:

        bool gameOver;

        int gameBoard[9];
        int currentPlayer;

        //
        const bool checkForWin(void);

};
#endif
