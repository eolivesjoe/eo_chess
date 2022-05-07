/*  Moves.h
    Store Struct for movelist
*/

#ifndef MOVES_H
#define MOVES_H

#include "definitions.h"
#include "move.h"

struct STRUCT_MOVE_LIST
{
    STRUCT_MOVE moves[MAX_POSITION_MOVES];
    int count;
};

#endif //MOVES_H