
#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "Definitions.h"
#include "BoardState.h"
#include "Moves.h"
#include "Move.h"
#include "Board.h"

class MoveGenerator 
{
public:

    MoveGenerator();

    ~MoveGenerator();

	void AddQuietMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void AddCaptureMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void AddEnPassantMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void generateAllMoves(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList);

	void addWhitePawnCaptureMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
		Board* board, const int from, const int to, const int capture);

private:

};

#endif //MOVEGENERATOR_H