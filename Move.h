
#ifndef MOVE_H
#define MOVE_H

#define MOVE_FLAG_EN_PASSANT 0x40000
#define MOVE_FLAG_PAWN_START 0x80000
#define MOVE_FLAG_CASTLE 0x1000000
#define MOVE_FLAG_CAPTURE 0x7C000

/*
    0000 0000 0000 0000 0000 0111 1111 - From -> 0x7F
    0000 0000 0000 0011 1111 1000 0000 - To -> 7, 0x7F
    0000 0000 0011 1100 0000 0000 0000 - Captured -> 14, 0xF
    0000 0000 0100 0000 0000 0000 0000 - En passant -> 0x40000
    0000 0000 1000 0000 0000 0000 0000 - Pawn start -> 0x80000
    0000 1111 0000 0000 0000 0000 0000 - Promoted -> 20, 0xF
    0001 0000 0000 0000 0000 0000 0000 - Castle -> 0x1000000
*/

struct STRUCT_MOVE
{
    int move;
    int move_score;

    // square moved from
    int fromSquare(int move);

    // square moved to
    int toSquare(int move);

    // was a piece captured
    int captured(int move);

    // was a piece promoted
    int promoted(int move);

    // create move int using from, to, capture, promotion and flag using bitwise OR
    int createMove(int from, int to, int capture, int promotion, int flag);
};

#endif //MOVE_H