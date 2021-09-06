
#include <iostream>

#include "BitBoard.h"

BitBoard::BitBoard() {

    for (int i = 0; i != SQ_64; ++i) {
        this->setBitMask[i] = 0ULL;
        this->clearBitMask[i] = 0ULL;
    }

    for (int i = 0; i != SQ_64; ++i) {
        this->setBitMask[i] |= (1ULL << i);
        this->clearBitMask[i] = ~this->setBitMask[i];
    }
}

BitBoard::~BitBoard() {

}

bool BitBoard::bitExists(int square64, U64& pieceBitBoard) {
    bool outcome = false;
    if ((shifter << square64) & pieceBitBoard) {
        outcome = true;
    }

    return outcome;
}

bool BitBoard::setBit(int square, U64& pieceBitBoard) {
    bool outcome = false;
    if ((pieceBitBoard) |= (this->setBitMask[(square)])) {
        outcome = true;
    }

    return outcome;
}

bool BitBoard::clearBit(int square, U64& pieceBitBoard) {
    bool outcome = false;
    if ((pieceBitBoard) &= (this->clearBitMask[(square)])) {
        outcome = true;
    }

    return outcome;
}



int BitBoard::countBits(U64& pieceBitBoard) {
    int numBits;
    for (numBits = 0; pieceBitBoard; ++numBits, pieceBitBoard &= pieceBitBoard - 1);
    return numBits;
}

U64 BitBoard::getShifter() {
    return this->shifter;
}

const int* BitBoard::getBitTable() {
    return this->bitTable;
}