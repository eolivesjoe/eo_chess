
#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "Definitions.h"
#include "BoardState.h"
#include "Moves.h"
#include "Move.h"
#include "Board.h"
#include "Pieces.h"

class MoveGenerator 
{
public:

    MoveGenerator();

    ~MoveGenerator();

	// Moves without capture or en passant
	void AddQuietMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	// Capture moves
	void AddCaptureMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	// En passant moves
	void AddEnPassantMove(const STRUCT_BOARD_STATE* boardState, int move, STRUCT_MOVELIST* moveList);

	// generate all moves
	void generateAllMoves(STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
		Board* board, Pieces* pieces);

	// WP capture moves
	void addWhitePawnCaptureMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
		Board* board, const int from, const int to, const int capture);

	// WP non capture moves
	void addWhitePawnMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
		Board* board, const int from, const int to);

private:

};

#endif //MOVEGENERATOR_H