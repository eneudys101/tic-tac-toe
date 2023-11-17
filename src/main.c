#include <stdio.h>
#include <stdlib.h>

int gameover = 0;
int multiplayer = 0;
int player1_score = 0;
int player2_score = 0;
char player1;
char player2;
int board [3][3];

void init_game();
void game_loop();
void draw_board();
void player_move(char);
void computer_move();
char get_space(int, int);
int is_empty(int, int);
int check_win(char);
int check_draw();
int check_col(char, int);
int check_row(char, int);
int check_diag(char);
int check_anti_diag(char);

int main()
{
    init_game();
    game_loop();
    
    return 0;
}

int is_empty(int col, int row){
    if(board[col-1][row-1] != 'X' && board[col-1][row-1] != 'O'){
        return 1;
    }
    return 0;
}

char get_space(int col, int row){
    return board[col-1][row-1];
}

void draw_board()
{
    for(int y = 0; y < 3; y++){
        printf("+---+---+---+\n");
        printf("|");

        for(int x = 0; x < 3; x++){
            if(board[x][y] == 'X' || board[x][y] == 'O'){
                printf(" %c |",board[x][y]);
            }else{
                printf(" %d |",board[x][y]);
            }
        }

        printf("\n");
    }

    printf("+---+---+---+\n");
}

void player_move(char player)
{
    int board_space = 1;
    int count = 1;
    int col;
    int row;

    printf("Player %c, Enter space (1-9): \n", player);
    scanf("%d", &board_space);

    for(col = 1; col <= 3; col++){
        for(row = 1; row <= 3; row++){
            if(count == board_space){
                if(is_empty(col, row)){
                    board[col-1][row-1] = player;
                }else{
                    printf("Cant play here (%d, %d)\n", col, row);
                    player_move(player);
                }
            }
            count++;
        }
    }
    
    
    
}


/*
Computer strategy
    Win: If the computer has two in a row, place the third to get three in a row.
    Block: If the opponent has two in a row, play the third to block them.
    Fork: Create an opportunity where the computer has two ways to win (two non-blocked lines of 2).
    Block Opponent's Fork: If there is a configuration where the opponent can fork, block that fork.
    Center: Play the center if it's open.
    Opposite Corner: If the opponent is in the corner, play the opposite corner.
    Empty Corner: Play in a corner square.
    Empty Side: Play in a middle square on any of the 4 sides.
*/
void computer_move()
{
    //Rows
    for(int row = 1; row <= 3; row++){

        //Win
        if(check_row(player2, row) == 2){
            for(int col = 1; col <= 3; col++){
                if(is_empty(col, row)){
                    board[col-1][row-1] = player2;
                    return;
                }
            }
        }
        
        //Block
        if(check_row(player1, row) == 2){
            for(int col = 1; col <= 3; col++){
                if(is_empty(col, row)){
                    board[col-1][row-1] = player2;
                    return;
                }
            }
        }
    }
    //Cols
    for(int col = 1; col <= 3; col++){

        //Win
        if(check_col(player2, col) == 2){
            for(int row = 1; row <= 3; row++){
                if(is_empty(col, row)){
                    board[col-1][row-1] = player2;
                    return;
                }
            }
        }
        //Blocks
        if(check_col(player1, col) == 2){
            for(int row = 1; row <= 3; row++){
                if(is_empty(col, row)){
                    board[col-1][row-1] = player2;
                    return;
                }
            }
        }
    }
    //Diagonals Win
    if(check_diag(player2) == 2){
        for(int i = 1; i <=3; i++){
            if(is_empty(i,i)){
                board[i][i] = player2;
                return;
            }
        }
    }
    if(check_anti_diag(player2) == 2){
        for(int i = 1; i <=3; i++){
            if(is_empty(i,2-i)){
                board[i][2-i] = player2;
                return;
            }
        }
    }

    //Diagonal Block
    if(check_diag(player1) == 2){
        for(int i = 1; i <=3; i++){
            if(is_empty(i,i)){
                board[i][i] = player2;
                return;
            }
        }
    }
    if(check_anti_diag(player1) == 2){
        for(int i = 1; i <=3; i++){
            if(is_empty(i,3-i)){
                board[i-1][3-i] = player2;
                return;
            }
        }
    }

    //Fork goes here

    //Fork Block goes here

    //Center
    if(is_empty(2,2)){
        board[1][1] = player2;
        return;   
    }

    //Opposing Corners
    if(get_space(1,1) == player1){
        if(is_empty(3,3)){
            board[2][2] = player2;
            return;
        }
    }
    if(get_space(3,3) == player1){
        if(is_empty(1,1)){
            board[0][0] = player2;
            return;
        }  
    }
    if(get_space(3,1) == player1){
        if(is_empty(1,3)){
            board[0][2] = player2;
            return;
        }
    }
    if(get_space(1,3) == player1){
        if(is_empty(3,1)){
            board[2][0] = player2;
            return;
        }
    }

    //Empty Corner
    if(is_empty(1,1)){
        board[0][0] = player2;
        return;
    }
    if(is_empty(3,3)){
        board[2][2] = player2;
        return;
    }
   if(is_empty(3,1)){
        board[2][0] = player2;
        return;
    }
    if(is_empty(1,3)){
        board[0][2] = player2;
        return;
    }

    //Empty sides
    if(is_empty(2,1)){
        board[1][0] = player2;
        return;
    }
    if(is_empty(1,2)){
        board[0][1] = player2;
        return;
    }
   if(is_empty(2,3)){
        board[1][2] = player2;
        return;
    }
    if(is_empty(3,2)){
        board[2][1] = player2;
        return;
    }

}


