/*  Moves.h
    Store Struct for movelist
*/

#ifndef MOVES_H
#define MOVES_H

#include "Definitions.h"
#include "Move.h"

struct STRUCT_MOVELIST 
{
    STRUCT_MOVE moves[MAX_POSITION_MOVES];
    int count;
};

#endif //MOVES_H