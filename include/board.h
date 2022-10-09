#ifndef BOARD_H
#define BOARD_H
#include <stdint.h>


typedef struct BoardTag {
    uint64_t white_attack: 8;
    uint64_t black_attack: 8;
    Piece **pieces;

} Board;

void print_board(Board *board, int **color_map);

Board create_blank_board();

int** create_default_colormap();

void fill_board_default(Piece **pieceBoard);

#endif