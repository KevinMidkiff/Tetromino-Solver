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

#define MAX_PIECES_STR_LEN 9

int main(int argc, char** argv)
{
    char piecesStr[MAX_PIECES_STR_LEN];
    int m;
    int n;
    int len = 0;
    TetrominoSolver* ts;
    bool solved = false;
    std::vector<Piece> pieces;

    scanf("%d %d\n", &m, &n);
    scanf("%s", piecesStr);

    len = strlen(piecesStr);

    for(int i = 0; i < len; i++)
        pieces.push_back(static_cast<Piece>(piecesStr[i]));

    ts = new TetrominoSolver(m, n, pieces);
    solved = ts->solve();

    if(solved)
        ts->print();
    else
        printf("?\n");

    delete ts;

    return (solved) ? 0 : -1;
}