//Old algorithm. lol
/*void computer_move()
{   
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            int x_rn = (x + 1 > 2) ? 0: x + 1;
            int x_ln = (x - 1 < 0) ? 2: x - 1;
            int y_bn = (y + 1 > 2) ? 0: y + 1;
            int y_tn = (y - 1 < 0) ? 2: y - 1;
            
            //play offense
            if(board[x][y] == 'O'){
                if(board[x_rn][y] == 'O' && board[x_ln][y] == '\0'){
                    printf("A: (%d, %d)",x,y);
                    board[x_ln][y] = 'O';
                    return;
                }else if(board[x][y_bn] == 'O' && board[x][y_tn] == '\0'){
                    printf("B: (%d, %d)",x,y);
                    board[x][y_tn] = 'O';
                    return;
                }else if(board[x_rn][y_bn] == 'O' && board[x_ln][y_tn] == '\0'){
                    printf("C: (%d, %d)",x,y);
                    board[x_ln][y_tn] = 'O';
                    return;
                }else if(board[x_rn][y_tn] == 'O' && board[x_ln][y_bn] == '\0'){
                    printf("D: (%d, %d)",x,y);
                    board[x_ln][y_bn] = 'O';
                    return;
                }

            //play defense
            }else if(board[x][y] == 'X' ){
                if(board[x_rn][y] == 'X' && board[x_ln][y] == '\0'){
                    printf("E: (%d, %d)",x,y);
                    board[x_ln][y] = 'O';
                    return;
                }else if(board[x][y_bn] == 'X' && board[x][y_tn] == '\0'){
                    printf("F: (%d, %d)",x,y);
                    board[x][y_tn] = 'O';
                    return;
                }else if(board[x_rn][y_bn] == 'X' && board[x_ln][y_tn] == '\0'){
                    printf("G: (%d, %d)",x,y);
                    board[x_ln][y_tn] = 'O';
                    return;
                }else if(board[x_rn][y_tn] == 'X' && board[x_ln][y_bn] == '\0'){
                    printf("H: (%d, %d)",x,y);
                    board[x_ln][y_bn] = 'O';
                    return;
                }
            }
        }
    }

    if(board[1][1] == '\0'){
        printf("I");
        board[1][1] = 'O';
        return;
    }

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(board[x][y] == '\0'){
                printf("J: (%d, %d)",x,y);
                board[x][y] = 'O';
                return;
            }
        }
    }
}*/

int check_row(char player, int row)
{
    int count = 0;
    
    for(int col = 0; col < 3; col++){
        if(board[col][row-1] == player){
            count++;
        }
    }

    return count;
}

int check_col(char player, int col)
{
    int count = 0;
    
    for(int row = 0; row < 3; row++){
        if(board[col-1][row] == player){
            count++;
        }
    }

    return count;
}

int check_diag(char player)
{   
    int count = 0;

    for(int i = 0; i < 3; i++){
        if(board[i][i] == player){
            count++;
        }      
    }

    return count;   
}

int check_anti_diag(char player)
{
    int count = 0;

    for(int i = 0; i < 3; i++){
        if(board[i][2-i] == player){
            count++;
        } 
    }

    return count;  
}

int check_win(char player)
{
    for(int i = 1; i <= 3; i++){
        //check rows
        if(check_row(player, i) == 3){
            return 1;
        }
        //check cols
        if(check_col(player, i) == 3){
            return 1;
        }
    }
    
    //check diagonals
    if(check_diag(player) == 3 || check_anti_diag(player) == 3){
        return 1;
    }
    
    return 0;    
}

int check_draw(){
    int play_count = 0;

    for(int col = 0; col < 3; col++){
        for(int row = 0; row < 3; row++){
            if(board[col][row] == 'X' || board[col][row] == 'O'){
                play_count++;
            }
        }
    }
    if(play_count == 9){
        return 1;
    }
    return 0;
}

void init_game()
{   
    char multiplayer_opt;
    char mark_opt;
    int board_space = 1;
    gameover = 0;
    multiplayer = 0;

    for(int col = 0; col < 3; col++){
        for (int row = 0; row < 3; row++){

            board[col][row] = board_space;
            board_space++;
        }
    }

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
        multiplayer = 1;
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
        printf("triggered\n");
        player1 = 'X';
        player2 = 'O';
    }else{
        player1 = 'O';
        player2 = 'X';
    }
}

void game_loop()
{
    while(!gameover){  
        if(!multiplayer){
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
            }
        }else{
            printf("Test\n");
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
        } 
    }

    draw_board();
    printf("Game Over!\n");
    printf("Play again?\n");
    init_game();
    game_loop();
}