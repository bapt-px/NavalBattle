#ifndef BOARD_DEFINED
#define BOARD_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include "../Ship/Ship.h"
  #define SIZE 10
  #define NBSHIP 10

  typedef struct Board Board;
  struct Board {
      char pos[SIZE][SIZE];
      char name[32];
      Ship *ship;
  };
  Board *initPlayer();

  int isItAShip(Board *player, int x, int y, int mustHit );
  void showBoard(Board *board);

#endif
