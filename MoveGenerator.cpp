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

// non capture moves for white pawns
void MoveGenerator::addWhitePawnMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
	Board* board, const int from, const int to)
{
	// if we're on rank 7, add the options to promote white pawns
	if (board->getRankOnBoard()[from] == RANK_7)
	{
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, wQ, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, wR, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, wN, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, wB, 0), moveList);
	} 
	else 
	{
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, NO_PIECE, 0), moveList);
	}
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
	else
	{
		AddCaptureMove(boardState, move->createMove(from, to, capture, NO_PIECE, 0), moveList);
	}
}

// non capture moves for black pawns
void MoveGenerator::addBlackPawnMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
	Board* board, const int from, const int to)
{
	// if we're on rank 2, add the options to promote black pawns
	if (board->getRankOnBoard()[from] == RANK_2)
	{
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, bQ, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, bR, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, bN, 0), moveList);
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, bB, 0), moveList);
	}
	else
	{
		AddQuietMove(boardState, move->createMove(from, to, NO_PIECE, NO_PIECE, 0), moveList);
	}
}

void MoveGenerator::addBlackPawnCaptureMove(const STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
	Board* board, const int from, const int to, const int capture)
{
	// if we're on rank 2, add the options to promote black pawns
	if (board->getRankOnBoard()[from] == RANK_2)
	{
		AddCaptureMove(boardState, move->createMove(from, to, capture, bQ, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, bR, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, bN, 0), moveList);
		AddCaptureMove(boardState, move->createMove(from, to, capture, bB, 0), moveList);
	}
	else
	{
		AddCaptureMove(boardState, move->createMove(from, to, capture, NO_PIECE, 0), moveList);
	}
}



void MoveGenerator::generateAllMoves(STRUCT_BOARD_STATE* boardState, STRUCT_MOVELIST* moveList, STRUCT_MOVE* move,
	Board* board, Pieces* pieces)
{
	assertBool(board->checkBoard(boardState));
	moveList->count = 0;

	int square = 0;

	// white pawns
	if (boardState->sideToMove == WHITE)
	{
		for (int i = 0; i != boardState->pieceNumber[wP]; ++i)
		{
			square = boardState->pieceList[wP][i];

			//check
			sqOnBoard(board->getFileOnBoard()[square]);

			// add pawn move if there's a free square in front of the pawn
			if (boardState->pieces[square + 10] == NO_PIECE)
			{
				addWhitePawnMove(boardState, moveList, move, board, square, square + 10);

				// add pawn start move if there's a free square two squares in front of a pawn that hasn't moved
				if (board->getRankOnBoard()[square] == RANK_2 && boardState->pieces[square + 20] == NO_PIECE)
				{
					AddQuietMove(boardState, move->createMove(square, square + 20, 0, 0, moveFlagPawnStart), moveList);
				}
			}

			// add capture moves for white pawns
			if (sqOnBoard(board->getFileOnBoard()[square + 9]) && pieces->getPieceColour()[boardState->pieces[square + 9]] == BLACK)
			{
				addWhitePawnCaptureMove(boardState, moveList, move, board, square, square + 9, boardState->pieces[square + 9]);
			}
			if (sqOnBoard(board->getFileOnBoard()[square + 11]) && pieces->getPieceColour()[boardState->pieces[square + 11]] == BLACK)
			{
				addWhitePawnCaptureMove(boardState, moveList, move, board, square, square + 11, boardState->pieces[square + 11]);
			}

			// add white en passant moves
			if (sqOnBoard(board->getFileOnBoard()[square + 9]) && square + 9 == boardState->enPassant)
			{
				AddEnPassantMove(boardState, move->createMove(square, square + 9, 0, 0, moveFlagEnPassant), moveList);
			}
			else if (sqOnBoard(board->getFileOnBoard()[square + 11]) && square + 11 == boardState->enPassant)
			{
				AddEnPassantMove(boardState, move->createMove(square, square + 11, 0, 0, moveFlagEnPassant), moveList);
			}
		}
	}

	// black pawns
	if (boardState->sideToMove == BLACK)
	{
		for (int i = 0; i != boardState->pieceNumber[bP]; ++i)
		{
			square = boardState->pieceList[bP][i];

			//check
			sqOnBoard(board->getFileOnBoard()[square]);

			// add pawn move if there's a free square in front of the pawn
			if (boardState->pieces[square - 10] == NO_PIECE)
			{
				addBlackPawnMove(boardState, moveList, move, board, square, square - 10);

				// add pawn start move if there's a free square two squares in front of a pawn that hasn't moved
				if (board->getRankOnBoard()[square] == RANK_7 && boardState->pieces[square - 20] == NO_PIECE)
				{
					AddQuietMove(boardState, move->createMove(square, square - 20, 0, 0, moveFlagPawnStart), moveList);
				}
			}

			// add capture moves for black pawns
			if (sqOnBoard(board->getFileOnBoard()[square - 9]) && pieces->getPieceColour()[boardState->pieces[square - 9]] == WHITE)
			{
				addBlackPawnCaptureMove(boardState, moveList, move, board, square, square - 9, boardState->pieces[square - 9]);
			}
			if (sqOnBoard(board->getFileOnBoard()[square - 11]) && pieces->getPieceColour()[boardState->pieces[square - 11]] == WHITE)
			{
				addBlackPawnCaptureMove(boardState, moveList, move, board, square, square - 11, boardState->pieces[square - 11]);
			}

			// add black en passant moves
			if (sqOnBoard(board->getFileOnBoard()[square - 9]) && square - 9 == boardState->enPassant)
			{
				AddEnPassantMove(boardState, move->createMove(square, square - 9, 0, 0, moveFlagEnPassant), moveList);
			}
			else if (sqOnBoard(board->getFileOnBoard()[square - 11]) && square - 11 == boardState->enPassant)
			{
				AddEnPassantMove(boardState, move->createMove(square, square - 11, 0, 0, moveFlagEnPassant), moveList);
			}
		}
	}
}