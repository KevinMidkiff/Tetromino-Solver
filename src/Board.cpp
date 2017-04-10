/**
 * Board Implementation
 *
 * @author Kevin Midkiff
 */

#include <stdio.h>
#include "Board.h"


Board::Board(int m, int n) :
    mRowLen(m), mColLen(n), mUpperLeftX(0), mUpperLeftY(0), mLetter('a')
{
    // Initialize grid
    mGrid = new char*[m];

    // Fill grid chars with the empty cell character
    for(int i = 0; i < m; i++)
    {
        mGrid[i] = new char[n];
        for(int j = 0; j < n; j++)
            mGrid[i][j] = EMPTY_CELL;
    }
}

Board::~Board()
{
    // Deleting offsets
    for(auto pp : mPlacedPieces)
        delete[] pp.offsets;
    // Delete the grid
    for(int i = 0; i < mRowLen; i++)
        delete mGrid[i];
    delete mGrid;
}

std::pair<int,int> Board::initPair(int x, int y)
{
    std::pair<int,int> p;
    p.first = x;
    p.second = y;
    return p;
}

std::pair<int,int>* Board::initOffsets(std::pair<int,int> p1,
                                        std::pair<int,int> p2,
                                       std::pair<int,int> p3)
{
    std::pair<int,int>* offsets = new std::pair<int,int>[OFFSET_LEN];
    offsets[0] = initPair(0,0);
    offsets[1] = p1;
    offsets[2] = p2;
    offsets[3] = p3;
    return offsets;
}

std::pair<int,int>* Board::getOffsets(Piece p, Rotation r)
{
    std::pair<int,int>* offs;
    switch(p)
    {
    case PIECE_I:
        if(r == ROT_0)
            offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(0, 3));
        else if(r == ROT_90)
            offs = initOffsets(initPair(1, 0), initPair(2, 0), initPair(3, 0));
        break;
    case PIECE_5:
        if(r == ROT_0)
            offs = initOffsets(initPair(1, 0), initPair(0, 1), initPair(-1, 1));
        else if(r == ROT_90)
            offs = initOffsets(initPair(0, 1), initPair(1, 1), initPair(1, 2));
        break;
    case PIECE_2:
        if(r == ROT_0)
            offs = initOffsets(initPair(1, 0), initPair(1, 1), initPair(2, 1));
        else if(r == ROT_90)
            offs = initOffsets(initPair(0, 1), initPair(-1, 1), initPair(-1, 2));
        break;
    case PIECE_T:
        switch(r)
        {
        case ROT_0:   offs = initOffsets(initPair(1, 0), initPair(1, 1), initPair(2, 0)); break;
        case ROT_90:  offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(-1, 1)); break;
        case ROT_180: offs = initOffsets(initPair(0, 1), initPair(-1, 1), initPair(1, 1)); break;
        case ROT_270: offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(1, 1)); break;
        }
        break;
    case PIECE_L:
        switch(r)
        {
        case ROT_0:   offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(1, 2)); break;
        case ROT_90:  offs = initOffsets(initPair(1, 0), initPair(2, 0), initPair(0, 1)); break;
        case ROT_180: offs = initOffsets(initPair(1, 0), initPair(1, 1), initPair(1, 2)); break;
        case ROT_270: offs = initOffsets(initPair(0, 1), initPair(-1, 1), initPair(-2, 1)); break;
        }
        break;
    case PIECE_P:
        switch(r)
        {
        case ROT_0:   offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(1, 0)); break;
        case ROT_90:  offs = initOffsets(initPair(1, 0), initPair(2, 0), initPair(2, 1)); break;
        case ROT_180: offs = initOffsets(initPair(0, 1), initPair(0, 2), initPair(-1, 2)); break;
        case ROT_270: offs = initOffsets(initPair(0, 1), initPair(1, 1), initPair(2, 1)); break;
        }
        break;
    case PIECE_O: offs = initOffsets(initPair(0, 1), initPair(1, 0), initPair(1, 1)); break;
    default:break;
    }

    return offs;
}

