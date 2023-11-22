#include "game_constants.h"

#ifndef GAME_STATE_H
#define GAME_STATE_H

typedef struct game_state 
{   
    int is_multiplayer;
    int player1_score;
    int player2_score;
    Status status;
    int debug; 
    CellState board[BOARD_ROWS][BOARD_COLS];
}GameState;

#endif //GAME_STATE_H