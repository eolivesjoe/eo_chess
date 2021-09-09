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
    if (a != b) 
    {
        std::cerr << "-- Error in assert int --  " << a << " and " << b << std::endl;
        return false;
    }
    return true;
}

// assert two booleans
static bool assertBool(bool a)
{
    if (!a)
    {
        std::cerr << "-- Error in assert bool --  " << a << std::endl;
        return false;
    }
    return true;
}

// check if square is on the board
static bool sqOnBoard(const int square)
{
    if (square == NO_SQUARE)
    {
        std::cerr << "-- Square is not on board --  " << square << std::endl;
        return false;
    }
    std::cout << square << std::endl;
    return true;
}

// check if side is valid
static bool isSideValid(const int side)
{
    if (!side == WHITE || !side == BLACK)
    {
        std::cerr << "-- Error in valid side check --  " << side << std::endl;
        return false;
    }
    return true;
}

// check if piece is empty or valid
static bool isPieceValidOrEmpty(const int piece)
{
    if (piece < NO_PIECE || piece > bK)
    {
        std::cerr << "-- Error in valid piece or empty --  " << piece << std::endl;
        return false;
    }
    return true;
}

// check if piece is valid
static bool isPieceValid(const int piece)
{
    if ((piece < wP) || (piece > bK))
    {
        std::cerr << "-- Error in valid piece --  " << piece << std::endl;
        return false;
    }
    return true;
}

// check if rank and file is valid
static bool isRankAndFileValid(const int rankfile)
{
    if (rankfile < 0 || rankfile > 7)
    {
        std::cerr << "-- Error in valid rank and file --  " << rankfile << std::endl;
        return false;
    }
    return true;
}

#endif // UTILITY_H