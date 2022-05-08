/*  Board.cpp
    Used for all functions that deals with the board. Setting up File and Ranks etc..
*/

#include <iostream>
#include <iomanip>

#include "board.h"
#include "utility.h"

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
    int square_120 = A1;
    int square_64 = 0;

    for (int i = 0; i != SQ_120; ++i) {

        this->square_120_to_64[i] = NO_SQUARE;
    }

    for (int i = 0; i != SQ_64; ++i)
    {
        this->square_64_to_120[i] = NO_SQUARE;
    }

    for (rank = RANK_1; rank <= RANK_8; ++rank)
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            square_120 = fileAndRankToBoard120Index(file, rank);

            this->square_64_to_120[square_64] = square_120;
            this->square_120_to_64[square_120] = square_64;

            ++square_64;
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
            state->piece_list[i][j] = 0;
        }
    }

    for (int i = 0; i != 2; ++i)
    {
        state->big_pieces[i] = 0;
        state->major_pieces[i] = 0;
        state->minor_pieces[i] = 0;
        state->material_counter[i] = 0;
    }

    for (int i = 0; i != PIECE_TYPE; ++i)
    {
        state->piece_number[i] = 0;
    }

    state->en_passant = NO_SQUARE;
    state->side_to_move = BOTH;
    state->castle_permission = 0;

    state->king_square[WHITE] = NO_SQUARE;
    state->king_square[BLACK] = NO_SQUARE;

    state->fifty_moves = 0;
    state->ply = 0;
    state->history_ply = 0;

    state->position_key = 0ULL;
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

int Board::readFENString(const char* fen, STRUCT_BOARD_STATE* state, HashKey* hash_key, Pieces* pieces, BitBoard* bit_board)
{
    checkFENString(fen, state);

    resetBoard(state);
    checkBoard(state);

    int rank = RANK_8;
    int file = FILE_A;
    int piece = NO_PIECE;
    int castle = 0;

    int square_64 = 0;
    int square_120 = 0;
    int counter = 0;

    bool end_of_pieces = false;
    bool end_of_castle = false;

    while ((rank >= RANK_1) && *fen && !end_of_pieces)
    {
        counter = 1;

        // black pieces
        if (*fen == 'r')
        {
            piece = BLACK_ROOK;
        }
        else if (*fen == 'n')
        {
            piece = BLACK_KNIGHT;
        }
        else if (*fen == 'b')
        {
            piece = BLACK_BISHOP;
        }
        else if (*fen == 'q')
        {
            piece = BLACK_QUEEN;
        }
        else if (*fen == 'k')
        {
            piece = BLACK_KING;
        }
        else if (*fen == 'p')
        {
            piece = BLACK_PAWN;

            // white pieces
        }
        else if (*fen == 'R')
        {
            piece = WHITE_ROOK;
        }
        else if (*fen == 'N')
        {
            piece = WHITE_KNIGHT;
        }
        else if (*fen == 'B')
        {
            piece = WHITE_BISHOP;
        }
        else if (*fen == 'Q')
        {
            piece = WHITE_QUEEN;
        }
        else if (*fen == 'K')
        {
            piece = WHITE_KING;
        }
        else if (*fen == 'P')
        {
            piece = WHITE_PAWN;

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
            end_of_pieces = true;

        }
        else
        {
            std::cerr << "Error in fen parsing, end of readFENString";
            return EXIT_FAILURE;
        }

        // set piece on correct square
        for (int i = 0; i != counter; ++i)
        {
            square_64 = rank * 8 + file;
            square_120 = getSq64To120()[square_64];

            if (piece != NO_PIECE)
            {
                state->pieces[square_120] = piece;
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
        state->side_to_move = WHITE;
    }
    else
    {
        state->side_to_move = BLACK;
    }

    fen += 2;

    // castling
    while (castle != 4 && !end_of_castle)
    {
        if (*fen == 'K')
        {
            state->castle_permission |= WHITE_KING_CASTLING;
        }
        else if (*fen == 'Q')
        {
            state->castle_permission |= WHITE_QUEEN_CASTLING;
        }
        else if (*fen == 'k')
        {
            state->castle_permission |= BLACK_KING_CASTLING;
        }
        else if (*fen == 'q')
        {
            state->castle_permission |= BLACK_QUEEN_CASTLING;
        }
        else if (*fen == ' ')
        {
            end_of_castle = true;
        }
        ++castle;

        if (!end_of_castle)
        {
            ++fen;
        }
    }
    ++fen;

    // castle check
    if (state->castle_permission < 0 || state->castle_permission > 15)
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
            std::cerr << "Error in fen parsing, en passant\n";
            return EXIT_FAILURE;
        }
        state->en_passant = fileAndRankToBoard120Index(file, rank);
    }

    state->position_key = hash_key->generatePositionKey(state);
    updateMaterialLists(state, pieces, bit_board);
    return EXIT_SUCCESS;
}

