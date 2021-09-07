/*  Utility.h
    Store Utility functions used throughout the program
*/

#include <iostream>

#include "Definitions.h"

#ifndef UTILITY_H
#define UTILITY_H

// assert two integers
static bool assertIntegers(int a, int b) 
{
    if (!(a == b)) 
    {
        std::cerr << "-- Error in assert int --  " << a << " and " << b << std::endl;
        return 1;
    }
    return 0;
}

// assert two booleans
static bool assertBool(bool a)
{
    if (!(a == true))
    {
        std::cerr << "-- Error in assert bool --  " << a << std::endl;
        return 1;
    }
    return 0;
}

// check if square is on the board
static int isSquareOnBoard(const int square)
{
    if (square != NO_SQUARE)
    {
        return 0;
    }
    return 1;
}

// check if side is valid
static int isSideValid(const int side)
{
    if (side == WHITE || side == BLACK)
    {
        return 0;
    }
    return 1;
}

// check if piece is empty or valid
static int isPieceValidOrEmpty(const int piece)
{
    if (piece >= NO_PIECE || piece <= bK)
    {
        return 0;
    }
    return 1;
}

// check if piece is valid
static int isPieceValid(const int piece)
{
    if (piece >= wP || piece <= bK)
    {
        return 0;
    }
    return 1;
}

// check if rank and file is valid
static int isRankAndFileValid(const int rankfile)
{
    if (rankfile >= 0 || rankfile <= 7)
    {
        return 0;
    }
    return 1;
}

#endif // UTILITY_H