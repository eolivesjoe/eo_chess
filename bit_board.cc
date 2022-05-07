/*  BitBoard.cpp
    Used for the bitboards used by the pawns
*/

#include <iostream>

#include "bit_board.h"

BitBoard::BitBoard()
{

    for (int i = 0; i != SQ_64; ++i)
    {
        this->set_bit_mask[i] = 0ULL;
        this->clear_bit_mask[i] = 0ULL;
    }

    for (int i = 0; i != SQ_64; ++i)
    {
        this->set_bit_mask[i] |= (1ULL << i);
        this->clear_bit_mask[i] = ~this->set_bit_mask[i];
    }
}

BitBoard::~BitBoard()
{

}

bool BitBoard::bitExists(int square_64, U64& piece_bit_board)
{
    bool outcome = false;
    if ((shifter << square_64) & piece_bit_board)
    {
        outcome = true;
    }

    return outcome;
}

bool BitBoard::setBit(int square, U64& piece_bit_board)
{
    bool outcome = false;
    if ((piece_bit_board) |= (this->set_bit_mask[(square)]))
    {
        outcome = true;
    }

    return outcome;
}

bool BitBoard::clearBit(int square, U64& piece_bit_board)
{
    bool outcome = false;
    if ((piece_bit_board) &= (this->clear_bit_mask[(square)]))
    {
        outcome = true;
    }

    return outcome;
}



int BitBoard::countBits(U64& piece_bit_board)
{
    int num_bits;
    for (num_bits = 0; piece_bit_board; ++num_bits, piece_bit_board &= piece_bit_board - 1);
    return num_bits;
}

U64 BitBoard::getShifter()
{
    return this->shifter;
}

const int* BitBoard::getBitTable()
{
    return this->bit_table;
}