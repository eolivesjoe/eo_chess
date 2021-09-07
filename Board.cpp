/*  Board.cpp
    Used for all functions that deals with the board. Setting up File and Ranks etc..
*/

#include <iostream>
#include <iomanip>

#include "Board.h"
#include "Utility.h"

Board::Board() 
{
    init120To64();
    initFileAndRankCheck();
}

Board::~Board()
{

}

int Board::fileAndRankToBoard120Index(int file, int rank) 
{
    return (file + 21) + (rank * 10);
}

void Board::init120To64() 
{
    int file = FILE_A;
    int rank = RANK_1;
    int square120 = A1;
    int square64 = 0;

    for (int i = 0; i != SQ_120; ++i) {

        sq120to64[i] = INVALID_SQ;
    }

    for (int i = 0; i != SQ_64; ++i) 
    {
        sq64to120[i] = INVALID_SQ;
    }

    for (rank = RANK_1; rank <= RANK_8; ++rank) 
    {
        for (file = FILE_A; file <= FILE_H; ++file) 
        {
            square120 = fileAndRankToBoard120Index(file, rank);

            sq64to120[square64] = square120;
            sq120to64[square120] = square64;

            ++square64;
        }
    }
}

void Board::resetBoard(STRUCT_BOARD_STATE* state) 
{
    for (int i = 0; i != SQ_120; ++i) 
    {
        state->pieces[i] = NO_SQUARE;
    }

    for (int i = 0; i != SQ_64; ++i) 
    {
        state->pieces[this->getSq64To120()[i]] = NO_PIECE;
    }

    for (int i = 0; i != 3; ++i) 
    {
        state->pawns[i] = 0ULL;
    }

    for (int i = 0; i != PIECE_TYPE; ++i) 
    {
        for (int j = 0; j != PIECE_NUMBER; ++j) 
        {
            state->pieceList[i][j] = 0;
        }
    }

    for (int i = 0; i != 2; ++i) 
    {
        state->bigPieces[i] = 0;
        state->majorPieces[i] = 0;
        state->minorPieces[i] = 0;
        state->materialCounter[i] = 0;
    }

    for (int i = 0; i != PIECE_TYPE; ++i) 
    {
        state->pieceNumber[i] = 0;
    }

    state->enPassant = NO_SQUARE;
    state->sideToMove = BOTH;
    state->castlePermission = 0;

    state->KingSquare[WHITE] = NO_SQUARE;
    state->KingSquare[BLACK] = NO_SQUARE;

    state->fiftyMoves = 0;
    state->ply = 0;
    state->historyPly = 0;

    state->positionKey = 0ULL;
}

