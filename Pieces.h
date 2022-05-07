#ifndef PIECES_H
#define PIECES_H

#include "definitions.h"

class Pieces
{
public:

    Pieces();

    ~Pieces();

    // getters
    const int* getPieceBig();
    const int* getPieceMajor();
    const int* getPieceMinor();
    const int* getPieceColour();
    const int* getPieceKnight();
    const int* getPieceBishopOrQueen();
    const int* getPieceRookOrQueen();
    const int* getPieceKing();
    const int* getSlidingPiece();
    const int* getLoopSlidingPieces();
    const int* getLoopSlidingIndex();
    const int* getNonSlidingPiece();
    const int* getLoopNonSlidingPieces();
    const int* getLoopNonSlidingIndex();
    const int(*getPieceDirections())[8];
    const int* getNumDirections();

private:

    // used to check if a piece is big, major or small, corresponds to the board pieces enum
    const int piece_big[13] = { false, false, true, true, true, true, true, false, true, true, true, true, true };
    const int piece_major[13] = { false, false, false, true, true, true, true, false, false, false, true, true, true };
    const int piece_minor[13] = { false, false, true, true, false, false, false, false, true, true, false, false, false };

    // checking type of piece, corresponds to the boardPieces enum
    const int piece_knight[13] = { false, false, true, false, false, false, false, false, true, false, false, false, false };
    const int piece_bishop_or_queen[13] = { false, false, false, true, false, true, false, false, false, true, false, true, false };
    const int piece_rook_or_queen[13] = { false, false, false, false, true, true, false, false, false, false, true, true, false };
    const int piece_king[13] = { false, false, false, false, false, false, true, false, false, false, false, false, true };

    // check sliding piece
    const int sliding_piece[13] = { false, false, false, true, true, true, false, false, false, true, true, true, false };
    const int loop_sliding_pieces[8] = { WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, 0, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, 0 };
    const int loop_sliding_index[2] = { 0, 4 };

    // check non-sliding piece
    const int non_sliding_piece[13] = { true, true, true, false, false, false, true, true, true, false, false, false, true };
    const int loop_non_sliding_pieces[8] = { WHITE_KNIGHT, WHITE_KING, 0, BLACK_KNIGHT, BLACK_KING, 0 };
    const int loop_non_sliding_index[2] = { 0, 3 };

    // used to match colour of the piece to the boardPieces enum
    const int piece_colour[13] = { BOTH, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
                                   BLACK, BLACK, BLACK, BLACK, BLACK, BLACK };

    // legal moves that corresponds to pieces in enum and the board in resources
    const int pieceDirections[13][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {-8, -12, -19, -21, 8, 12, 19, 21},
        {-9, -11, 9, 11,0,0,0,0},
        {-1 , -10, 1, 10,0,0,0,0},
        {-1, -9, -10, -11, 1, 9, 10, 11},
        {-1, -9, -10, -11, 1, 9, 10, 11},
        {0,0,0,0,0,0,0,0},
        {-8, -12, -19, -21, 8, 12, 19, 21},
        {-9, -11, 9, 11,0,0,0,0},
        {-1 , -10, 1, 10,0,0,0,0},
        {-1, -9, -10, -11, 1, 9, 10, 11},
        {-1, -9, -10, -11, 1, 9, 10, 11}
    };

    // number of directions to check for each piece
    const int numDirections[13] = { 0,0,8,4,4,8,8,0,8,4,4,8,8 };

    // value of piece, used later in milestone 2, corresponds to the boardPieces enum
    // int piece_value[13] = {0, 100, 300, 300, 500, 1000, 50000, 100, 300, 300, 500, 500, 5000};

};

#endif //PIECES_H