/**
 * Tetromino Solver Class Implementation.
 *
 * @author Kevin Midkiff
 */

#include "TetrominoSolver.h"


TetrominoSolver::TetrominoSolver(int m, int n, std::vector<Piece> pieces)
{
    mPieces = pieces;
    mBoard = new Board(m, n);
}

TetrominoSolver::~TetrominoSolver()
{
    delete mBoard;
}

bool TetrominoSolver::solve()
{
    return solver(mPieces);
}

bool TetrominoSolver::solver(std::vector<Piece> pieces)
{
    // Do the recursive stuff here
    if(mBoard->solved())
        return true;

    int size = pieces.size();

    for(int i = 0; i < size; i++)
    {
        Piece p = pieces[0];
        pieces.erase(pieces.begin());

        for(int j = 0; j < getNumberRotations(p); j++)
        {
            if(mBoard->place(p, static_cast<Rotation>(j)))
            {
                if(this->solver(pieces))
                    return true;
                mBoard->pop();
            }
        }

        pieces.push_back(p);
    }

    return false;
}

void TetrominoSolver::print()
{
    mBoard->print();
}
