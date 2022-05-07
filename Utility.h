
#include <iostream>

#include "definitions.h"

#ifndef UTILITY_H
#define UTILITY_H

namespace Utility
{
    // assert two integers
    bool assertIntegers(int a, int b);

    // assert two booleans
    bool assertBool(bool a);

    // check if square is on the board
    bool assertSquare(const int square);

    // check if side is valid
    bool assertValidSide(const int side);

    // check if piece is empty or valid
    bool assertPieceOrEmpty(const int piece);

    // check if piece is valid
    bool assertPieceValid(const int piece);

    // check if rank and file is valid
    bool assertRankAndFileValid(const int rankfile);

}

#endif // UTILITY_H