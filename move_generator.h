
#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "definitions.h"
#include "board_state.h"
#include "moves.h"
#include "move.h"
#include "board.h"
#include "pieces.h"
#include "attack.h"
#include "utility.h"

#include "writer.h"

class MoveGenerator
{
public:

	MoveGenerator();

	~MoveGenerator();

	// Moves without capture or en passant
	void addQuietMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list);

	// Capture moves
	void addCaptureMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list);

	// En passant moves
	void addEnPassantMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list);

	// generate all moves
	void generateAllMoves(STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
		Board* board, Pieces* pieces, Attack* attack, Writer* w);

	// WP capture moves
	void addWhitePawnCaptureMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
		Board* board, const int from, const int to, const int capture);

	// BP capture moves
	void addBlackPawnCaptureMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
		Board* board, const int from, const int to, const int capture);

	// WP non capture moves
	void addWhitePawnMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
		Board* board, const int from, const int to);

	// BP non capture moves
	void addBlackPawnMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
		Board* board, const int from, const int to);

private:

};

#endif //MOVEGENERATOR_H