bool Board::checkFENString(const char* fen, STRUCT_BOARD_STATE* state) 
{
    if (fen == nullptr || state == nullptr) 
    {
        std::cerr << "Error in readFENString -- Board.cpp";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int Board::readFENString(const char* fen, STRUCT_BOARD_STATE* state, HashKey* key, Pieces* pieces, BitBoard* bitboard) 
{
    checkFENString(fen, state);

    resetBoard(state);

    int rank = RANK_8;
    int file = FILE_A;
    int piece = NO_PIECE;
    int castle = 0;

    int square64 = 0;
    int square120 = 0;
    int counter = 0;

    bool endOfPieces = false;
    bool endOfCastle = false;

    while ((rank >= RANK_1) && *fen && !endOfPieces) 
{
        counter = 1;

        // black pieces
        if (*fen == 'r') 
        {
            piece = bR;
        }
        else if (*fen == 'n') 
        {
            piece = bN;
        }
        else if (*fen == 'b') 
        {
            piece = bB;
        }
        else if (*fen == 'q') 
        {
            piece = bQ;
        }
        else if (*fen == 'k') 
        {
            piece = bK;
        }
        else if (*fen == 'p') 
        {
            piece = bP;

            // white pieces
        }
        else if (*fen == 'R') 
        {
            piece = wR;
        }
        else if (*fen == 'N') 
        {
            piece = wN;
        }
        else if (*fen == 'B') 
        {
            piece = wB;
        }
        else if (*fen == 'Q')
        {
            piece = wQ;
        }
        else if (*fen == 'K') 
        {
            piece = wK;
        }
        else if (*fen == 'P') 
        {
            piece = wP;

            // empty squares
        }
        else if (*fen == '1' || *fen == '2' || *fen == '3' || *fen == '4' ||
            *fen == '5' || *fen == '6' || *fen == '7' || *fen == '8') 
        {
            piece = NO_PIECE;
            counter = *fen - '0';

            // divider in FEN string
        }
        else if (*fen == '/') 
        {
            if (rank > RANK_1) 
            {
                --rank;
            }

            file = FILE_A;

            // end loop if we've reached the end of the pieces
        }
        else if (*fen == ' ') 
        {
            piece = NO_PIECE;
            endOfPieces = true;

        }
        else 
        {
            std::cerr << "Error in fen parsing, end of readFENString";
            return EXIT_FAILURE;
        }

        // set piece on correct square
        for (int i = 0; i != counter; ++i) 
        {
            square64 = rank * 8 + file;
            square120 = getSq64To120()[square64];

            if (piece != NO_PIECE) 
            {
                state->pieces[square120] = piece;
            }

            // // reset to no piece
            piece = NO_PIECE;

            // if we just changed rank, don't increment file
            if (*fen != '/') 
            {
                ++file;
            }
        }
        ++fen;
    }

    if (*fen != 'w' && *fen != 'b')
    {
        std::cerr << "Error in fen parsing, side to move error";
        return EXIT_FAILURE;
    }

    // side to move
    if (*fen == 'w') 
    {
        state->sideToMove = WHITE;
    }
    else 
    {
        state->sideToMove = BLACK;
    }

    fen += 2;

    // castling
    while (castle != 4 && !endOfCastle) 
    {
        if (*fen == 'K') 
        {
            state->castlePermission |= wKCastling;
        }
        else if (*fen == 'Q') 
        {
            state->castlePermission |= wQCastling;
        }
        else if (*fen == 'k')
        {
            state->castlePermission |= bKCastling;
        }
        else if (*fen == 'q') 
        {
            state->castlePermission |= bQCastling;
        }
        else if (*fen == ' ') 
        {
            endOfCastle = true;
        }
        ++castle;
        ++fen;
    }
    ++fen;

    // castle check
    if (state->castlePermission < 0 || state->castlePermission > 15) 
    {
        std::cerr << "Error in fen parsing, Castle permission error";
        return EXIT_FAILURE;
    }


    // en passant
    if (*fen != '-') 
    {
        file = fen[0] - 'a';
        rank = fen[1] - '1';

        if ((file < FILE_A || file > FILE_H) || (rank < RANK_1 || rank > RANK_8)) 
        {
            std::cerr << "Error in fen parsing, en passant";
            return EXIT_FAILURE;
        }
        state->enPassant = fileAndRankToBoard120Index(file, rank);
    }

    state->positionKey = key->generatePositionKey(state);
    updateMaterialLists(state, pieces, bitboard);
    return EXIT_SUCCESS;
}

void Board::updateMaterialLists(STRUCT_BOARD_STATE* state, Pieces* pieces, BitBoard* bitboard) 
{
    int piece = 0;
    int colour = 0;

    for (int i = 0; i != SQ_120; ++i)
    {
        piece = state->pieces[i];

        if (piece != NO_SQUARE && piece != NO_PIECE) 
        {
            colour = pieces->getPieceColour()[piece];

            // update material arrays
            if (pieces->getPieceBig()[piece]) 
            {
                state->bigPieces[colour]++;
            }
            if (pieces->getPieceMajor()[piece]) 
            {
                state->majorPieces[colour]++;
            }
            if (pieces->getPieceMinor()[piece]) 
            {
                state->minorPieces[colour]++;
            }

            // TODO:
            // used later to count up the total value of material
            // state->materialCounter[colour] += pieces->pieceValue[piece]

            // update pieceList and how many of the piece
            state->pieceList[piece][state->pieceNumber[piece]] = i;
            state->pieceNumber[piece]++;

            if (piece == wK)
            {
                state->KingSquare[WHITE] = i;
            }

            if (piece == bK) 
            {
                state->KingSquare[BLACK] = i;
            }

            if (piece == wP) 
            {
                bitboard->setBit(sq120to64[i], state->pawns[WHITE]);
                bitboard->setBit(sq120to64[i], state->pawns[BOTH]);

            }
            else if (piece == bP) 
            {
                bitboard->setBit(sq120to64[i], state->pawns[BLACK]);
                bitboard->setBit(sq120to64[i], state->pawns[BOTH]);
            }
        }
    }
}

void Board::initFileAndRankCheck() 
{
    for (int i = 0; i != SQ_120; ++i) 
    {
        this->fileOnBoard[i] = NO_SQUARE;
        this->rankOnBoard[i] = NO_SQUARE;
    }

    for (int rank = RANK_1; rank <= RANK_8; ++rank) 
    {
        for (int file = FILE_A; file <= FILE_H; ++file) 
        {
            int square = fileAndRankToBoard120Index(file, rank);
            this->fileOnBoard[square] = file;
            this->rankOnBoard[square] = rank;
        }
    }
}

bool Board::checkBoard(STRUCT_BOARD_STATE* state) 
{
    int tempPiece = 0;
    int square64 = 0;
    int square120 = 0;
    // int pieceCount = 0;

    int tempPieceNumber[PIECE_TYPE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int tempMajorPieces[2] = { 0, 0 };
    int tempBigPieces[2] = { 0, 0 };
    int tempMinorPieces[2] = { 0, 0 };
    // int tempMaterial[2] = {0, 0};

    // U64 tempPawns[3] = {0ULL, 0ULL, 0ULL};
    // tempPawns[WHITE] = state->pawns[WHITE];
    // tempPawns[BLACK] = state->pawns[BLACK];
    // tempPawns[BOTH] = state->pawns[BOTH];

    // check piece lists
    for (tempPiece = wP; tempPiece <= bK; ++tempPiece) 
    {
        for (int tempPieceNum = 0; tempPieceNum != state->pieceNumber[tempPiece]; ++tempPieceNum) 
        {
            square120 = state->pieceList[tempPiece][tempPieceNum];
            assertIntegers(state->pieces[square120], tempPiece);
        }
    }

    // check piece count and material counter
    for (square64 = 0; square64 != SQ_64; ++square64) 
    {

        // convert to 120sq index, look at the piece and increment the temp piece number
        square120 = this->sq64to120[square64];
        tempPiece = state->pieces[square120];
        tempPieceNumber[tempPiece]++;

        if (state->majorPieces[tempPiece])
        {
            tempMajorPieces[tempPiece]++;
        }

        if (state->bigPieces[tempPiece]) 
        {
            tempBigPieces[tempPiece]++;
        }

        if (state->minorPieces[tempPiece]) 
        {
            tempMinorPieces[tempPiece]++;
        }

        // TODO: 
        // used later for the piece values
        // tempMaterial[colour] += PieceVal
    }

    // check piecenumber array
    for (tempPiece = wP; tempPiece <= bK; ++tempPiece) 
    {
        assertIntegers(tempPieceNumber[tempPiece], state->pieceNumber[tempPiece]);
    }

    // TODO:
    // check bitboards squares and counts

    // check material, min and major pieces

    // check en passant and kingsquare 

    return true;
}

int* Board::getSq120To64() 
{
    return this->sq120to64;
}

int* Board::getSq64To120() 
{
    return this->sq64to120;
}

int* Board::getFileOnBoard() 
{
    return this->fileOnBoard;
}

int* Board::getRankOnBoard()
{
    return this->rankOnBoard;
}