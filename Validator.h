
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Definitions.h"

// will be used for various validation checks throughout the program
struct STRUCT_VALIDATOR 
{
    // check if square is on the board
    int isSquareOnBoard(const int square) {
        if (square != NO_SQUARE) {
            return 0;
        }
        return 1;
    }
};

#endif // VALIDATOR_H