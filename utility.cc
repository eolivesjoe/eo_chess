/*  utility.cpp
    Store Utility functions used throughout the program
*/

#include "utility.h"

namespace Utility
{

    // assert two integers
    bool assertIntegers(int a, int b)
    {
        if (a != b)
        {
            std::cerr << "-- Error in assert int --  " << a << " and " << b << std::endl;
            return false;
        }
        return true;
    }

    // assert boolean
    bool assertBool(bool a)
    {
        if (!a)
        {
            std::cerr << "-- Error in assert bool --  " << a << std::endl;
            return false;
        }
        return true;
    }

    // check if square is on the board
    bool assertSquare(const int square)
    {
        if (square == NO_SQUARE)
        {
            // std::cerr << "-- Square is not on board --  " << square << std::endl;
            return false;
        }
        // std::cout << square << std::endl;
        return true;
    }

    // check if side is valid
    bool assertValidSide(const int side)
    {
        if (side != WHITE || side != BLACK)
        {
            std::cerr << "-- Error in valid side check --  " << side << std::endl;
            return false;
        }
        return true;
    }

    // check if piece is empty or valid
    bool assertPieceOrEmpty(const int piece)
    {
        if (piece < NO_PIECE || piece > BLACK_KING)
        {
            std::cerr << "-- Error in valid piece or empty --  " << piece << std::endl;
            return false;
        }
        return true;
    }

    // check if piece is valid
    bool assertPieceValid(const int piece)
    {
        if ((piece < WHITE_PAWN) || (piece > BLACK_KING))
        {
            std::cerr << "-- Error in valid piece --  " << piece << std::endl;
            return false;
        }
        return true;
    }

    // check if rank and file is valid
    bool assertRankAndFileValid(const int rankfile)
    {
        if (rankfile < 0 || rankfile > 7)
        {
            std::cerr << "-- Error in valid rank and file --  " << rankfile << std::endl;
            return false;
        }
        return true;
    }
}