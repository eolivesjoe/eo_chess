#ifndef BITBOARD_H
#define BITBOARD_H

#include "definitions.h"

class BitBoard
{
public:

    BitBoard();

    ~BitBoard();

    // check if bit exists on square
    bool bitExists(int square_64, U64& piece_bit_board);

    // set bit on square
    bool setBit(int square, U64& piece_bit_board);

    // clear bit on square
    bool clearBit(int square, U64& piece_bit_board);

    // count all bits set to 1 on the bit board
    int countBits(U64& piece_bit_board);

    // getters
    U64 getShifter();
    const int* getBitTable();

private:

    // shifter used to move bits when checking
    U64 shifter = 1ULL;

    //  bit table
    const int bit_table[SQ_64] = {
        63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
        51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
        26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
        58, 20, 37, 17, 36, 8
    };

    // bit masks used to set and clear bit board
    U64 set_bit_mask[SQ_64];
    U64 clear_bit_mask[SQ_64];

};

#endif // BITBOARD_H