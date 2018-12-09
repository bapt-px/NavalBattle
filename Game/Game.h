#ifndef GAME_DEFINED
#define GAME_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include "../Ship/Ship.h"
  #include "../Board/Board.h"


  void initBoard(Board *board);
  void placeShip(Board *board, Ship *ship);

#endif
