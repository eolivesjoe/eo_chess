/*  Move.cpp
    Used for all move related funcitons, such as from square, to square etc
*/

#include "Move.h"

int STRUCT_MOVE::fromSquare(int move) 
{
    return ((move) & 0x7F);
}

int STRUCT_MOVE::toSquare(int move) 
{
    return ((move >> 7) & 0x7F);
}

int STRUCT_MOVE::captured(int move) 
{
    return ((move >> 14) & 0xF);
}

int STRUCT_MOVE::promoted(int move) 
{
    return ((move >> 20) & 0xF);
}

int STRUCT_MOVE::createMove(int from, int to, int castle, int promotion, int flag)
{
    return (from) | ((to) << 7) | ((castle) << 14) | ((promotion) << 20) | (flag);
}
