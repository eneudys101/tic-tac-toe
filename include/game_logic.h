#include "board.h"
#include "game_constants.h"

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void init_game(GameState *);
void game_loop(GameState *);
int play(GameState *, Player, int);
int check_win(GameState *, Player);

#endif //GAME_LOGIC_H