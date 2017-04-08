/**
 * Board Implementation
 *
 * @author Kevin Midkiff
 */

#include <stdio.h>
#include "Board.h"


Board::Board(int m, int n) :
    mRowLen(m), mColLen(n), mUpperLeftX(0), mUpperLeftY(0)
{
    // Initialize grid
    mGrid = new char*[m];

    // Fill grid chars with '-' for empty cells
    for(int i = 0; i < m; i++)
    {
        mGrid[i] = new char[n];
        for(int j = 0; j < n; j++)
            mGrid[i][j] = '-';
    }
}

Board::~Board()
{
    // Delete the grid
    for(int i = 0; i < mRowLen; i++)
        delete mGrid[i];
    delete mGrid;
}

bool Board::place(Piece p, Rotation r)
{
    return false;
}

void Board::pop()
{}

bool Board::solved()
{
    return false;
}

void Board::print()
{
    for(int i = 0; i < mRowLen; i++)
    {
        for(int j = 0; j < mColLen; j++)
            printf("%c", mGrid[i][j]);
        printf("\n");
    }
}

