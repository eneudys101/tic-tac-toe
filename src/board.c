#include "board.h"
#include "game_constants.h"
#include "game_state.h"

int check_col(GameState * state, Player player, int col)
{
    int count = 0;
    
    for(int row = 0; row < BOARD_ROWS; row++){
        if(state->board[row][col-1] == player){
            count++;
        }
    }
    return count;
}

int check_row(GameState * state, Player player, int row)
{
    int count = 0;
    
    for(int col = 0; col < BOARD_COLS; col++){
        if(state->board[row-1][col] == player){
            count++;
        }
    }
    return count;
}

int check_diag(GameState * state, Player player)
{   
    int count = 0;

    for(int i = 0; i < BOARD_COLS; i++){
        if(state->board[i][i] == player){
            count++;
        }      
    }
    return count;   
}

int check_anti_diag(GameState * state, Player player)
{
    int count = 0;

    for(int i = 0; i < BOARD_COLS; i++){
        if(state->board[i][2-i] == player){
            count++;
        } 
    }
    return count;  
}

void clean_board(GameState * state)
{
    for(int col = 0; col < BOARD_COLS; col++){
        for (int row = 0; row < BOARD_ROWS; row++){
            state->board[row][col] = EMPTY;
        }
    }
}

void draw_board(GameState * state)
{
    for(int col = 0; col < BOARD_COLS; col++){
        printf("+---+---+---+\n");
        printf("|");

        for(int row = 0; row < BOARD_ROWS; row++){

            switch (state->board[row][col])
            {
            case PLAYER_X:
                printf(" X |");
                break;
            
            case PLAYER_O:
                printf(" O |");

            default:
                printf("   |");
                break;
            }
        }

        printf("\n");
    }

    printf("+---+---+---+\n");
}