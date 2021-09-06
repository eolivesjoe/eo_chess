#ifndef HASHKEY_H
#define HASHKEY_H

#include <random>

#include "Definitions.h"
#include "BoardState.h"

class HashKey 
{
public:

    HashKey();

    ~HashKey();

    // used to generate 64 bit hash keys
    U64 generate64BitHashKey();

    // generates a unique key for current board state
    U64 generatePositionKey(const STRUCT_BOARD_STATE* state);

    // getters
    U64(*getPieceHashKeys())[SQ_120];

    U64 getSideHashKey();

    U64* getCastleKeys();

private:

    // returns a reference to the random number generator
    std::mt19937& generator();

    // pieces and index on board square 
    U64 pieceHashKeys[PIECE_TYPE][SQ_120];

    // hash in rand number if white is to move
    U64 sideHashKey;

    // castle keys, 0 2 4 8, for queen and king on each side
    U64 castleKeys[16];
};

#endif //HASHKEY_H