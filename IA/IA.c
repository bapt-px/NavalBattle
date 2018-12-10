#include "IA.h"

void selectAPlace(int *x, int *y, int *sense, Ship *ship, Board *board) {
  int continuer = 0;
  printf("debtuS\n" );
  do {
    continuer = 0;
    *sense = rand() % 2;
    if(*sense == 0)  { // horizontal
      *x = rand() % (SIZE - ship->size);
      *y = rand() % SIZE;
      for(int i = 0; i < ship->size; i++) {
        if(isItAShip(board, *x + i, *y, 0) ) {
            continuer = 1;
        }
      }
    } else {  // vertical
      *x = rand() % SIZE;
      *y = rand() % (SIZE - ship->size);
      for(int i = 0; i < ship->size; i++) {
        if(isItAShip(board, *x, *y + i, 0) ) {
            continuer = 1;
        }
      }
    }
  } while (continuer);
  printf("selected\n" );
}
void setBoardIA(Board *board) {
  for(int i = 0;i < SIZE;i++) {
    for(int j = 0; j < SIZE;j++) {
      board->IAWeight[j][i] = 100;
      if (i < 4) board->IAWeight[j][i] -= 4 - i;
      if (SIZE - i < 5) board->IAWeight[j][i] -= 5 - (SIZE - i);
      if (j < 4) board->IAWeight[j][i] -= 4 - j;
      if (SIZE - j < 5) board->IAWeight[j][i] -= 5 - (SIZE - j);
      printf("%4d", board->IAWeight[j][i] );
    }
    printf("\n" );
  }
}

void setIAPlay(Board *board, int x, int y, int result) {
  board->IAWeight[x][y] = -1000;
  if(result != 2) {
    int mult = (result == 1 ? 2 : -2);
    for(int i = 0; i < 4; i++) {
      if(x - i >= 0) board->IAWeight[x - i][y] += (4 - i) * mult;
      if(y - i >= 0) board->IAWeight[x][y - i] += (4 - i) * mult;
      if(x + i < SIZE) board->IAWeight[x + i][y] += (4 - i) * mult;
      if(y + i < SIZE) board->IAWeight[x][y + i] += (4 - i) * mult;
    }
  }
}

void getIAPlay(Board *board, int *x, int *y) {
  *x = 0;
  *y = 0;
  for(int i = 0; i < SIZE; i++) {
    for(int j = 1; j < SIZE; j++) {
      if(board->IAWeight[j][i] > board->IAWeight[*x][*y]) {
        *x = i;
        *y = j;
      }
    }
  }
}