void Board::updateMaterialLists(STRUCT_BOARD_STATE* state, Pieces* pieces, BitBoard* bit_board)
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
                state->big_pieces[colour]++;
            }
            if (pieces->getPieceMajor()[piece])
            {
                state->major_pieces[colour]++;
            }
            if (pieces->getPieceMinor()[piece])
            {
                state->minor_pieces[colour]++;
            }

            // TODO:
            // used later to count up the total value of material
            // state->material_counter[colour] += pieces->piece_value[piece]

            // update pieceList and how many of the piece
            state->piece_list[piece][state->piece_number[piece]] = i;
            state->piece_number[piece]++;

            if (piece == WHITE_KING_CASTLING)
            {
                state->king_square[WHITE] = i;
            }

            if (piece == BLACK_KING)
            {
                state->king_square[BLACK] = i;
            }

            if (piece == WHITE_PAWN)
            {
                bit_board->setBit(square_120_to_64[i], state->pawns[WHITE]);
                bit_board->setBit(square_120_to_64[i], state->pawns[BOTH]);

            }
            else if (piece == BLACK_PAWN)
            {
                bit_board->setBit(square_120_to_64[i], state->pawns[BLACK]);
                bit_board->setBit(square_120_to_64[i], state->pawns[BOTH]);
            }
        }
    }
}

void Board::initFileAndRankCheck()
{
    for (int i = 0; i != SQ_120; ++i)
    {
        this->file_on_board[i] = NO_SQUARE;
        this->rank_on_board[i] = NO_SQUARE;
    }

    for (int rank = RANK_1; rank <= RANK_8; ++rank)
    {
        for (int file = FILE_A; file <= FILE_H; ++file)
        {
            int square = fileAndRankToBoard120Index(file, rank);
            this->file_on_board[square] = file;
            this->rank_on_board[square] = rank;
        }
    }
}

bool Board::checkBoard(STRUCT_BOARD_STATE* state)
{
    int temp_piece = 0;
    int square_64 = 0;
    int square_120 = 0;
    // int piece_count = 0;

    int temp_piece_number[PIECE_TYPE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    // int temp_major_pieces[2] = { 0, 0 };
    // int temp_heavy_pieces[2] = { 0, 0 };
    // int temp_minor_pieces[2] = { 0, 0 };
    // int temp_material[2] = {0, 0};

    // U64 temp_pawns[3] = {0ULL, 0ULL, 0ULL};
    // temp_pawns[WHITE] = state->pawns[WHITE];
    // temp_pawns[BLACK] = state->pawns[BLACK];
    // temp_pawns[BOTH] = state->pawns[BOTH];

    // check piece lists
    // TODO: Use the util function
    for (temp_piece = WHITE_PAWN; temp_piece <= BLACK_KING; ++temp_piece)
    {
        for (int temp_piece_num = 0; temp_piece_num != state->piece_number[temp_piece]; ++temp_piece_num)
        {
            square_120 = state->piece_list[temp_piece][temp_piece_num];
            Utility::assertIntegers(state->pieces[square_120], temp_piece);
        }
    }

    // check piece count and material counter
    for (square_64 = 0; square_64 != SQ_64; ++square_64)
    {

        // convert to 120sq index, look at the piece and increment the temp piece number
        square_120 = this->square_64_to_120[square_64];
        temp_piece = state->pieces[square_120];
        temp_piece_number[temp_piece]++;


        // TODO: Replace heavy_p[colour]
        //if (state->heavy_[temp_piece])
        //{
        //    temp_heavy_p[temp_piece]++;
        //}

        //if (state->big_pieces[temp_piece]) 
        //{
        //    temp_big_pieces[temp_piece]++;
        //}

        //if (state->minor_pieces[temp_piece]) 
        //{
        //    temp_minor_pieces[temp_piece]++;
        //}

         //TODO: 
         //used later for the piece values
         //temp_material[colour] += piece_val
    }

    // check piecenumber array
    //TODO: use util function
    for (temp_piece = WHITE_PAWN; temp_piece <= BLACK_KING; ++temp_piece)
    {
        Utility::assertIntegers(temp_piece_number[temp_piece], state->piece_number[temp_piece]);
    }

    // TODO:
    // check bitboards squares and counts

    // check material, min and major pieces

    // check en passant and kingsquare 

    return true;
}

int* Board::getSq120To64()
{
    return this->square_120_to_64;
}

int* Board::getSq64To120()
{
    return this->square_64_to_120;
}

int* Board::getFileOnBoard()
{
    return this->file_on_board;
}

int* Board::getRankOnBoard()
{
    return this->rank_on_board;
}