
#include "Pieces.h"

Pieces::Pieces() {

}

Pieces::~Pieces() {

}

// getters
int* Pieces::getPieceBig() {
    return this->pieceBig;
}

int* Pieces::getPieceMajor() {
    return this->pieceMajor;
}

int* Pieces::getPieceMinor() {
    return this->pieceMinor;
}

int* Pieces::getPieceColour() {
    return this->pieceColour;
}

int* Pieces::getPieceKnight() {
    return this->pieceKnight;
}

int* Pieces::getPieceBishopOrQueen() {
    return this->pieceBishopOrQueen;
}

int* Pieces::getPieceRookOrQueen() {
    return this->pieceRookOrQueen;
}

int* Pieces::getPieceKing() {
    return this->pieceKing;
}