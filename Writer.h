#ifndef WRITER_H
#define WRITER_H

#include <iostream>

#include "board.h"
#include "board_state.h"
#include "attack.h"
#include "pieces.h"
#include "move.h"
#include "moves.h"

class Writer
{
public:

    Writer();

    ~Writer();

    // standard board printing with correct indexing
    void print120Board(Board* board);
    void print64Board(Board* board);

    // prints bit board
    void printBitBoard(BitBoard* bit_board, Board* board, U64& piece_bit_board);

    // print chess board
    void printBoard(Board* board, STRUCT_BOARD_STATE* state);

    // print squares under attack
    void printAttackedSquares(Board* board, const int side, STRUCT_BOARD_STATE* state, Attack* attack, Pieces* pieces);

    // print square in move
    char* printSquare(const int square, Board* board);

    // print move made
    char* printMove(const int move, STRUCT_MOVE* m, Board* board, Pieces* pieces);

    // print move list
    void printMoveList(STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* m, Board* board, Pieces* pieces);

private:

    const char* piece_char;
    const char* side_char;
    const char* rank_char;
    const char* file_char;

};

#endif // WRITER_H