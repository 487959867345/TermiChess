#include "math.h"
#include "linkedlist.h"
#include "piece.h"
#include "board.h"

#include <stdlib.h>
#include <stdio.h>

int calc_pawn_moves(Vec2 move_pos, Vec2 piece_pos, int piece_color, Board board) {
	int isLegal = 0;
	if (piece_color == WHITE) {
	} else {

	}
	
	return isLegal;
}

int calc_rook_moves(Vec2 move_pos, Vec2 piece_pos, int piece_color, Board board) {

	if (move_pos.x == piece_pos.x) {
		if (board.pieces[move_pos.x][move_pos.y].type != EMPTY) {
			return 0;
		}
		return 1;
	}else if (move_pos.y == piece_pos.y) {
		if (board.pieces[move_pos.x][move_pos.y].type != EMPTY) {
			return 0;
		}
		return 1;
	}else {
		return 0;
	}
	
	
	return -1;
}


// assumes x, y not out of bounds, does not check if can move
int move_is_legal(Vec2 move_pos, Vec2 piece_pos, Piece piece, Board board) {
	switch (piece.type) {
		case Pawn:
			return calc_pawn_moves(move_pos, piece_pos, piece.color, board);
		case Rook:
			return calc_rook_moves(move_pos, piece_pos, piece.color, board);
		case Knight:
			break;
		case Bishop:
			break;
		case Queen:
			break;
		// TODO disallow king from-
		// moving into attacked tiles
		case King:
			break;
	}
	return -1;
}

Piece blank_piece() {
	Piece blank;
	blank.color = 0;
	blank.type = EMPTY;
	return blank;
}
