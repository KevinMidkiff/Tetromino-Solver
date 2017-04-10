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

    /**
     * Initialize an (x,y) pair with the given x and y.
     *
     * @param x - X integer value
     * @param y - Y integer value
     * @return An std::pair<int,int> with first = x and second = y
     */
    std::pair<int,int> initPair(int x, int y);

    /**
     * Initialize an array of pairs for the offsets for a piece to be placed based
     * on the upper left x and y values. The length of the array returned from this
     * method is OFFSET_LEN (i.e. 4). The first element of the array is always (0, 0).
     * The structure of the array is: [ (0,0), p1, p2, p3 ].
     *
     * \note{ The array must be deleted by the caller of the method. }
     *
     * @param p1 - First pair after (0,0)
     * @param p2 - Second pair of (x,y) values
     * @param p3 - Third pair of (x,y) values.
     * @return Array of pairs of length OFFSET_LEN
     */
    std::pair<int,int>* initOffsets(std::pair<int,int> p1,
                                   std::pair<int,int> p2,
                                   std::pair<int,int> p3);

    /**
     * Get the offsets for the placement of the given piece on the given rotation.
     *
     * @param p - Piece to get offsets for
     * @param r - Rotation of the piece
     * @return List of pairs representing the x,y offsets, of length OFFSET_LEN
     */
    std::pair<int,int>* getOffsets(Piece p, Rotation r);

    /**
     * Find the next upper left x and y values. Note that if no upper left x and y
     * values can be found, mUpperLeftX and mUpperLeftY will be set to -1. Because
     * of the way this algorithm works, if that is the case then the board has been
     * solved. If this is the case, then the mSolved flag is set to True.
     */
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

