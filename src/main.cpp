/**
 * Main entry point of the program.
 *
 * @author Kevin Midkiff
 */

#include <vector>
#include <stdio.h>
#include <string.h>

#include "Pieces.h"
#include "TetrominoSolver.h"

#define MAX_PIECES 9
#define MAX_SIZE 36

int main(int argc, char** argv)
{
    char piece;
    int m;
    int n;
    TetrominoSolver* ts;
    bool solved = false;
    std::vector<Piece> pieces;

    // Scan row and column size
    scanf("%d %d\n", &m, &n);

    // Check if m x n is greater than the max possible size
    if((m * n) > MAX_SIZE)
    {
#ifdef DEBUG
        printf("Failed: %d * %d > %d\n", m, n, MAX_SIZE);
#endif
        printf("?\n");
        return 0;
    }

    while((piece = getchar()) != EOF)
    {
        if(piece != '\n')
            pieces.push_back(static_cast<Piece>(piece));
    }

    // Check that the number of pieces does not exceed the max
    // number of pieces
    if(pieces.size() > MAX_PIECES)
    {
#ifdef DEBUG
        printf("Failed: # of pieces %d > %d\n", (int) pieces.size(), MAX_PIECES);
#endif
        printf("?\n");
        return 0;
    }

    // Check if there are too many pieces to fit in the area.
    if(m * n != ((int) pieces.size()) * 4)
    {
#ifdef DEBUG
        printf("Failed: %d * %d > %d\n", m, n, (int) pieces.size() * 4);
#endif
        printf("?\n");
        return 0;
    }

    // Create the solver and solve
    ts = new TetrominoSolver(m, n, pieces);
    solved = ts->solve();

    // Check the result
    if(solved)
        ts->print();
    else
        printf("?\n");

    delete ts;

    return 0;
}
