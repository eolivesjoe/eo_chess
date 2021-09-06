
#ifndef MOVES_H
#define MOVES_H

#include "Definitions.h"
#include "Move.h"


// struct to store moves
struct STRUCT_MOVES 
{
    STRUCT_MOVE moves[MAX_POSITION_MOVES];
    int count;
};

#endif //MOVES_H