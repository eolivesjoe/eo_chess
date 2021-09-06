#ifndef PIECES_H
#define PIECES_H

#include "Definitions.h"

class Pieces 
{
public:

    Pieces();

    ~Pieces();

    // getters
    int* getPieceBig();
    int* getPieceMajor();
    int* getPieceMinor();
    int* getPieceColour();
    int* getPieceKnight();
    int* getPieceBishopOrQueen();
    int* getPieceRookOrQueen();
    int* getPieceKing();

private:

    // used to check if a piece is big, major or small, corresponds to the boardPieces enum
    int pieceBig[13] = { false, false, true, true, true, true, true, false, true, true, true, true, true };
    int pieceMajor[13] = { false, false, false, true, true, true, true, false, false, false, true, true, true };
    int pieceMinor[13] = { false, false, true, true, false, false, false, false, true, true, false, false, false };

    // checking type of piece, corresponds to the boardPieces enum
    int pieceKnight[13] = { false, false, true, false, false, false, false, false, true, false, false, false, false };
    int pieceBishopOrQueen[13] = { false, false, false, true, false, true, false, false, false, true, false, true, false };
    int pieceRookOrQueen[13] = { false, false, false, false, true, true, false, false, false, false, true, true, false };
    int pieceKing[13] = { false, false, false, false, false, false, true, false, false, false, false, false, true };

    // used to match colour of the piece to the boardPieces enum
    int pieceColour[13] = { BOTH, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
                           BLACK, BLACK, BLACK, BLACK, BLACK, BLACK };

    // value of piece, used later in milestone 2, corresponds to the boardPieces enum
    // int pieceValue[13] = {0, 100, 300, 300, 500, 1000, 50000, 100, 300, 300, 500, 500, 5000};

};

#endif //PIECES_H