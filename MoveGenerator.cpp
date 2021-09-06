/*  MoveGenerator.cpp
	Used for generating moves in the game
*/

#include "MoveGenerator.h"
#include "Utility.h"

MoveGenerator::MoveGenerator() 
{

}

MoveGenerator::~MoveGenerator() 
{

}

void MoveGenerator::AddQuietMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList)
{
	moveList->moves[moveList->count].move = move;
	moveList->moves[moveList->count].moveScore = 0;
	++moveList->count;
}

void MoveGenerator::AddCaptureMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList)
{
	moveList->moves[moveList->count].move = move;
	moveList->moves[moveList->count].moveScore = 0;
	++moveList->count;
}

void MoveGenerator::AddEnPassantMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList)
{
	moveList->moves[moveList->count].move = move;
	moveList->moves[moveList->count].moveScore = 0;
	++moveList->count;
}

void MoveGenerator::addWhitePawnCaptureMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
	Board* board, const int from, const int to, const int capture)
{
	// if we're on rank 7, add the options to promote white pawns
	if (board->getRankOnBoard()[from] == RANK_7)
	{
		AddCaptureMove(boardState, move->createMove(from, to, capture, wQ, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, wR, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, wN, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, wB, 0), moveList);
	}
}

void generateAllMoves(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList)
{
	moveList->count = 0;

	// white pawns

}