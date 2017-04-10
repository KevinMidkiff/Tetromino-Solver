/**
 * Representation of a board
 *
 * @author Kevin Midkiff
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <utility>

#include "Pieces.h"

// Character which represents an empty cell in the board's grid
#define EMPTY_CELL '-'
#define OFFSET_LEN 4

/**
 * Structure of a placed piece on the board.
 */
struct PiecePlacement
{
    Piece p;
    std::pair<int,int>* offsets;
    int upperX;
    int upperY;
};

/**
 * Representation of a board.
 */
class Board
{
private:
    std::vector<PiecePlacement> mPlacedPieces;
    int mRowLen;
    int mColLen;
    int mUpperLeftX;
    int mUpperLeftY;
    char mLetter;
    char** mGrid;
    bool mSolved;

    // TODO: Document private methods
    std::pair<int,int> initPair(int x, int y);
    std::pair<int,int>* initOffsets(std::pair<int,int> p1,
                                   std::pair<int,int> p2,
                                   std::pair<int,int> p3);
    std::pair<int,int>* getOffsets(Piece p, Rotation r);
    void findUpperLeft();

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

