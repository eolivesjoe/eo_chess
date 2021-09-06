/*  MoveGenerator.cpp
	Used for generating moves in the game
*/

#include "MoveGenerator.h"

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

void generateAllMoves(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList)
{
	moveList->count = 0;

	// white pawns

}