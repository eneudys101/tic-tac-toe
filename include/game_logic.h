#include "board.h"
#include "game_constants.h"

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void init_game(GameState *);
void game_loop(GameState *);
int play(GameState *, CellState, int);
int check_win(GameState *, CellState);

#endif //GAME_LOGIC_H