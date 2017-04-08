/**
 * Representation of a board
 *
 * @author Kevin Midkiff
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

#include "Pieces.h"

class Board
{
private:
    std::vector<Piece> mPlacedPieces;
    int mRowLen;
    int mColLen;
    int mUpperLeftX;
    int mUpperLeftY;
    char** mGrid;

public:
    /**
     * Constructor
     *
     * @param m - m of the m x n matrix of the board
     * @param n - n of the m x n matrix of the board
     */
    Board(int m, int n);

    /**
     * Destructor
     */
    ~Board();

    /**
     * Try to place piece p in rotation r on the board.
     *
     * @param p - Piece to place
     * @param r - Rotation at which to place p
     * @return true if the piece was successfully place, and
     *         return false if it was not
     */
    bool place(Piece p, Rotation r);

    /**
     * Returns whether or not the board is solved.
     */
    bool solved();

    /**
     * Pop the last placed item off of the board.
     */
    void pop();

    /**
     * Print the board.
     */
    void print();
};

#endif // _BOARD_H_