bool Board::place(Piece p, Rotation r)
{
    // Get the offsets for the given piece on its given rotation
    std::pair<int,int>* offsets = getOffsets(p, r);

    // Check that the offsets are allowed
    for(int i = 0; i < OFFSET_LEN; i++)
    {
        // Get the current offset we are looking at.
        std::pair<int, int> xy = offsets[i];
        // Potential X coordinate of the to-be filled cell in the grid
        int x = mUpperLeftX + xy.first;
        // Potential y coordinate of the to-be filled cell in the grid
        int y = mUpperLeftY + xy.second;

        // If either is < 0, then we have an out of bounds error, and the
        // piece cannot be placed
        if(x < 0 || y < 0)
            return false;

        // If x > the column number, then it is out of bounds, or if y is > row number,
        // then it is out of bounds and cannot be placed
        if(x >= mColLen || y >= mRowLen)
            return false;

        // Check if the cell is already occupied, if it is already occupied, then the piece
        // cannot be placed
        if(mGrid[y][x] != EMPTY_CELL)
            return false;
    }

    // If we get to this point, then we can place the piece.
    for(int i = 0; i < OFFSET_LEN; i++)
    {
        std::pair<int,int> xy = offsets[i];
        mGrid[mUpperLeftY + xy.second][mUpperLeftX + xy.first] = mLetter;
    }

    // Add the placed piece to the list of placed pieces
    PiecePlacement pp = { p, offsets, mUpperLeftX, mUpperLeftY };
    mPlacedPieces.push_back(pp);

    // Increment the letter so the next place piece uses the correct char
    mLetter++;

    // Find upper left, it is okay if it cannot find an upper left, as this means the
    // board is solved.
    findUpperLeft();

    return true;
}

void Board::findUpperLeft()
{
    bool found = false;
    int x = mUpperLeftX;
    int y = mUpperLeftY;

    // Loop until we find a new upper left x and y
    while(!found)
    {
        // Increment the current x value
        x++;
        // If x is greater than the column length, then go to the next y value
        if(x > mColLen)
        {
            x = 0;
            y++;
            // If the next y value is greater than the number of rows, then no new
            // upper left x and y exists.
            if(y >= mRowLen)
            {
                // If we can no longer find any empty cells, then the board is
                // completely covered, therefore, the board is solved.
                mSolved = true;
                x = -1;
                y = -1;
                break;
            }
        }

        // If the current cell we are looking at is empty, then we have our new
        // upper left x and y.
        if(mGrid[y][x] == EMPTY_CELL)
            found = true;
    }

#ifdef DEBUG
    printf("Updating upper (x,y): (%d, %d) => (%d, %d)\n",
           mUpperLeftX, mUpperLeftY, x, y);
#endif

    mUpperLeftX = x;
    mUpperLeftY = y;
}

void Board::pop()
{
    // Get the last place piece and remove it from the placed pieces list
    PiecePlacement pp = mPlacedPieces.back();
    mPlacedPieces.pop_back();

    // Clear the letters that were placed on the grid
    for(int i = 0; i < OFFSET_LEN; i++)
    {
        std::pair<int,int> xy = pp.offsets[i];
        mGrid[pp.upperY + xy.second][pp.upperX + xy.first] = EMPTY_CELL;
    }

#ifdef DEBUG
    printf("Resetting upper (x,y): (%d, %d) => (%d, %d)\n",
           mUpperLeftX, mUpperLeftY, pp.upperX, pp.upperY);
#endif

    // Reset the board's upper left x and y to the previous values
    mUpperLeftX = pp.upperX;
    mUpperLeftY = pp.upperY;

    // Delete offsets array
    delete[] pp.offsets;

    // Decrement the letter
    mLetter--;
}

bool Board::solved()
{
    return mSolved;
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

