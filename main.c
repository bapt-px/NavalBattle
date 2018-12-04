#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define NBSHIP 10


typedef struct Tab {
    char pos[SIZE][SIZE];
    char name[32];
    struct Ship *ship;
};
typedef struct Ship{
    int size;
    char name[20];
    char hit, notHit;
    struct Position *position;
};
typedef struct Position {
    int x;
    int y;
    int down;
};

int isDown(struct Ship ship) {
    for(int i = 0; i < ship.size; i++) if(ship.position[i].down = 0) return 0;
    return 1;
}

int isItAShip(struct Tab *player, int x, int y, int mustHit ) {
  printf("map : %d\n%d\n%d\n", (int) (player->pos[x][y]), x, y);
    if(player->pos[x][y] == ' ') return 0;
    else if (mustHit) {
        for(int i = 0; i < NBSHIP; i++) {
            for(int j = 0; j < player->ship[i].size; j++) {
                if (player->ship[i].position[j].x == x && player->ship[i].position[j].y == y) {
                    player->ship[i].position[j].down = 1;
                    if (isDown(player->ship[i])) return 2;
                    else return 1;
                    break;
                }
            }
        }
    } else return 1;
}

void initTab(struct Tab *tab) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            tab->pos[i][j] = ' ';
        }
    }
}
void showTab(struct Tab *tab) {
    printf("\n     ");
    for(int i = 0; i < SIZE; i++) printf("%3c |", (char)('A' + i));
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
            printf("%3d |", (i+1));
        for(int j = 0; j < SIZE; j++) {
            char c;
            if(tab->pos[i][j] == ' ') c = ' ';
            else if(tab->pos[i][j] == 'C') c = 'S';
            else c = 'X';
            printf("%3c |", tab->pos[i][j]);
        }
        printf("\n");
    }
}
void placeShip(struct Tab *tab, struct Ship *ship) {
    int continuer = 1;
    showTab(tab);
    int x, y, sense;    //sense 0 = horizontal; sense 1 = vertical
    do {
        char saisi[4];
        printf("Placement d'un %s, sur %d cases (ex : B4V ou C6H) : ", ship->name, ship->size);
        fgets(saisi, 4, stdin);
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
            x--;
            y--;
            if(sense == 0) {
              printf("sense 0\n" );

                if(x > SIZE - ship->size) {
                    printf("Votre bateau depasse le jeu ! \n");
                    continuer = 1;
                }
                else {
                    for(int i = 0; i < ship->size; i++) {
                        if(isItAShip(tab, x + i, y, 0)) {
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
                        if(isItAShip(tab, x, y + i, 0) ) {
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
            tab->pos[x + i][y] = ship->notHit;
            ship->position[i].x = x;
            ship->position[i].y = y;
        }
    }
    else {
        for(int i = 0; i < ship->size; i++) {
            tab->pos[x][y + 1] = ship->notHit;
            ship->position[i].x = x;
            ship->position[i].y = y;
        }
    }
}


void copyString(char *t1, char *t2) {
    int i = 0;
    while(t2[i] != '\0') t1[i] = t2[i++];
    t1[i] = '\0';
}
struct Ship *Ship(char name[20], int size, char notHit, char hit) {
    struct Ship *ship;
    ship = (struct Ship*) malloc(sizeof(struct Ship));
    copyString(ship->name, name);
    ship->size = size;
    ship->notHit = notHit;
    ship->hit = hit;
    ship->position = (struct Position*) malloc(sizeof(struct Position) * size);
    for(int i = 0; i < size; i++) ship->position[i].down = 0;
    return ship;
};
struct Tab *initPlayer() {
    struct Tab *player;
    printf("Entrez votre pseudo : ");

    player = (struct Tab*) malloc(sizeof(struct Tab));
    initTab(player);

    //fgets(player->name, 32, stdin);
    printf("%d", sizeof(struct Ship) );
    player->ship = (struct Ship*) malloc(sizeof(struct Ship) * NBSHIP);
    printf("OK");
    for(int i = 0; i < 3; i++) placeShip(player, Ship("Submarines", 3, 'c', 'C'));
    return player;
}
int main()
{
    printf("t1");
    struct Tab *j1 = initPlayer();
    char t[20] = "yolo";
    printf("Hello world!\n%s", t);
    return 0;
}
