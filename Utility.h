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
static bool sqOnBoard(const int square)
{
    if (square == NO_SQUARE)
    {
        std::cerr << "-- Square is not on board --  " << square << std::endl;
        return false;
    }
    return true;
}

//// check if side is valid
//static bool isSideValid(const int side)
//{
//    if (!side == WHITE || !side == BLACK)
//    {
//        return false;
//    }
//    return true;
//}
//
//// check if piece is empty or valid
//static bool isPieceValidOrEmpty(const int piece)
//{
//    if (!piece >= NO_PIECE && !piece <= bK)
//    {
//        return false;
//    }
//    return true;
//}
//
//// check if piece is valid
//static bool isPieceValid(const int piece)
//{
//    if (!piece >= wP && !piece <= bK)
//    {
//        return false;
//    }
//    return true;
//}
//
//// check if rank and file is valid
//static bool isRankAndFileValid(const int rankfile)
//{
//    if (!rankfile >= 0 || !rankfile <= 7)
//    {
//        return false;
//    }
//    return true;
//}

#endif // UTILITY_H