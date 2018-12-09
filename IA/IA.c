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
