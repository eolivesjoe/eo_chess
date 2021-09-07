#ifndef BOARD_H
#define BOARD_H

#include "Definitions.h"
#include "BoardState.h"
#include "HashKey.h"
#include "Pieces.h"
#include "BitBoard.h"

class Board 
{
public:

    Board();

    ~Board();

    // init square arrays
    void init120To64();

    // init arrays that return the file and rank for a square
    void initFileAndRankCheck();

    // returns 120 board square index from a file and rank
    int fileAndRankToBoard120Index(int file, int rank);

    // reset board to original state
    void resetBoard(STRUCT_BOARD_STATE* position);

    // make sure FEN string is valid
    bool checkFENString(const char* fen, STRUCT_BOARD_STATE* state);

    // read in position string
    int readFENString(const char* fen, STRUCT_BOARD_STATE* state, HashKey* key, Pieces* pieces, BitBoard* bitBoard);

    // update all lists containing material information
    void updateMaterialLists(STRUCT_BOARD_STATE* state, Pieces* pieces, BitBoard* bitBoard);

    // check that the board is correct after a change
    bool checkBoard(STRUCT_BOARD_STATE* state);

    // getters
    int* getSq120To64();
    int* getSq64To120();
    int* getFileOnBoard();
    int* getRankOnBoard();

private:

    // 120 and 64 square arrays used for the board
    int sq120to64[SQ_120];
    int sq64to120[SQ_64];

    // used to find which rank and file the square is on
    int fileOnBoard[SQ_120];
    int rankOnBoard[SQ_120];

};

#endif // BOARD_H