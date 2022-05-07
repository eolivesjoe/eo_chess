#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>

#define U64 unsigned long long

// 1024 max moves
#define MAX_GAME_MOVES 2048

// max moves for any given position
#define MAX_POSITION_MOVES 256

// starting board position for FEN representation
#define START_POS_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

#define SQ_64 64
#define SQ_120 120

#define PIECE_TYPE 13
#define PIECE_NUMBER 10

// board ranks
enum boardRanks
{
    RANK_1,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    NO_RANK
};

// board files
enum boardFiles
{
    FILE_A,
    FILE_B,
    FILE_C,
    FILE_D,
    FILE_E,
    FILE_F,
    FILE_G,
    FILE_H,
    NO_FILE
};

//pieces
enum boardPieces
{
    NO_PIECE,
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING
};

// piece colours
enum pieceColours
{
    WHITE,
    BLACK,
    BOTH
};

//board squares
enum squares
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQUARE
};

enum castling
{
    WHITE_KING_CASTLING = 1,
    WHITE_QUEEN_CASTLING = 2,
    BLACK_KING_CASTLING = 4,
    BLACK_QUEEN_CASTLING = 8
};

#endif // DEFINITIONS_H