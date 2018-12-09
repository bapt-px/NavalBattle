#ifndef GAME_DEFINED
#define GAME_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include "../Ship/Ship.h"
  #include "../Board/Board.h"
  #include "../IA/IA.h"


  void initBoard(Board *board);
  void placeShip(Board *board, Ship *ship, int isAuto);
  int isLose(Board *board);
  int playJ(Board *j, Board *adversary);

#endif
