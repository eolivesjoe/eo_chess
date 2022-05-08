/*  Writer.cpp
    All functions that prints things are stored here
*/


// TODO
// supressed for sprintf
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>

#include "writer.h"

Writer::Writer()
{
    this->piece_char = ".PNBRQKpnbrqk";
    this->side_char = "wb-";
    this->rank_char = "12345678";
    this->file_char = "abcdefgh";
}

Writer::~Writer()
{

}

void Writer::print120Board(Board* board)
{
    for (int i = 0; i != SQ_120; ++i)
    {
        if (i % 10 == 0)
        {
            std::cout << "\n";
        }
        std::cout << std::setw(3) << board->getSq120To64()[i];
    }
}

void Writer::print64Board(Board* board)
{
    for (int i = 0; i != SQ_64; ++i)
    {
        if (i % 8 == 0)
        {
            std::cout << "\n";
        }
        std::cout << std::setw(3) << board->getSq64To120()[i];
    }
}


void Writer::printBitBoard(BitBoard* bit_board, Board* board, U64& piece_bit_board)
{
    int file = 0;
    int rank = 0;
    int square = 0; // index in 120 board
    int square64 = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank)
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            square = board->fileAndRankToBoard120Index(file, rank);
            square64 = board->getSq120To64()[square];

            if (bit_board->bitExists(square64, piece_bit_board))
            {
                std::cout << std::setw(3) << "X";
            }
            else
            {
                std::cout << std::setw(3) << "-";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
}

void Writer::printBoard(Board* board, STRUCT_BOARD_STATE* state)
{
    int rank = 0;
    int file = 0;
    int square = 0;
    int piece = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank)
    {
        std::cout << rank_char[rank] << " ";

        for (file = FILE_A; file <= FILE_H; ++file)
        {
            square = board->fileAndRankToBoard120Index(file, rank);
            piece = state->pieces[square];
            std::cout << std::setw(3) << piece_char[piece];
        }

        if (rank == RANK_7)
        {
            std::cout << "    move:       " << side_char[state->side_to_move];
        }
        else if (rank == RANK_6)
        {
            std::cout << "    castle:     " << state->castle_permission;
        }
        else if (rank == RANK_5)
        {
            std::cout << "    en passant: " << state->en_passant;
        }
        else if (rank == RANK_4)
        {
            std::cout << "    hash key:   " << state->position_key;
        }


        std::cout << "\n";

        if (rank == RANK_1)
        {
            std::cout << "\n";
            std::cout << "  ";

            for (file = FILE_A; file <= FILE_H; ++file)
            {
                std::cout << std::setw(3) << file_char[file];
            }
            std::cout << "\n";
        }
    }
}

void Writer::printAttackedSquares(Board* board, const int side, STRUCT_BOARD_STATE* state, Attack* attack, Pieces* pieces)
{
    int file = 0;
    int rank = 0;
    int square = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank)
    {
        for (file = FILE_A; file <= FILE_H; ++file)
        {
            square = board->fileAndRankToBoard120Index(file, rank);

            if (attack->squareAttacked(board, square, side, state, pieces))
            {
                std::cout << std::setw(3) << "o";
            }
            else
            {
                std::cout << std::setw(3) << "-";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
}

char* Writer::printSquare(const int square, Board* board)
{
    static char square_string[3];

    int file = board->getFileOnBoard()[square];
    int rank = board->getRankOnBoard()[square];

    std::sprintf(square_string, "%c%c", ('a' + file), ('1' + rank));

    return square_string;
}

char* Writer::printMove(const int move, STRUCT_MOVE* m, Board* board, Pieces* pieces)
{
    static char move_string[6];

    int file_from = board->getFileOnBoard()[m->fromSquare(move)];
    int file_to = board->getFileOnBoard()[m->toSquare(move)];
    int rank_from = board->getRankOnBoard()[m->fromSquare(move)];
    int rank_to = board->getRankOnBoard()[m->toSquare(move)];
    int promoted = m->promoted(move);

    if (promoted)
    {
        char promoted_char = 'q';

        if (pieces->getPieceKnight()[promoted])
        {
            promoted_char = 'n';
        }
        else if (pieces->getPieceBishopOrQueen()[promoted] && !pieces->getPieceRookOrQueen()[promoted])
        {
            promoted_char = 'b';
        }
        else if (!pieces->getPieceBishopOrQueen()[promoted] && pieces->getPieceRookOrQueen()[promoted])
        {
            promoted_char = 'r';
        }
        std::sprintf(move_string, "%c%c%c%c%c", ('a' + file_from), ('1' + rank_from), ('a' + file_to), ('1' + rank_to), promoted_char);
    }
    else
    {
        std::sprintf(move_string, "%c%c%c%c", ('a' + file_from), ('1' + rank_from), ('a' + file_to), ('1' + rank_to));
    }

    return move_string;
}

void Writer::printMoveList(STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* m, Board* board, Pieces* pieces)
{
    for (int i = 0; i != move_list->count; ++i)
    {
        int move = move_list->moves[i].move;
        int score = move_list->moves[i].move_score;

        std::cout << "Move: " << i + 1 << " < " << printMove(move, m, board, pieces) << " score: " << score << "\n";
    }
    std::cout << "Total moves: " << move_list->count << "\n";
}