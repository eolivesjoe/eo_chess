/*  Main.cpp
    Main entry point of the program
*/

#include <iostream>
#include <iomanip>

#include "Definitions.h"
#include "Writer.h"
#include "Board.h"
#include "BitBoard.h"
#include "Pieces.h"
#include "HashKey.h"
#include "BoardState.h"
#include "Attack.h"
#include "Move.h"

void run();

int main(int argc, char const* argv[])
{
    run();
    return 0;
}

void run() 
{
    STRUCT_BOARD_STATE* state = new STRUCT_BOARD_STATE();
    Board* board = new Board();
    HashKey* key = new HashKey();
    Writer* w = new Writer();
    Pieces* pieces = new Pieces();
    BitBoard* bitboard = new BitBoard();
    Attack* attack = new Attack();
    STRUCT_MOVE* m = new STRUCT_MOVE();

    // const char* e4 = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
    // const char* d5 = "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
    // const char* nf3 = "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2";
    // const char* randomBoardState = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
    // const char* pawnAttackCheck = "8/8/3p4/8/8/3P4/8/8 w KQkq - 0 1";
    // const char* knightAttackCheck = "8/8/3n4/8/8/3N4/8/8 w KQkq - 0 1";
    // const char* rookAttackCheck = "8/8/3r4/8/8/3R4/8/8 w KQkq - 0 1";
    // const char* bishopAttackCheck = "8/8/3b4/8/8/3B4/8/8 w KQkq - 0 1";
    // const char* queenAttackCheck = "8/8/3q4/8/8/3Q4/8/8 w KQkq - 0 1";
    // const char* kingAttackCheck = "8/8/3k4/8/8/3K4/8/8 w KQkq - 0 1";
    const char* blockTest = "8/3q1p2/8/3Q1P2/8/8/8/8 w KQkq - 0 1";

    std::cout << "STANDARD BOARD\n";
    board->readFENString(blockTest, state, key, pieces, bitboard);
    w->printBoard(board, state);

    std::cout << "\n";

    // std::cout << "WHITE PAWNS\n";
    // w->printBitBoard(bitboard, board, state->pawns[WHITE]);
    // std::cout << "\n";

    // std::cout << "BLACK PAWNS\n";
    // w->printBitBoard(bitboard, board, state->pawns[BLACK]);
    // std::cout << "\n";

    // std::cout << "ALL PAWNS\n";
    // w->printBitBoard(bitboard, board, state->pawns[BOTH]);
    // std::cout << "\n";

    std::cout << "\n";

    board->checkBoard(state, pieces);

    w->printAttackedSquares(board, WHITE, state, attack, pieces);

    std::cout << "\n";

    w->printAttackedSquares(board, BLACK, state, attack, pieces);

    std::cout << "\n";

    int move = 0;
    int from = A2;
    int to = H7;
    int cap = wR;
    int promoted = bK;

    move = ((from) | (to << 7) | (cap << 14) | (promoted << 20));

    std::cout << "from: " << std::dec << m->fromSquare(move) << std::endl
        << "to: " << std::dec << m->toSquare(move) << std::endl
        << "cap: " << std::dec << m->captured(move) << std::endl
        << "promoted: " << std::dec << m->promoted(move) << std::endl;

    std::cout << "Algebraic from: " << w->printSquare(from, board) << "\n";
    std::cout << "Algebraic to: " << w->printSquare(to, board) << "\n";
    std::cout << "Algebraic Move: " << w->printMove(move, m, board, pieces) << "\n";

    delete state;
    delete board;
    delete key;
    delete w;
    delete pieces;
    delete bitboard;
    delete attack;
    delete m;
}