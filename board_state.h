/*  BoardState.h
    Used for all information relevant to the current board state
*/

#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include "definitions.h"

// struct for undo move
struct STRUCT_UNDO_MOVE
{
    // board move
    int move;

    // store bits for castling
    int castle_permission;

    //store en passant
    int en_passant;

    // store fifty move rule
    int fifty_moves;

    // store unique key for every position
    U64 position_key;
};

// general board struct
struct  STRUCT_BOARD_STATE
{
    // store value of the board, pass in a square and see which piece is on it
    int pieces[SQ_120];

    // store white, black and both as bitboards
    U64 pawns[3];

    // store the squares kings are on
    int king_square[2];

    int castle_permission;

    // store side to move
    int side_to_move;

    int en_passant;

    // store fifty move rule
    int fifty_moves;

    // store how many half moves we're into the current search
    int ply;

    // store how many half moves have been made in the total game
    int history_ply;

    U64 position_key;

    // store how many of each type of piece on the board
    int piece_number[PIECE_TYPE];

    // store square for every piece on the board. type of piece and n of that type
    int piece_list[PIECE_TYPE][PIECE_NUMBER];

    // store anything that isn't a pawn for white, black and both
    int big_pieces[2];

    // same for queens and rooks
    int major_pieces[2];

    // same for knights and bishops
    int minor_pieces[2];

    // keep track of material for black and white
    int material_counter[2];

    STRUCT_UNDO_MOVE game_history[MAX_GAME_MOVES];
};

#endif // BOARDSTATE_H