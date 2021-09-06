
// TODO
// supressed for sprintf
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>

#include "Writer.h"

Writer::Writer() {
    this->pieceChar = ".PNBRQKpnbrqk";
    this->sideChar = "wb-";
    this->rankChar = "12345678";
    this->fileChar = "abcdefgh";
}

Writer::~Writer() {

}

void Writer::print120Board(Board* board) {
    for (int i = 0; i != SQ_120; ++i) {
        if (i % 10 == 0) {
            std::cout << "\n";
        }
        std::cout << std::setw(3) << board->getSq120To64()[i];
    }
}

void Writer::print64Board(Board* board) {
    for (int i = 0; i != SQ_64; ++i) {
        if (i % 8 == 0) {
            std::cout << "\n";
        }
        std::cout << std::setw(3) << board->getSq64To120()[i];
    }
}


void Writer::printBitBoard(BitBoard* bitBoard, Board* board, U64& pieceBitBoard) {

    int file = 0;
    int rank = 0;
    int square = 0; // index in 120 board
    int square64 = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank) {
        for (file = FILE_A; file <= FILE_H; ++file) {
            square = board->fileAndRankToBoard120Index(file, rank);
            square64 = board->getSq120To64()[square];

            if (bitBoard->bitExists(square64, pieceBitBoard)) {
                std::cout << std::setw(3) << "X";
            }
            else {
                std::cout << std::setw(3) << "-";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
}

void Writer::printBoard(Board* board, STRUCT_BOARD_STATE* state) {
    int rank = 0;
    int file = 0;
    int square = 0;
    int piece = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank) {
        std::cout << rankChar[rank] << " ";

        for (file = FILE_A; file <= FILE_H; ++file) {
            square = board->fileAndRankToBoard120Index(file, rank);
            piece = state->pieces[square];
            std::cout << std::setw(3) << pieceChar[piece];
        }

        if (rank == RANK_7) {
            std::cout << "    move:       " << sideChar[state->sideToMove];
        }
        else if (rank == RANK_6) {
            std::cout << "    castle:     " << state->castlePermission;
        }
        else if (rank == RANK_5) {
            std::cout << "    en passant: " << state->enPassant;
        }
        else if (rank == RANK_4) {
            std::cout << "    hash key:   " << state->positionKey;
        }


        std::cout << "\n";

        if (rank == RANK_1) {

            std::cout << "\n";

            std::cout << "  ";
            for (file = FILE_A; file <= FILE_H; ++file) {
                std::cout << std::setw(3) << fileChar[file];
            }
            std::cout << "\n";
        }
    }
}

void Writer::printAttackedSquares(Board* board, const int side, STRUCT_BOARD_STATE* state, Attack* attack, Pieces* pieces) {

    int file = 0;
    int rank = 0;
    int square = 0;

    for (rank = RANK_8; rank >= RANK_1; --rank) {
        for (file = FILE_A; file <= FILE_H; ++file) {
            square = board->fileAndRankToBoard120Index(file, rank);

            if (attack->squareAttacked(square, side, state, pieces)) {
                std::cout << std::setw(3) << "X";
            }
            else {
                std::cout << std::setw(3) << "-";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
}

char* Writer::printSquare(const int square, Board* board) {
    static char squareString[3];

    int file = board->getFileOnBoard()[square];
    int rank = board->getRankOnBoard()[square];

    std::sprintf(squareString, "%c%c", ('a' + file), ('1' + rank));

    return squareString;
}

char* Writer::printMove(const int move, STRUCT_MOVE* m, Board* board, Pieces* pieces) {
    static char moveString[6];

    int fileFrom = board->getFileOnBoard()[m->fromSquare(move)];
    int fileTo = board->getFileOnBoard()[m->toSquare(move)];
    int rankFrom = board->getRankOnBoard()[m->fromSquare(move)];
    int rankTo = board->getRankOnBoard()[m->toSquare(move)];

    int promoted = m->promoted(move);

    if (promoted) {
        char promotedChar = 'q';

        if (pieces->getPieceKnight()[promoted]) {
            promotedChar = 'n';
        }
        else if (pieces->getPieceBishopOrQueen()[promoted] && !pieces->getPieceRookOrQueen()[promoted]) {
            promotedChar = 'b';
        }
        else if (!pieces->getPieceBishopOrQueen()[promoted] && pieces->getPieceRookOrQueen()[promoted]) {
            promotedChar = 'r';
        }
        std::sprintf(moveString, "%c%c%c%c%c", ('a' + fileFrom), ('1' + rankFrom), ('a' + fileTo), ('1' + rankTo), promotedChar);
    }
    else {
        std::sprintf(moveString, "%c%c%c%c", ('a' + fileFrom), ('1' + rankFrom), ('a' + fileTo), ('1' + rankTo));
    }

    return moveString;
}



void Writer::printHeader() {
    std::cout << R"(
        __          __  _                            _                      _____ _                   
        \ \        / / | |                          | |                    / ____| |                  
         \ \  /\  / /__| | ___ ___  _ __ ___   ___  | |_ ___     ___  ___ | |    | |__   ___  ___ ___ 
          \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \   / _ \/ _ \| |    | '_ \ / _ \/ __/ __|
           \  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | |  __/ (_) | |____| | | |  __/\__ \__ \
            \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/   \___|\___/ \_____|_| |_|\___||___/___/
                                                                                               
    )" << "\n";
}