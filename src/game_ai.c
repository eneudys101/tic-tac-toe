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

*/