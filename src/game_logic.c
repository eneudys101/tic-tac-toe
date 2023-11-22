#include <stdio.h>

#include "game_logic.h"
#include "game_state.h"
#include "board.h"

void init_game(GameState * state) 
{
    char multiplayer_opt;

    clean_board(state);
    state->status = GAME_ONGOING;
    do{
        printf("Multiplayer? (y/n): ");
        int result = scanf(" %c", &multiplayer_opt);
        
        while (getchar() != '\n' && result != EOF);

        if (result != 1) {
            printf("Error. Try again.\n");
            // Depending on the situation you might want to exit or handle the error differently
            continue;
        }

        // Check if the input is neither 'y' nor 'n'
        if (multiplayer_opt != 'y' && multiplayer_opt != 'n') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }while(multiplayer_opt != 'y' && multiplayer_opt != 'n');

    if(multiplayer_opt == 'y'){
        state->players = MULTIPLAYER;
    }
}



void game_loop(GameState * game)
{
    while(game->status == GAME_ONGOING){

        switch (game->players)
        {
        case SINGLE_PLAYER:
            break;

        case MULTIPLAYER:
            draw_board();
            int space;
            printf("Player X make your move: ");
            scanf("%d", &space);

            play(game, PLAYER_X, space); 

            if(check_win(game, PLAYER_X)){
                printf("Player X Won, Congratulations!\n");
                game->status = GAME_WON;
                break;
            }
            break;
        }  
    }

    draw_board();
    printf("Game Over!\n");
    printf("Play again?\n");
}

int play(GameState * state, CellState player, int board_space)
{
    int count = 0;

    for(int row = 0; row < BOARD_ROWS; row++){
        for(int col = 0; col < BOARD_COLS; col++){
            if(count == board_space - 1){
                printf("Count: %d\n Row: %d\n Col: %d\n", count, row, col);
                if(state->board[row][col] == EMPTY){
                    state->board[row][col] = player;
                    return 1;
                }else{
                    return 0;
                }
            }
            count++;
        }
    }
}



int check_win(GameState * state, CellState player)
{
    for(int i = 0; i < BOARD_COLS; i++){
        //check rows
        if(check_row(state, player, i) == 3){
            return 1;
        }
        //check cols
        if(check_col(state, player, i) == 3){
            return 1;
        }
    }
    
    //check diagonals
    if(check_diag(state, player) == 3 || check_anti_diag(state, player) == 3){
        return 1;
    }
    
    return 0;    
}