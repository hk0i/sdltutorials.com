#ifndef _TICTACTOE_H
#define _TICTACTOE_H

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

        //assumes X or O based on current player
        void takeTurn(int index);

        const GridType getCell(int index) const;


    private:

        int gameBoard[9];
        int currentPlayer;

};
#endif
