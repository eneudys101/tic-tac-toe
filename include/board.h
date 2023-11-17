#include "game_state.h"

#ifndef BOARD_H
#define BOARD_H

void draw_board();
int check_col(GameState *, CellState, int);
int check_row(GameState *, CellState, int);
int check_diag(GameState *, CellState);
int check_anti_diag(GameState *, CellState);
void clean_board(GameState *);

#endif //BOARD_H