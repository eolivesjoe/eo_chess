/*  HashKey.cpp
    Used to generate a hash key for every board position used
*/

#include <iostream>

#include "hash_key.h"

HashKey::HashKey()
{
    this->side_hash_key = generate64BitHashKey();

    for (int i = 0; i != PIECE_TYPE; ++i)
    {
        for (int j = 0; j != SQ_120; ++j)
        {
            this->piece_hash_keys[i][j] = generate64BitHashKey();
        }
    }

    for (int i = 0; i != 16; ++i)
    {
        this->castle_keys[i] = generate64BitHashKey();
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
    U64 position_key = 0;
    int piece = NO_PIECE;

    for (int i = 0; i != SQ_120; ++i)
    {
        piece = state->pieces[i];

        if (piece != NO_SQUARE && piece != NO_PIECE)
        {
            //TODO: Use util
            if (piece >= WHITE_PAWN && piece <= BLACK_KING)
            {
                position_key ^= this->piece_hash_keys[piece][i];

            }
            else
            {
                std::cerr << "ERROR in generation position key -- pieces";
                return EXIT_FAILURE;
            }
        }
    }

    if (state->side_to_move == WHITE)
    {
        position_key ^= this->side_hash_key;
    }

    if (state->en_passant != NO_SQUARE)
    {
        if (state->en_passant >= 0 && state->en_passant <= SQ_120)
        {
            position_key ^= piece_hash_keys[NO_PIECE][state->en_passant];

        }
        else
        {
            std::cerr << "ERROR in generation position key -- en passant";
            return EXIT_FAILURE;
        }
    }

    if (state->castle_permission >= 0 && state->castle_permission <= 15)
    {
        position_key ^= castle_keys[state->castle_permission];

    }
    else
    {
        std::cerr << "ERROR in generation position key -- castle permission";
        return EXIT_FAILURE;
    }

    return position_key;
}

U64(*HashKey::getPieceHashKeys())[SQ_120]
{
    return this->piece_hash_keys;
}

U64 HashKey::getSideHashKey()
{
    return this->side_hash_key;
}

U64* HashKey::getCastleKeys()
{
    return this->castle_keys;
}