#include <stdio.h>

#include "game_logic.h"
#include "game_state.h"
#include "board.h"

void init_game(GameState * state) 
{
    char multiplayer_opt;
    char mark_opt;

    clean_board(state);

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
        state->is_multiplayer = 1;
    }

    do{
        printf("Player 1 choose your mark(x/o): ");
        int result = scanf(" %c", &mark_opt);
        
        while (getchar() != '\n' && result != EOF);

        if (result != 1) {
            printf("Error. Try again.\n");
            // Depending on the situation you might want to exit or handle the error differently
            continue;
        }

        // Check if the input is neither 'y' nor 'n'
        if (mark_opt != 'x' && mark_opt != 'o') {
            printf("Invalid input. Please enter 'x' or 'o'.\n");
        }
    }while(mark_opt != 'x' && mark_opt != 'o');

    if(mark_opt == 'x'){
        state->player1_mark = 'X';
        state->player2_mark = 'O';
    }else{
        state->player1_mark = 'O';
        state->player2_mark = 'X';
    }
}

void game_loop(GameState * game)
{
    while(game->status == GAME_ONGOING){  
        if(game->is_multiplayer){
            draw_board();
            int space;
            printf("Player 1 make your move: ");
            scanf("%d", &space);
            play(game, PLAYER_1, space); 

            if(check_win(game, PLAYER_1)){
                printf("Player 1 Won, Congratulations!\n");
                game->status = GAME_WON;
                break;
            }
            /*if(check_draw()){
                printf("Its a tie\n");
                gameover = 1;
                break;
            }
            computer_move();
            if(check_win(player2)){
                printf("Player %c Won, Try again!\n", player2);
                gameover = 1;
                break;
            }
            if(check_draw()){
                printf("Its a tie\n");
                gameover = 1;
                break;
            }*/
        }/*else{
            draw_board();
            player_move(player1); 
            if(check_win(player1)){
                printf("Player %c Won, Congratulations!\n", player1);
                gameover = 1;
                break;
            }
            if(check_draw()){
                printf("Its a tie\n");
                gameover = 1;
                break;
            }
            draw_board();
            player_move(player2);
            if(check_win(player1)){
                printf("Player %c Won, Congratulations!\n", player2);
                gameover = 1;
                break;
            }
            if(check_draw()){
                printf("Its a tie\n");
                gameover = 1;
                break;
            }
        }*/ 
    }

    draw_board();
    printf("Game Over!\n");
    printf("Play again?\n");
    //init_game();
    //game_loop();
}

int play(GameState * state, Player player, int board_space)
{
    int count = 0;

    for(int col = 0; col < BOARD_COLS; col++){
        for(int row = 0; row < BOARD_ROWS; row++){
            if(count == board_space - 1){
                if(state->board[col][row] != EMPTY){
                    state->board[col][row] = player;
                    return 1;
                }else{
                    return 0;
                }
            }
            count++;
        }
    }
}

int check_win(GameState * state, Player player)
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