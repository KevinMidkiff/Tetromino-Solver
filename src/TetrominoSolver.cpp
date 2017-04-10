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
    int size = pieces.size();

    if(mBoard->solved())
        return true;
    if(size == 0)
        return false;

#ifdef DEBUG
    printf("Pieces: ");
    for(auto p : pieces)
        printf("%c", p);
    printf("\n");
#endif


    for(int i = 0; i < size; i++)
    {
        Piece p = pieces[0];
        pieces.erase(pieces.begin());

        for(int j = 0; j < getNumberRotations(p); j++)
        {
            Rotation r = static_cast<Rotation>(j);
#ifdef DEBUG
            printf("Trying to place piece '%c' at rotation '%d'\n", p, r);
#endif
            if(mBoard->place(p, r))
            {
#ifdef DEBUG
                printf("Successfully placed piece '%c' at rotation '%d'\n", p, r);
                mBoard->print();
                printf("\n");
#endif
                if(this->solver(pieces))
                    return true;
                mBoard->pop();
            }
#ifdef DEBUG
            else
                printf("Failed to place piece '%c' at rotation '%d'\n", p, r);
#endif
        }

        pieces.push_back(p);
    }

    return false;
}

void TetrominoSolver::print()
{
    mBoard->print();
}
