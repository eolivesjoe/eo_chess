#ifndef WRITER_H
#define WRITER_H

#include <iostream>

#include "Board.h"
#include "BoardState.h"
#include "Attack.h"
#include "Pieces.h"
#include "Move.h"

class Writer 
{
public:

    Writer();

    ~Writer();

    // standard board printing with correct indexing
    void print120Board(Board* board);
    void print64Board(Board* board);

    // prints bit board
    void printBitBoard(BitBoard* bitBoard, Board* board, U64& pieceBitBoard);

    // print chess board
    void printBoard(Board* board, STRUCT_BOARD_STATE* state);

    // print squares under attack
    void printAttackedSquares(Board* board, const int side, STRUCT_BOARD_STATE* state, Attack* attack, Pieces* pieces);

    // print square in move
    char* printSquare(const int square, Board* board);

    // print move made
    char* printMove(const int move, STRUCT_MOVE* m, Board* board, Pieces* pieces);

    // print header
    void printHeader();


private:

    const char* pieceChar;
    const char* sideChar;
    const char* rankChar;
    const char* fileChar;

};

#endif // WRITER_H