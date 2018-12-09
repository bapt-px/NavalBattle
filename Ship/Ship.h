#ifndef SHIP_DEFINED
#define SHIP_DEFINED
  #include <stdio.h>
  #include <stdlib.h>
  #include "../fct/fct.h"
  #include "Position.h"

  typedef struct Position Position;
  struct Position {
      int x;
      int y;
      int down;
  };

  typedef struct Ship Ship;
  struct Ship {
      int size;
      char name[20];
      char hit, notHit;
      Position *position;
  };

  int isDown(Ship ship);
  Ship *ShipC(char name[20], int size, char notHit, char hit);  // Ship constructor
#endif
