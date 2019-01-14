#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ship/Ship.h"
#include "Board/Board.h"
#include "Game/Game.h"

void play() {
  Board *j1 = initPlayer(0);
  Board *j2 = initPlayer(1);
  setBoardIA(j1);
  setBoardIA(j2);
  int continuer = 0;
  int tour = 0;

  while (continuer == 0) {
    if(tour == 0) {
      playJ(j1, j2, 0, 0);
      if(isLose(j2)) continuer = 1;
      tour = 1;
    } else {
      playJ(j2, j1, 1, 0);
      if(isLose(j1)) continuer = 2;
      tour = 0;
    }
  }
  if(continuer == 1) printf("Félicitation au joueur 1\n" );
  else printf("Félicitation au joueur 2\n" );

}

void menu () {

int saisi;
  do {
    printf("0/ Exit \n1/ Heberger une parti. \n2/ Rejoindre une parti. \n3/ Jouer contre une IA\nSaisi : ");
    scanf("%d", &saisi);
  } while(saisi < 0 || saisi > 3);
  if(saisi == 1) hostParty();
  else if(saisi == 2) joinParty();
  else if(saisi == 3) play();
}

int main()
{
  menu();

  return 0;
}
