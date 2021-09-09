/*  Main.cpp
    Main entry point of the program
*/

#include <iostream>
#include <iomanip>

#include "Utility.h"
#include "Definitions.h"
#include "BoardState.h"
#include "HashKey.h"
#include "Pieces.h"
#include "BitBoard.h"
#include "Board.h"
#include "Writer.h"
#include "MoveGenerator.h"

void run();

int main(int argc, char const* argv[])
{
    run();
    return 0;
}

void run()
{
    STRUCT_BOARD_STATE* boardState = new STRUCT_BOARD_STATE();
    HashKey* key = new HashKey();
    Pieces* pieces = new Pieces();
    BitBoard* bitBoard = new BitBoard();
    Board* board = new Board();
    MoveGenerator* moveGen = new MoveGenerator();

    STRUCT_MOVELIST* moveList = new STRUCT_MOVELIST();
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
    const char* PAWNTESTW = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
    const char* PAWNTESTB = "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1";

    std::cout << "STANDARD BOARD\n";
    board->readFENString(PAWNTESTB, boardState, key, pieces, bitBoard);
    w->printBoard(board, boardState);

    std::cout << "\n";
    std::cout << "\n";

    moveGen->generateAllMoves(boardState, moveList, move, board, pieces);
    w->printMoveList(moveList, move, board, pieces);

    std::cout << "\n";
    std::cout << "\n";

    delete boardState;
    delete key;
    delete pieces;
    delete bitBoard;
    delete board;
    delete w;
    delete moveList;
    delete move;
}
