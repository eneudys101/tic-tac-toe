#include <stdio.h>
#include <stdlib.h>

#include "game_logic.h"

int main()
{
    GameState * game_state_ptr = (GameState *) malloc(sizeof(GameState));
    init_game(game_state_ptr);
    game_loop(game_state_ptr);
    free(game_state_ptr);
    return 0;
}
