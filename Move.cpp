
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
