/**
 * Piece and rotations definitions.
 *
 * @author Kevin Midkiff
 */

#ifndef _PIECES_H_
#define _PIECES_H_

/**
 * Tetromino Pieces
 */
enum Piece : char
{
    PIECE_I = 'I',
    PIECE_5 = '5',
    PIECE_2 = '2',
    PIECE_T = 'T',
    PIECE_L = 'L',
    PIECE_P = 'P',
    PIECE_O = 'O'
};

/**
 * Possible rotation for pieces
 */
enum Rotation : int
{
    ROT_0   = 0,
    ROT_90  = 1,
    ROT_180 = 2,
    ROT_270 = 3
};

/**
 * Get the number of rotations for the given piece.
 *
 * @param p - Piece
 * @return Number of possible rotations
 */
int getNumberRotations(Piece p);

#endif // _PIECES_H_
