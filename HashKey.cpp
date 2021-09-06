/*  HashKey.cpp
    Used to generate a hash key for every board position used
*/

#include <iostream>

#include "HashKey.h"

HashKey::HashKey() 
{
    this->sideHashKey = generate64BitHashKey();

    for (int i = 0; i != PIECE_TYPE; ++i)
    {
        for (int j = 0; j != SQ_120; ++j) 
        {
            this->pieceHashKeys[i][j] = generate64BitHashKey();
        }
    }

    for (int i = 0; i != 16; ++i) 
    {
        castleKeys[i] = generate64BitHashKey();
    }
}

HashKey::~HashKey() 
{

}

std::mt19937& HashKey::generator() 
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    return generator;
}

U64 HashKey::generate64BitHashKey() 
{
    std::uniform_int_distribution<unsigned long long> distributer;
    U64 key = distributer(generator());

    return key;
}

U64 HashKey::generatePositionKey(const STRUCT_BOARD_STATE* state) 
{
    U64 positionKey = 0;
    int piece = NO_PIECE;

    for (int i = 0; i != SQ_120; ++i)
    {
        piece = state->pieces[i];

        if (piece != NO_SQUARE && piece != NO_PIECE) 
        {
            if (piece >= wP && piece <= bK) 
            {
                positionKey ^= this->pieceHashKeys[piece][i];

            }
            else 
            {
                std::cerr << "ERROR in generation position key -- pieces";
                return EXIT_FAILURE;
            }
        }
    }

    if (state->sideToMove == WHITE) 
    {
        positionKey ^= this->sideHashKey;
    }

    if (state->enPassant != NO_SQUARE) 
    {
        if (state->enPassant >= 0 && state->enPassant <= SQ_120) 
        {
            positionKey ^= pieceHashKeys[NO_PIECE][state->enPassant];

        }
        else 
        {
            std::cerr << "ERROR in generation position key -- en passant";
            return EXIT_FAILURE;
        }
    }

    if (state->castlePermission >= 0 && state->castlePermission <= 15) 
    {
        positionKey ^= castleKeys[state->castlePermission];

    }
    else 
    {
        std::cerr << "ERROR in generation position key -- castle permission";
        return EXIT_FAILURE;
    }

    return positionKey;
}

U64(*HashKey::getPieceHashKeys())[SQ_120] 
{
    return this->pieceHashKeys;
}

U64 HashKey::getSideHashKey()
{
    return this->sideHashKey;
}

U64* HashKey::getCastleKeys() 
{
    return this->castleKeys;
}