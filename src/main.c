#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "linkedlist.h"
#include "board.h"
#include "color.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int main() {
	Board b = create_blank_board();
	int **color_map = create_default_colormap();
	fill_board_default(b.pieces);
	//print_board(&b, color_map);

	Vec2 move_pos;
	move_pos.x = 2;
	move_pos.y = 1;
	Vec2 piece_pos;
	piece_pos.x = 1;
	piece_pos.y = 1;

	if (move_is_legal(move_pos, piece_pos, b.pieces[0][0], b)) {
		b.pieces[move_pos.x][move_pos.y].type = King;
	}else {
		printf("Not legal\n");
		b.pieces[move_pos.x][move_pos.y].type = Queen;
	}
	print_board(&b, color_map);

	return 0;
}