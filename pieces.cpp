/*  Pieces.cpp
    Store all relevant information about the pieces
*/

#include "pieces.h"

Pieces::Pieces()
{

}

Pieces::~Pieces()
{

}

// getters
const int* Pieces::getPieceBig()
{
    return this->piece_big;
}

const int* Pieces::getPieceMajor()
{
    return this->piece_major;
}

const int* Pieces::getPieceMinor()
{
    return this->piece_minor;
}

const int* Pieces::getPieceColour()
{
    return this->piece_colour;
}

const int* Pieces::getPieceKnight()
{
    return this->piece_knight;
}

const int* Pieces::getPieceBishopOrQueen()
{
    return this->piece_bishop_or_queen;
}

const int* Pieces::getPieceRookOrQueen()
{
    return this->piece_rook_or_queen;
}

const int* Pieces::getPieceKing()
{
    return this->piece_king;
}

const int* Pieces::getSlidingPiece()
{
    return this->sliding_piece;
}

const int* Pieces::getLoopSlidingPieces()
{
    return this->loop_sliding_pieces;
}

const int* Pieces::getLoopSlidingIndex()
{
    return this->loop_sliding_index;
}

const int* Pieces::getNonSlidingPiece()
{
    return this->non_sliding_piece;
}

const int* Pieces::getLoopNonSlidingPieces()
{
    return this->loop_non_sliding_pieces;
}

const int* Pieces::getLoopNonSlidingIndex()
{
    return this->loop_non_sliding_index;
}

const int(*Pieces::getPieceDirections())[8]
{
    return this->pieceDirections;
}

const int* Pieces::getNumDirections()
{
    return this->numDirections;
}