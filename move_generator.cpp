/*  MoveGenerator.cpp
	Used for generating moves in the game
*/

#include "move_generator.h"

MoveGenerator::MoveGenerator()
{

}

MoveGenerator::~MoveGenerator()
{

}

void MoveGenerator::addQuietMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list)
{
	move_list->moves[move_list->count].move = move;
	move_list->moves[move_list->count].move_score = 0;
	++move_list->count;
}

void MoveGenerator::addCaptureMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list)
{
	move_list->moves[move_list->count].move = move;
	move_list->moves[move_list->count].move_score = 0;
	++move_list->count;
}

void MoveGenerator::addEnPassantMove(const STRUCT_BOARD_STATE* board_state, int move, STRUCT_MOVE_LIST* move_list)
{
	move_list->moves[move_list->count].move = move;
	move_list->moves[move_list->count].move_score = 0;
	++move_list->count;
}

// non capture moves for white pawns
void MoveGenerator::addWhitePawnMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
	Board* board, const int from, const int to)
{
	// checks
	Utility::assertSquare(from);
	Utility::assertSquare(to);

	// if we're on rank 7, add the options to promote white pawns
	if (board->getRankOnBoard()[from] == RANK_7)
	{
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, WHITE_QUEEN, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, WHITE_ROOK, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, WHITE_KNIGHT, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, WHITE_BISHOP, 0), move_list);
	}
	else
	{
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, NO_PIECE, 0), move_list);
	}
}

void MoveGenerator::addWhitePawnCaptureMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
	Board* board, const int from, const int to, const int capture)
{
	// checks
	Utility::assertPieceOrEmpty(capture);
	Utility::assertSquare(from);
	Utility::assertSquare(to);

	// if we're on rank 7, add the options to promote white pawns
	if (board->getRankOnBoard()[from] == RANK_7)
	{
		addCaptureMove(board_state, move->createMove(from, to, capture, WHITE_QUEEN, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, WHITE_ROOK, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, WHITE_KNIGHT, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, WHITE_BISHOP, 0), move_list);
	}
	else
	{
		addCaptureMove(board_state, move->createMove(from, to, capture, NO_PIECE, 0), move_list);
	}
}

// non capture moves for black pawns
void MoveGenerator::addBlackPawnMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
	Board* board, const int from, const int to)
{
	// checks
	Utility::assertSquare(from);
	Utility::assertSquare(to);

	// if we're on rank 2, add the options to promote black pawns
	if (board->getRankOnBoard()[from] == RANK_2)
	{
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, BLACK_QUEEN, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, BLACK_ROOK, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, BLACK_KNIGHT, 0), move_list);
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, BLACK_BISHOP, 0), move_list);
	}
	else
	{
		addQuietMove(board_state, move->createMove(from, to, NO_PIECE, NO_PIECE, 0), move_list);
	}
}

void MoveGenerator::addBlackPawnCaptureMove(const STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
	Board* board, const int from, const int to, const int capture)
{
	// checks
	Utility::assertPieceOrEmpty(capture);
	Utility::assertSquare(from);
	Utility::assertSquare(to);

	// if we're on rank 2, add the options to promote black pawns
	if (board->getRankOnBoard()[from] == RANK_2)
	{
		addCaptureMove(board_state, move->createMove(from, to, capture, BLACK_QUEEN, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, BLACK_ROOK, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, BLACK_KNIGHT, 0), move_list);
		addCaptureMove(board_state, move->createMove(from, to, capture, BLACK_BISHOP, 0), move_list);
	}
	else
	{
		addCaptureMove(board_state, move->createMove(from, to, capture, NO_PIECE, 0), move_list);
	}
}



