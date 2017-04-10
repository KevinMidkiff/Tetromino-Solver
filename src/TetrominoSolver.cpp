/**
 * Tetromino Solver Class Implementation.
 *
 * @author Kevin Midkiff
 */

#include "TetrominoSolver.h"


TetrominoSolver::TetrominoSolver(int m, int n, std::vector<Piece> pieces) :
    mPieces(pieces), mBoard(new Board(m, n))
{}

TetrominoSolver::~TetrominoSolver()
{
    delete mBoard;
}

bool TetrominoSolver::solve()
{
    // If the board is solved, then return true
    if(mBoard->solved())
        return true;

    // Get the current size of the pieces list
    int size = mPieces.size();

#ifdef DEBUG
    if(size > 0)
    {
        printf("Pieces: ");
        for(auto p : mPieces)
            printf("%c", p);
        printf("\n");
    }
#endif

    for(int i = 0; i < size; i++)
    {
        // Get the current piece
        Piece p = mPieces[0];
        // Remove from list for now
        mPieces.erase(mPieces.begin());

        // Iterate over all rotations for the current piece and try to place
        // the piece on the board with that rotation.
        for(int j = 0; j < getNumberRotations(p); j++)
        {
            Rotation r = static_cast<Rotation>(j);
#ifdef DEBUG
            printf("Trying to place piece '%c' at rotation '%d'\n", p, r);
#endif
            // Try to place the piece on the board with rotation r
            if(mBoard->place(p, r))
            {
#ifdef DEBUG
                printf("Successfully placed piece '%c' at rotation '%d'\n", p, r);
                mBoard->print();
                printf("\n");
#endif
                // Recurse down and try to solve with the current piece placed
                if(this->solve())
                    return true;
                // If solving from this point fails, then remove the placed piece
                // from the board
                mBoard->pop();
            }
#ifdef DEBUG
            else
                printf("Failed to place piece '%c' at rotation '%d'\n", p, r);
#endif
        }

        // We did not find a solution with placing the current piece next,
        // put it at the back of the list and try with the next piece.
        mPieces.push_back(p);
    }

    return false;
}

void TetrominoSolver::print()
{
    mBoard->print();
}
