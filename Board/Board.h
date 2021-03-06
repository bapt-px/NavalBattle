#ifndef BOARD_DEFINED
#define BOARD_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include "../Ship/Ship.h"
  #define SIZE 10
  #define NBSHIP 10
  #define NBCARRIER 1
  #define NBBATTLESHIPS 2
  #define NBSUBMARINES 3
  #define NBDESTROYERS 4


  typedef struct Board Board;
  struct Board {
    char pos[SIZE][SIZE];
    int opponent[SIZE][SIZE];
    int IAWeight[SIZE][SIZE];
    char name[32];
    Ship *ship;
    int nbShip;
  };
  Board *initPlayer(int isIA);

  int isItAShip(Board *player, int x, int y, int mustHit );
  char isItAShipToChar(int c);
  void showBoard(Board *board);
  void showBoardOpponent(Board *board);
  void showBoardIA(Board *board);
  void showLBoard(Board *board);

#endif
