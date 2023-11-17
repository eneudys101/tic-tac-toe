#include "game_state.h"

#ifndef BOARD_H
#define BOARD_H

void draw_board();
int check_col(GameState *, Player, int);
int check_row(GameState *, Player, int);
int check_diag(GameState *, Player);
int check_anti_diag(GameState *, Player);
void clean_board(GameState *);

#endif //BOARD_H