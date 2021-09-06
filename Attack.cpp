/*  Attack.cpp
    Store functions to calculate which squares are under attack
*/

#include "Attack.h"
#include "Utility.h"

Attack::Attack()
{

}

Attack::~Attack() 
{

}

bool Attack::squareAttacked(Board* board, const int square, const int side, STRUCT_BOARD_STATE* boardState, Pieces* pieces) 
{
    bool outcome = false;

    // checks
    isSquareOnBoard(board->getFileOnBoard()[square]);
    isSideValid(side);
    board->checkBoard(boardState, pieces);
    

    // pawns
    if (side == WHITE) 
    {
        if (boardState->pieces[square - 11] == wP || boardState->pieces[square - 9] == wP)
        {
            outcome = true;
        }
    }
    else 
    {
        if (boardState->pieces[square + 11] == bP || boardState->pieces[square + 9] == bP) 
        {
            outcome = true;
        }
    }

    // knights
    for (int i = 0; i != 8; ++i) 
    {
        int piece = boardState->pieces[square + this->knightSquares[i]];

        if (square != NO_SQUARE) 
        {
            if (pieces->getPieceColour()[piece] == side && pieces->getPieceKnight()[piece])
                outcome = true;
        }
    }

    // bishop, queen
    for (int i = 0; i != 4; ++i) 
    {
        int direction = this->bishopSquares[i];
        int tempSquare = square + direction;
        int piece = boardState->pieces[tempSquare];
        bool pathBlocked = false;

        while (piece != NO_SQUARE && !pathBlocked) 
        {

            if (piece != NO_PIECE) 
            {
                if (pieces->getPieceBishopOrQueen()[piece] && pieces->getPieceColour()[piece] == side)
                {
                    outcome = true;
                }
                pathBlocked = true;
            }
            tempSquare += direction;
            piece = boardState->pieces[tempSquare];
        }
    }

    // rook, queen
    for (int i = 0; i != 4; ++i)
    {
        int direction = this->rookSquares[i];
        int tempSquare = square + direction;
        int piece = boardState->pieces[tempSquare];
        bool pathBlocked = false;

        while (piece != NO_SQUARE && !pathBlocked) 
        {

            if (piece != NO_PIECE) 
            {
                if (pieces->getPieceRookOrQueen()[piece] && pieces->getPieceColour()[piece] == side) 
                {
                    outcome = true;
                }
                pathBlocked = true;
            }
            tempSquare += direction;
            piece = boardState->pieces[tempSquare];
        }
    }

    // king
    for (int i = 0; i != 8; ++i)
    {
        int piece = boardState->pieces[square + this->kingSquares[i]];

        if (square != NO_SQUARE)
        {
            if (pieces->getPieceColour()[piece] == side && pieces->getPieceKing()[piece]) 
            {
                outcome = true;
            }
        }
    }

    return outcome;
}

