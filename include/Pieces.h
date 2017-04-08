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
enum Rotation
{
    ROT_0,
    ROT_90,
    ROT_180,
    ROT_270
};

#endif // _PIECES_H_
