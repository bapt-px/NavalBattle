#include "Game.h"

void placeShip(Board *board, Ship *ship, int isAuto) {
    int continuer = 1;
    showBoard(board);
    int x, y, sense;    //sense 0 = horizontal; sense 1 = vertical
    if(!isAuto) {
      do {
          char saisi[4];
          printf("Placement d'un %s, sur %d cases (ex : B4V ou C6H) : ", ship->name, ship->size);
          do { fgets(saisi, 4, stdin); } while (saisi[0] == 10);
          if (saisi[0] >= 'A') saisi[0] -= 32;
          x = saisi[0] - 'A';
          if (saisi[0] >= 'A' && saisi[0] <= 'J') {
              y = -1;
              if(saisi[1] == '1' && saisi[2] == 0) y = 10;
              else if(saisi[1] == '1' ) y = 1;
              else y = (int)(saisi[1] - '0');
              printf("saisi : %d", y);

              if(y != -1) {
                  if(y == 10) {
                      if(saisi[4] == 'h' || saisi [4] == 'H') sense = 0;
                      else sense = 1;
                  }
                  else {
                      if(saisi[3] == 'h' || saisi [3] == 'H') sense = 0;
                      else sense = 1;
                  }
                  continuer = 0;
              }
          }
          if(continuer == 0) {
              y--;
              if(sense == 0) {
                  if(x > SIZE - ship->size) {
                      printf("Votre bateau depasse le jeu ! \n");
                      continuer = 1;
                  }
                  else {
                      for(int i = 0; i < ship->size; i++) {
                          if(isItAShip(board, x + i, y, 0)) {
                              printf("Il y a deja un bateau sur cet emplacement !\n");
                              continuer = 1;
                          }
                      }
                  }
              }
              else {
                  if(y > SIZE - ship->size) {
                      printf("Votre bateau depasse le jeu ! \n");
                      continuer = 1;
                  } else {
                      for(int i = 0; i < ship->size; i++) {
                          if(isItAShip(board, x, y + i, 0) ) {
                              printf("Il y a deja un bateau sur cet emplacement !\n");
                              continuer = 1;
                          }
                      }
                  }
              }
          }
      } while (continuer);
    } else
    selectAPlace(&x, &y, &sense, ship, board);
    if (sense == 0) {
        for(int i = 0; i < ship->size; i++) {
            board->pos[x + i][y] = ship->notHit;
            ship->position[i].x = x;
            ship->position[i].y = y;
        }
    }
    else {
        for(int i = 0; i < ship->size; i++) {
            board->pos[x][y + i] = ship->notHit;
            ship->position[i].x = x;
            ship->position[i].y = y;
        }
    }
    int nb = board->nbShip;
    board->ship[nb] = *ship;
    board->nbShip++;

}

Board *initPlayer() {
    Board *player;
    int autoPlace = 1;
    player = (Board*) malloc(sizeof(Board));

    printf("Entrez votre pseudo : ");
    // do { fgets(player->name, 32, stdin); } while (player->name[0] == 10);
    initBoard(player);

    player->ship = (Ship*) malloc(sizeof(Ship) * NBSHIP);

    for(int i = 0; i < NBCARRIER; i++) placeShip(player, ShipC("Carrier", 5, 'c', 'C'), autoPlace);
    for(int i = 0; i < NBBATTLESHIPS; i++) placeShip(player, ShipC("Battleships", 4, 'b', 'B'), autoPlace);
    for(int i = 0; i < NBSUBMARINES; i++) placeShip(player, ShipC("Submarines", 3, 's', 'S'), autoPlace);
    for(int i = 0; i < NBDESTROYERS; i++) placeShip(player, ShipC("Destroyers", 2, 'd', 'D'), autoPlace);
    //printf("111 : %d\n", player->ship[0].position[0].down);
    return player;
}

int isLose(Board *board) {

  for(int i = 0;i < NBSHIP; i++) {

    for(int j = 0;j < board->ship[i].size; j++) {

      if(board->ship[i].position[j].down == 0) return 0;
    }
  }
  return 1;
}
int playJ(Board *j, Board *adversary) {
  int continuer = 1, x, y;
  char saisi[4];
  while (continuer) {
    printf("%s, Select a case to shoot (ex: B4) : ", j->name );
    do { fgets(saisi, 4, stdin); } while (saisi[0] == 10);
    if (saisi[0] >= 'A') saisi[0] -= 32;
    x = saisi[0] - 'A';
    if (saisi[2] != '\0') y = 10;
    else y = saisi[1] - '0';
    if(x < 0 || x > SIZE || y < 0 || y > SIZE) {
      printf("Saisi incorrecte !\n" );
    } else if (j->opponent[x][y] != 0) {
      printf("Vous avez déjà tirer sur cette case !\n");
    } else {
      int result = isItAShip(adversary, x, y, 1);
      if(result == 1) printf("Touche !\n" );
      else if(result == 2) printf("Touche coule !\n" );
      else printf("Flop ...\n" );
      continuer = 0;
    }
  }
}