void MoveGenerator::generateAllMoves(STRUCT_BOARD_STATE* board_state, STRUCT_MOVE_LIST* move_list, STRUCT_MOVE* move,
	Board* board, Pieces* pieces, Attack* attack, Writer* w)
{
	Utility::assertBool(board->checkBoard(board_state));
	move_list->count = 0;

	int square = 0;

	if (board_state->side_to_move == WHITE)
	{
		// white pawns
		for (int i = 0; i != board_state->piece_number[WHITE_PAWN]; ++i)
		{
			square = board_state->piece_list[WHITE_PAWN][i];

			//check
			Utility::assertSquare(board->getFileOnBoard()[square]);

			// add pawn move if there's a free square in front of the pawn
			if (board_state->pieces[square + 10] == NO_PIECE)
			{
				addWhitePawnMove(board_state, move_list, move, board, square, square + 10);

				// add pawn start move if there's a free square two squares in front of a pawn that hasn't moved
				if (board->getRankOnBoard()[square] == RANK_2 && board_state->pieces[square + 20] == NO_PIECE)
				{
					addQuietMove(board_state, move->createMove(square, square + 20, 0, 0, MOVE_FLAG_PAWN_START), move_list);
				}
			}

			// add capture moves for white pawns
			if (Utility::assertSquare(board->getFileOnBoard()[square + 9]) && pieces->getPieceColour()[board_state->pieces[square + 9]] == BLACK)
			{
				addWhitePawnCaptureMove(board_state, move_list, move, board, square, square + 9, board_state->pieces[square + 9]);
			}
			if (Utility::assertSquare(board->getFileOnBoard()[square + 11]) && pieces->getPieceColour()[board_state->pieces[square + 11]] == BLACK)
			{
				addWhitePawnCaptureMove(board_state, move_list, move, board, square, square + 11, board_state->pieces[square + 11]);
			}

			// add white en passant moves
			if (Utility::assertSquare(board->getFileOnBoard()[square + 9]) && square + 9 == board_state->en_passant)
			{
				addEnPassantMove(board_state, move->createMove(square, square + 9, 0, 0, MOVE_FLAG_EN_PASSANT), move_list);
			}
			else if (Utility::assertSquare(board->getFileOnBoard()[square + 11]) && square + 11 == board_state->en_passant)
			{
				addEnPassantMove(board_state, move->createMove(square, square + 11, 0, 0, MOVE_FLAG_EN_PASSANT), move_list);
			}
		}

		// white castling
		if (board_state->castle_permission & WHITE_KING_CASTLING)
		{
			if (board_state->pieces[F1] == NO_PIECE && board_state->pieces[G1] == NO_PIECE)
			{
				if (!attack->squareAttacked(board, F1, BLACK, board_state, pieces) && !attack->squareAttacked(board, E1, BLACK, board_state, pieces))
				{
					std::cout << "White king castling allowed\n";
					addQuietMove(board_state, move->createMove(E1, G1, 0, 0, MOVE_FLAG_CASTLE), move_list);
				}
			}
		}

		if (board_state->castle_permission & WHITE_QUEEN_CASTLING)
		{
			if (board_state->pieces[C1] == NO_PIECE && board_state->pieces[D1] == NO_PIECE)
			{
				if (!attack->squareAttacked(board, E1, BLACK, board_state, pieces) && !attack->squareAttacked(board, D1, BLACK, board_state, pieces))
				{
					std::cout << "White queen castling allowed\n";
					addQuietMove(board_state, move->createMove(E1, C1, 0, 0, MOVE_FLAG_CASTLE), move_list);
				}
			}
		}

	}
	else
	{
		// black pawns
		for (int i = 0; i != board_state->piece_number[BLACK_PAWN]; ++i)
		{
			square = board_state->piece_list[BLACK_PAWN][i];

			//check
			Utility::assertSquare(board->getFileOnBoard()[square]);

			// add pawn move if there's a free square in front of the pawn
			if (board_state->pieces[square - 10] == NO_PIECE)
			{
				addBlackPawnMove(board_state, move_list, move, board, square, square - 10);

				// add pawn start move if there's a free square two squares in front of a pawn that hasn't moved
				if (board->getRankOnBoard()[square] == RANK_7 && board_state->pieces[square - 20] == NO_PIECE)
				{
					addQuietMove(board_state, move->createMove(square, square - 20, 0, 0, MOVE_FLAG_PAWN_START), move_list);
				}
			}

			// add capture moves for black pawns
			if (Utility::assertSquare(board->getFileOnBoard()[square - 9]) && pieces->getPieceColour()[board_state->pieces[square - 9]] == WHITE)
			{
				addBlackPawnCaptureMove(board_state, move_list, move, board, square, square - 9, board_state->pieces[square - 9]);
			}
			if (Utility::assertSquare(board->getFileOnBoard()[square - 11]) && pieces->getPieceColour()[board_state->pieces[square - 11]] == WHITE)
			{
				addBlackPawnCaptureMove(board_state, move_list, move, board, square, square - 11, board_state->pieces[square - 11]);
			}

			// add black en passant moves
			if (Utility::assertSquare(board->getFileOnBoard()[square - 9]) && square - 9 == board_state->en_passant)
			{
				addEnPassantMove(board_state, move->createMove(square, square - 9, 0, 0, MOVE_FLAG_EN_PASSANT), move_list);
			}
			else if (Utility::assertSquare(board->getFileOnBoard()[square - 11]) && square - 11 == board_state->en_passant)
			{
				addEnPassantMove(board_state, move->createMove(square, square - 11, 0, 0, MOVE_FLAG_EN_PASSANT), move_list);
			}
		}

		// black castling
		if (board_state->castle_permission & BLACK_KING_CASTLING)
		{
			if (board_state->pieces[F8] == NO_PIECE && board_state->pieces[G8] == NO_PIECE)
			{
				if (!attack->squareAttacked(board, F8, WHITE, board_state, pieces) && !attack->squareAttacked(board, E8, WHITE, board_state, pieces))
				{
					std::cout << "Black king castling allowed\n";
					addQuietMove(board_state, move->createMove(E8, G8, 0, 0, MOVE_FLAG_CASTLE), move_list);
				}
			}
		}

		if (board_state->castle_permission & BLACK_QUEEN_CASTLING)
		{
			if (board_state->pieces[D8] == NO_PIECE && board_state->pieces[B8] == NO_PIECE)
			{
				if (!attack->squareAttacked(board, E8, WHITE, board_state, pieces) && !attack->squareAttacked(board, D8, WHITE, board_state, pieces))
				{
					std::cout << "Black queen castling allowed\n";
					addQuietMove(board_state, move->createMove(E8, C8, 0, 0, MOVE_FLAG_CASTLE), move_list);
				}
			}
		}
	}

	// non sliding pieces (knight, king)
	int pieceIndex = pieces->getLoopNonSlidingIndex()[board_state->side_to_move];
	int piece = pieces->getLoopNonSlidingPieces()[pieceIndex];
	++pieceIndex;

	int direction = 0;
	int target_square = 0;

	while (piece != 0)
	{
		std::cout << "non slide index: " << pieceIndex << " Piece: " << piece << std::endl;

		// for each piece of that type
		for (int piece_num = 0; piece_num != board_state->piece_number[piece]; ++piece_num)
		{
			square = board_state->piece_list[piece][piece_num];
			Utility::assertSquare(square);
			std::cout << "Piece: " << piece << " on: " << w->printSquare(square, board) << "\n";

			// and each direction
			for (int i = 0; i != pieces->getNumDirections()[piece]; ++i)
			{
				direction = pieces->getPieceDirections()[piece][i];
				target_square = square + direction;

				// if the target square we're potientially going to is on the board
				if (Utility::assertSquare(board->getSq120To64()[target_square]))
				{

					// check to see if there's a piece on that square
					if (board_state->pieces[target_square] != NO_PIECE)
					{

						// check the colour of that piece, see if it's the opponents piece
						if (pieces->getPieceColour()[board_state->pieces[target_square]] != board_state->side_to_move)
						{
							std::cout << "\t\tCapture move on: " << w->printSquare(target_square, board) << "\n";
							addCaptureMove(board_state, move->createMove(square, target_square, board_state->pieces[target_square], 0, 0), move_list);
						}
					}

					// if the square is empty, it's a legal move
					else
					{
						std::cout << "\t\tNormal move on: " << w->printSquare(target_square, board) << "\n";
						addQuietMove(board_state, move->createMove(square, target_square, 0, 0, 0), move_list);
					}
				}
			}
		}

		piece = pieces->getLoopNonSlidingPieces()[pieceIndex];
		++pieceIndex;
	}

	// sliding pieces (bishop, rook, queen)
	pieceIndex = pieces->getLoopSlidingIndex()[board_state->side_to_move];
	piece = pieces->getLoopSlidingPieces()[pieceIndex];
	pieceIndex++;

	while (piece != 0)
	{
		std::cout << "Index: " << pieceIndex << " Piece: " << piece << std::endl;

		// for each piece of that type
		for (int piece_num = 0; piece_num != board_state->piece_number[piece]; ++piece_num)
		{
			square = board_state->piece_list[piece][piece_num];
			Utility::assertSquare(square);
			std::cout << "Piece: " << piece << " on: " << w->printSquare(square, board) << "\n";

			// and each direction
			for (int i = 0; i != pieces->getNumDirections()[piece]; ++i)
			{
				direction = pieces->getPieceDirections()[piece][i];
				target_square = square + direction;

				// if the target square we're potientially going to is on the board and there's no piece there,
				// keep going in the same direction
				while (Utility::assertSquare(board->getSq120To64()[target_square]) && board_state->pieces[target_square] == NO_PIECE)
				{
					std::cout << "\t\tNormal move on: " << w->printSquare(target_square, board) << "\n";
					addCaptureMove(board_state, move->createMove(square, target_square, board_state->pieces[target_square], 0, 0), move_list);

					target_square += direction;
				}

				// when we run into a piece, check the colour, see if it's the opponents piece
				if (Utility::assertSquare(board->getSq120To64()[target_square]) && board_state->pieces[target_square] != NO_PIECE)
				{
					if (pieces->getPieceColour()[board_state->pieces[target_square]] != board_state->side_to_move)
					{
						std::cout << "\t\tCapture move on: " << w->printSquare(target_square, board) << "\n";
						addCaptureMove(board_state, move->createMove(square, target_square, board_state->pieces[target_square], 0, 0), move_list);
					}
				}

			}
		}

		piece = pieces->getLoopSlidingPieces()[pieceIndex];
		++pieceIndex;
	}
}