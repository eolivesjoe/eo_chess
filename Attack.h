#ifndef ATTACK_H
#define ATTACK_H

#include "board_state.h"
#include "pieces.h"
#include "board.h"

class Attack
{
public:
    Attack();

    ~Attack();

    // Return if square is attacked or not
    bool squareAttacked(Board* board, const int square, const int side, STRUCT_BOARD_STATE* board_state, Pieces* pieces);

private:

    // attacking squares for pieces
    int knight_squares[8] = { -21, -19, -12, -8, 8, 12, 19, 21 };
    int rook_squares[4] = { -10, -1, 1, 10 };
    int bishop_squares[4] = { -11, -9, 9, 11 };
    int king_squares[8] = { -11, -10, -9, -1, 1, 9, 10, 11 };
};

#endif // ATTACK_H