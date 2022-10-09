#include "piece.h"
#include "board.h"
#include "color.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void print_board(Board *board, int **color_map) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			Piece piece = board->pieces[x][y];
			
			if (piece.type == EMPTY) {
				if (color_map[x][y] == WHITE) {
					printf("%s", BBLK);
				}else {
					printf("%s", BWHT);
				}
			}else if (piece.color == WHITE){
				printf("%s", BHBLK);
			}else {
				printf("%s", BHWHT);
			}

			switch (piece.type) {
				case Pawn:
					printf("P");
					break;
				case Rook:
					printf("R");
					break;
				case Knight:
					printf("H");
					break;
				case Bishop:
					printf("B");
					break;
				case King:
					printf("K");
					break;
				case Queen:
					printf("Q");
					break;
				case EMPTY:
					printf("#");
					break;
			}
			printf("%s", reset);
			printf(" ");
		}
		printf("\n");
	}
}

Board create_blank_board() {
	Board board;
	board.black_attack = 0;
	board.white_attack = 0;
	Piece* values = calloc(8, sizeof(Piece));
	Piece** rows = malloc(8 * sizeof(Piece*));
	
	for (size_t i = 0; i < 8; i++)
	{
		rows[i] = values + (i * 8) * sizeof(Piece);
	}

    for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++)
		{
			rows[i][j] = blank_piece();
		}
		
	}
	board.pieces = rows;
	return board;
}

int** create_default_colormap() {
	int* values = calloc(8, sizeof(int));
	int** rows = malloc(8 * sizeof(int*));
	
	for (size_t i = 0; i < 8; i++)
	{
		rows[i] = values + (i * 8) * sizeof(int);
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if ((x + y) % 2 == 0) {
				rows[x][y] = 1;
			}
			
		}
	}
	return rows;
}

// Assumes that any board passed is 8x8
void fill_board_default(Piece **pieceBoard) {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (i == 1) {
				pieceBoard[i][j].type = Pawn;
				pieceBoard[i][j].color = WHITE;
			}
			if (i == 0)	{
				if (j == 0 || j == 7) {
					pieceBoard[i][j].type = Rook;
					pieceBoard[i][j].color = WHITE;
				}else if (j == 1 || j == 6){
					pieceBoard[i][j].type = Knight;
					pieceBoard[i][j].color = WHITE;
				}else if (j == 2 || j == 5){
					pieceBoard[i][j].type = Bishop;
					pieceBoard[i][j].color = WHITE;
				}else if (j == 3){
					pieceBoard[i][j].type = King;
					pieceBoard[i][j].color = WHITE;
				}else if (j == 4){
					pieceBoard[i][j].type = Queen;
					pieceBoard[i][j].color = WHITE;
				}
			}
			if (i == 6) {
				pieceBoard[i][j].type = Pawn;
				pieceBoard[i][j].color = BLACK;
			}
			if (i == 7)	{
				if (j == 0 || j == 7) {
					pieceBoard[i][j].type = Rook;
					pieceBoard[i][j].color = BLACK;
				}else if (j == 1 || j == 6){
					pieceBoard[i][j].type = Knight;
					pieceBoard[i][j].color = BLACK;
				}else if (j == 2 || j == 5){
					pieceBoard[i][j].type = Bishop;
					pieceBoard[i][j].color = BLACK;
				}else if (j == 3){
					pieceBoard[i][j].type = King;
					pieceBoard[i][j].color = BLACK;
				}else if (j == 4){
					pieceBoard[i][j].type = Queen;
					pieceBoard[i][j].color = BLACK;
				}
			}
			
		}
		
	}
}