/*  Main.cpp
    Main entry point of the program
*/

#include <iostream>
#include <iomanip>

#include "utility.h"
#include "definitions.h"
#include "board_state.h"
#include "hash_key.h"
#include "pieces.h"
#include "bit_board.h"
#include "board.h"
#include "writer.h"
#include "move_generator.h"

void run();

int main(int argc, char const* argv[])
{
    run();
    return 0;
}

void run()
{
    STRUCT_BOARD_STATE* board_state = new STRUCT_BOARD_STATE();
    HashKey* hash_key = new HashKey();
    Pieces* pieces = new Pieces();
    BitBoard* bit_board = new BitBoard();
    Board* board = new Board();
    MoveGenerator* move_gen = new MoveGenerator();
    Attack* attack = new Attack();

    STRUCT_MOVE_LIST* move_list = new STRUCT_MOVE_LIST();
    STRUCT_MOVE* move = new STRUCT_MOVE();

    Writer* w = new Writer();



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
    // const char* blockTest = "8/3q1p2/8/3Q1P2/8/8/8/8 w KQkq - 0 1";
    // const char* PAWNTESTW = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
    // const char* PAWNTESTB = "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1";
    // const char* NONSLIDE = "5k2/1n6/4n3/6N1/8/3N4/8/5K2 w - - 0 1";
    // const char* SLIDEROOK = "6k1/8/5r2/8/1nR5/5N2/8/6K1 b - - 0 1";
    // const char* SLIDEQUEEN = "6k1/8/4nq1/8/1nQ5/5N2/1N6/6K1 b - - 0 1";
    // const char* SLIDEBISHOP = "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 b - - 0 1";
    // const char* CASTLING = "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1";
    const char* MOVEGENTEST = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";

    std::cout << "STANDARD BOARD\n";
    board->readFENString(MOVEGENTEST, board_state, hash_key, pieces, bit_board);
    w->printBoard(board, board_state);

    std::cout << "\n";
    std::cout << "\n";

    w->printAttackedSquares(board, BLACK, board_state, attack, pieces);

    std::cout << "\n";
    std::cout << "\n";

    move_gen->generateAllMoves(board_state, move_list, move, board, pieces, attack, w);
    w->printMoveList(move_list, move, board, pieces);


    std::cout << "\n";
    std::cout << "\n";

    delete board_state;
    delete hash_key;
    delete pieces;
    delete bit_board;
    delete board;
    delete w;
    delete move_list;
    delete move;
    delete attack;
}
