#include "Ship.h"

int isDown(Ship ship) {
  printf("before down\n" );
    for(int i = 0; i < ship.size; i++) {
      if(ship.position[i].down == 0){ printf("down %d : %d\n", i, ship.position[i].down); return 0; }
    }
    printf("after down\n" );

    return 1;
}
Ship *ShipC(char name[20], int size, char notHit, char hit) {
    Ship *ship;
    ship = (Ship*) malloc(sizeof(Ship));
    copyString(ship->name, name);
    ship->size = size;
    ship->notHit = notHit;
    ship->hit = hit;
    ship->position = (Position*) malloc(sizeof(Position) * size);
    for(int i = 0; i < size; i++) ship->position[i].down = 0;
    return ship;
}
