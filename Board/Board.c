#include "Board.h"


int isItAShip(Board *player, int x, int y, int mustHit ) {

    if(player->pos[x][y] == ' ') { player->pos[x][y] = 'x'; return 0; }
    else if (mustHit) {
      printf("SHIP 1 \n");
      printf("SHIP 1.5 : %d \n", player->pos[x][y]);

        for(int i = 0; i < NBSHIP; i++) {
            for(int j = 0; j < player->ship[i].size; j++) {
              printf("SHIP 2 : %d \n", player->ship[i].size);

                if (player->ship[i].position[j].x == x && player->ship[i].position[j].y == y) {
                  printf("Hit !\n" );
                    player->pos[x][y] = player->ship[i].hit;
                    player->ship[i].position[j].down = 1;
                    printf("SHIP 3 :  \n");

                    if (isDown(player->ship[i])) return 2;
                    else return 1;
                    break;
                }
            }
        }
    }
    return 1;
}

void initBoard(Board *board) {
  board->nbShip = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            board->pos[i][j] = ' ';
            board->opponent[i][j] = 0;
        }
    }
}

void showBoard(Board *board) {
    printf("\n     ");
    for(int i = 0; i < SIZE; i++) printf("%3c |", (char)('A' + i));
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
            printf("%3d |", (i+1));
        for(int j = 0; j < SIZE; j++) {
            char c;
            if(board->pos[j][i] == ' ') c = ' ';
            else if(board->pos[j][i] == 'C') c = 'S';
            else c = 'X';
            printf("%3c |", board->pos[j][i]);
        }
        printf("\n");
    }
}

void showBoardOpponent(Board *board) {
    printf("\n     ");
    for(int i = 0; i < SIZE; i++) printf("%6c |", (char)('A' + i));
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
            printf("%3d |", (i+1));
        for(int j = 0; j < SIZE; j++) {
            char c;
            if(board->opponent[j][i] ==  0) c = '?';
            else if(board->opponent[j][i] == 1) c = ' ';
            else c = 'X';
            printf("%3c%3d |", c, j);
        }
        printf("\n");
    }
}
void showBoardIA(Board *board) {
    printf("\n     ");
    for(int i = 0; i < SIZE; i++) printf("%3c |", (char)('A' + i));
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
            printf("%3d |", (i+1));
        for(int j = 0; j < SIZE; j++) {
            printf("%4d |", board->IAWeight[j][i]);
        }
        printf("\n");
    }
}
void showLBoard(Board *board) {
    printf("\n                         YOUR BOARD                                                     OPPONENT BOARD  \n     ");
    for(int i = 0; i < SIZE; i++) printf("%3c |", (char)('A' + i));
    printf("       ");
    for(int i = 0; i < SIZE; i++) printf("%3c |", (char)('A' + i));
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
            printf("%3d |", (i+1));
        for(int j = 0; j < SIZE; j++) printf("%3c |", board->pos[j][i]);
        printf("       ");
        for(int j = 0; j < SIZE; j++) {
            char c;
            if(board->opponent[j][i] ==  0) c = '?';
            else if(board->opponent[j][i] == 1) c = ' ';
            else c = 'X';
            printf("%3c |", c);
        }
        printf("\n");
    }
}
