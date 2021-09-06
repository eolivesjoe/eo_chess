#ifndef ATTACK_H
#define ATTACK_H

#include "BoardState.h"
#include "Pieces.h"

class Attack 
{
public:
    Attack();

    ~Attack();

    // Return if square is attacked or not
    bool squareAttacked(const int square, const int side, STRUCT_BOARD_STATE* boardState, Pieces* pieces);

private:

    // attacking squares for pieces
    int knightSquares[8] = { -21, -19, -12, -8, 8, 12, 19, 21 };
    int rookSquares[4] = { -10, -1, 1, 10 };
    int bishopSquares[4] = { -11, -9, 9, 11 };
    int kingSquares[8] = { -11, -10, -9, -1, 1, 9, 10, 11 };
};

#endif // ATTACK_H