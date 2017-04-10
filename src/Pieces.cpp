/**
 * Implementations of methods in pieces.
 *
 * @author Kevin Midkiff
 */

#include "Pieces.h"

int getNumberRotations(Piece p)
{
    switch(p)
    {
    case PIECE_O: return 1;
    case PIECE_I:
    case PIECE_2:
    case PIECE_5: return 2;
    case PIECE_T:
    case PIECE_L:
    case PIECE_P: return 4;
    }
}
