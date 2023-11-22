#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game_logic.h"
#include "game_state.h"
#include "board.h"

void test_game_loop()
{
    printf("Starting game_loop test...\n");
    
    //Initiate struct to store game data
    GameState * game_state_ptr = (GameState *) malloc(sizeof(GameState));


    game_state_ptr->debug = 1;
    game_state_ptr->is_multiplayer = 0;
    clean_board(game_state_ptr);
    
 
  
    // Start timer
    clock_t start = clock();

    // Call the function multiple times to get an average time
    for (long i = 0; i < 1000000; ++i) {
        game_loop(game_state_ptr);
    }

    // End timer
    clock_t end = clock();
    
    free(game_state_ptr);

    // Calculate the elapsed time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
}

int main()
{
    test_game_loop();
    return 0;
}