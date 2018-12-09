#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ship/Ship.h"
#include "Board/Board.h"
#include "Game/Game.h"

void play() {
  Board *j1 = initPlayer();
  Board *j2 = initPlayer();
  int continuer = 0;
  int tour = 0;

  while (continuer == 0) {
    if(tour == 0) {
      playJ(j1, j2);
      if(isLose(j1)) continuer = 1;
    } else {
      playJ(j2, j1);
      if(isLose(j1)) continuer = 2;
      tour = 0;
    }
  }
  if(continuer == 1) printf("Félicitation au joueur 1\n" );
  else printf("Félicitation au joueur 2\n" );

}

int main()
{
  play();

  return 0;
}
