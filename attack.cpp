/*  Attack.cpp
    Store functions to calculate which squares are under attack
*/

#include "attack.h"
#include "utility.h"

Attack::Attack()
{

}

Attack::~Attack()
{

}

bool Attack::squareAttacked(Board* board, const int square, const int side, STRUCT_BOARD_STATE* board_state, Pieces* pieces)
{
    bool outcome = false;

    // checks
    Utility::assertSquare(square);
    //isSideValid(side);
    Utility::assertBool(board->checkBoard(board_state));



    // pawns
    if (side == WHITE)
    {
        if (board_state->pieces[square - 11] == WHITE_PAWN || board_state->pieces[square - 9] == WHITE_PAWN)
        {
            outcome = true;
        }
    }
    else
    {
        if (board_state->pieces[square + 11] == BLACK_PAWN || board_state->pieces[square + 9] == BLACK_PAWN)
        {
            outcome = true;
        }
    }

    // knights
    for (int i = 0; i != 8; ++i)
    {
        int piece = board_state->pieces[square + this->knight_squares[i]];

        if (Utility::assertSquare(board->getSq120To64()[square + this->knight_squares[i]]))
        {
            if (pieces->getPieceColour()[piece] == side && pieces->getPieceKnight()[piece])
                outcome = true;
        }
    }

    // bishop, queen
    for (int i = 0; i != 4; ++i)
    {
        int direction = this->bishop_squares[i];
        int temp_square = square + direction;
        int piece = board_state->pieces[temp_square];
        bool path_blocked = false;

        while (piece != NO_SQUARE && !path_blocked)
        {

            if (piece != NO_PIECE)
            {
                if (pieces->getPieceBishopOrQueen()[piece] && pieces->getPieceColour()[piece] == side)
                {
                    outcome = true;
                }
                path_blocked = true;
            }
            temp_square += direction;
            piece = board_state->pieces[temp_square];
        }
    }

    // rook, queen
    for (int i = 0; i != 4; ++i)
    {
        int direction = this->rook_squares[i];
        int temp_square = square + direction;
        int piece = board_state->pieces[temp_square];
        bool path_blocked = false;

        while (piece != NO_SQUARE && !path_blocked)
        {

            if (piece != NO_PIECE)
            {
                if (pieces->getPieceRookOrQueen()[piece] && pieces->getPieceColour()[piece] == side)
                {
                    outcome = true;
                }
                path_blocked = true;
            }
            temp_square += direction;
            piece = board_state->pieces[temp_square];
        }
    }

    // king
    for (int i = 0; i != 8; ++i)
    {
        int piece = board_state->pieces[square + this->king_squares[i]];

        if (Utility::assertSquare(board->getSq120To64()[square + this->king_squares[i]]))
        {
            if (pieces->getPieceColour()[piece] == side && pieces->getPieceKing()[piece])
            {
                outcome = true;
            }
        }
    }

    return outcome;
}

