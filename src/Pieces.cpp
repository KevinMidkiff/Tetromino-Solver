/**
 * Implementations of methods in pieces.
 *
 * @author Kevin Midkiff
 */

#include "Pieces.h"

int getNumberRotations(Piece p)
{
    if(p == PIECE_O)
        return 1;
    else if(p == PIECE_I)
        return 2;
    else
        return 4;
}
