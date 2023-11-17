#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#define BOARD_ROWS 3
#define BOARD_COLS 3

typedef enum {
    EMPTY,
    PLAYER_X,
    PLAYER_O
} CellState;

typedef enum {
    PLAYER_1,
    PLAYER_2
} Player;

typedef enum {
    GAME_ONGOING,
    GAME_WON,
    GAME_DRAWN
} Status;

#endif //GAME_CONSTANTS_H