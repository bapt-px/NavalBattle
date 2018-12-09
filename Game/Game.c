#include "Game.h"

void placeShip(Board *board, Ship *ship) {
    int continuer = 1;
    showBoard(board);
    int x, y, sense;    //sense 0 = horizontal; sense 1 = vertical
    do {
        char saisi[4];
        printf("Placement d'un %s, sur %d cases (ex : B4V ou C6H) : ", ship->name, ship->size);
        do { fgets(saisi, 4, stdin); } while (saisi[0] == 10);
        printf("\nfirst char : %d\n", (int)saisi[0] );
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
              printf("sense 0\n" );

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
                }
                else {

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
}
Board *initPlayer() {
    Board *player;
    printf("Entrez votre pseudo : ");

    player = (Board*) malloc(sizeof(Board));
    initBoard(player);

    //fgets(player->name, 32, stdin);
    printf("Size :%d\n", sizeof(Ship) );
    player->ship = (Ship*) malloc(sizeof(Ship) * NBSHIP);
    player->pos[0][0] = 't';
    printf("pos : %d\n", player->pos[0][0]);
    for(int i = 0; i < 3; i++) placeShip(player, ShipC("Submarines", 3, 'c', 'C'));
    return player;
}
