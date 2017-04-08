/**
 * Board Implementation
 *
 * @author Kevin Midkiff
 */

#include "Board.h"


Board::Board(int m, int n) :
    mUpperLeftX(0), mUpperLeftY(0)
{
    // Initialize grid
    mGrid = new char*[m];

    // Fill grid chars with '-' for empty cells
    for(int i = 0; i < m; i++)
    {
        mGrid[i] = new char[n];
        for(int j = 0; j < n; i++)
            mGrid[i][j] = '-';
    }
}

Board::~Board()
{
    // Delete the grid
    delete mGrid;
}

bool Board::place(Piece p, Rotation r)
{
    return false;
}

