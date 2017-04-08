/**
 * Tetromino Solver
 *
 * @author Kevin Midkiff
 */

#ifndef _TETROM_SOLVER_H_
#define _TETROM_SOLVER_H_

#include <vector>
#include <algorithm>
#include "Pieces.h"
#include "Board.h"

/**
 * TetrominoSolver Class
 */
class TetrominoSolver
{
private:
    std::vector<Piece> mPieces;
    Board* mBoard;

    /**
     * Recursive solve method.
     *
     * @param pieces - List of pieces to try solving with
     * @return true if solved, false if failed
     */
    bool solver(std::vector<Piece> pieces);

public:
    /**
     * Constructor
     *
     * @param m      - Board grid m value (for m x n)
     * @param n      - Board grid n value (for m x n)
     * @param pieces - List of pieces to use to try and find a solution
     */
    TetrominoSolver(int m, int n, std::vector<Piece> pieces);

    /**
     * Destructor
     */
    ~TetrominoSolver();

    /**
     * Try to solve the tetromino puzzle.
     *
     * @return true if a solution was found, false if it was not found
     */
    bool solve();

    /**
     * Print the solution to stdout.
     */
    void print();
};

#endif // _TETROM_SOLVER_H_
