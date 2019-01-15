#ifndef GAME_DEFINED
#define GAME_DEFINED

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "../Ship/Ship.h"
#include "../Board/Board.h"
#include "../IA/IA.h"

  int conn, opponentReady, nbTouch;

  void initBoard(Board *board);
  void placeShip(Board *board, Ship *ship, int isAuto);
  int isLose(Board *board);
  int playJ(Board *j, Board *adversary, int isIA, int isOnline);
  void hostParty ();
  void joinParty ();

#endif
