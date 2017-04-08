/**
 * Main entry point of the program.
 *
 * @author Kevin Midkiff
 */

#include <stdio.h>
#include <string.h>

#include "Pieces.h"
#include "Board.h"

#define MAX_PIECES_STR_LEN 26

int main(int argc, char** argv)
{
    char piecesStr[MAX_PIECES_STR_LEN];
    int m;
    int n;
    int len = 0;
    Board* board;

    scanf("%d %d\n", &m, &n);
    scanf("%s", piecesStr);

    printf("Input: %d x %d\n", m, n);
    printf("Pieces: %s\n", piecesStr);

    len = strlen(piecesStr);
    printf("len = %d\n", len);
    Piece pieces[len];

    for(int i = 0; i < len; i++)
        pieces[i] = static_cast<Piece>(piecesStr[i]);

    for(int i = 0; i < len; i++)
        printf("%c\n", pieces[i]);

    board = new Board(m, n);
    delete board;

    return 0;
}
