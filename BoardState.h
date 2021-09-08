/*  BoardState.h
    Used for all information relevant to the current board state
*/

#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include "Definitions.h"

// struct for undo move
struct STRUCT_UNDO_MOVE 
{
    // board move
    int move;

    // store bits for castling
    int castlePermission;

    //store en passant
    int enPassant;

    // store fifty move rule
    int fiftyMoves;

    // store unique key for every position
    U64 positionKey;
};

// general board struct
struct  STRUCT_BOARD_STATE 
{
    // store value of the board
    int pieces[SQ_120];

    // store white, black and both as bitboards
    U64 pawns[3];

    // store the squares kings are on
    int KingSquare[2];

    int castlePermission;

    // store side to move
    int sideToMove;

    int enPassant;

    // store fifty move rule
    int fiftyMoves;

    // store how many half moves we're into the current search
    int ply;

    // store how many half moves have been made in the total game
    int historyPly;

    U64 positionKey;

    // store number of each type of piece
    int pieceNumber[PIECE_TYPE];

    // store square for each piece per piece type
    int pieceList[PIECE_TYPE][PIECE_NUMBER];

    // store anything that isn't a pawn for white, black and both
    int bigPieces[2];

    // same for queens and rooks
    int majorPieces[2];

    // same for knights and bishops
    int minorPieces[2];

    // keep track of material for black and white
    int materialCounter[2];

    STRUCT_UNDO_MOVE gameHistory[MAX_GAME_MOVES];
};

#endif // BOARDSTATE_H