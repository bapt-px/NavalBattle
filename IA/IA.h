#ifndef IA_DEFINED
#define IA_DEFINED

  #include <stdio.h>
  #include <stdlib.h>
  #include "../Ship/Ship.h"
  #include "../Board/Board.h"


  void selectAPlace(int *x, int *y, int *sense, Ship *ship, Board *board);
  void setBoardIA(Board *board);
  void setIAPlay(Board *board, int x, int y, int result);
  void getIAPlay(Board *board, int *x, int *y);

#endif
