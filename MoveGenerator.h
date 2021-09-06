
#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "Definitions.h"
#include "BoardState.h"
#include "Moves.h"

class MoveGenerator 
{
public:

    MoveGenerator();

    ~MoveGenerator();

	void AddQuietMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void AddCaptureMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void AddEnPassantMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	void generateAllMoves(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList);

private:

};

#endif //MOVEGENERATOR_H