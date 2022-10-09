#ifndef PIECE_H
#define PIECE_H
#define WHITE 1
#define BLACK 0
#include "linkedlist.h"
typedef enum {
	Pawn,
	King,
	Queen,
	Knight,
	Bishop,
	Rook,
	EMPTY,
} piece_type;


typedef struct PieceTag{
	int color;
	piece_type type;
} Piece;

Piece blank_piece();

#include "board.h"


int move_is_legal(Vec2 move_pos, Vec2 piece_pos, Piece piece, Board board);


#endif