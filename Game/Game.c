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
            ship->position[i].x = x + i;
            ship->position[i].y = y;
        }
    }
    else {
        for(int i = 0; i < ship->size; i++) {
            board->pos[x][y + i] = ship->notHit;
            ship->position[i].x = x;
            ship->position[i].y =  + i;
        }
    }
    int nb = board->nbShip;
    board->ship[nb] = *ship;
    board->nbShip++;

}

Board *initPlayer(int isIA) {
    Board *player;
    int autoPlace = 1;
    player = (Board*) malloc(sizeof(Board));
    if(!isIA) {
      printf("Entrez votre pseudo : ");
      do { fgets(player->name, 32, stdin); } while (player->name[0] == 10);
      do {
        printf("Souhaitez vous que le placement des bateaux s'effectue automatiquement ?\n0/ Non\n1/ Oui\nSaisi : " );
        scanf("%d", &autoPlace);
      } while (autoPlace < 0 || autoPlace > 1);
    } else { player->name[0] = 'I'; player->name[1] = 'A'; player->name[2] = '\0'; }
    int j = 0;
    while (player->name[j] != '\0') if (player->name[j++] == '\n') player->name[j - 1] = '\0';
    initBoard(player);

    player->ship = (Ship*) malloc(sizeof(Ship) * NBSHIP);

    for(int i = 0; i < NBCARRIER; i++) placeShip(player, ShipC("Carrier", 5, 'c', 'X'), autoPlace);
    for(int i = 0; i < NBBATTLESHIPS; i++) placeShip(player, ShipC("Battleships", 4, 'b', 'B'), autoPlace);
    for(int i = 0; i < NBSUBMARINES; i++) placeShip(player, ShipC("Submarines", 3, 's', 'S'), autoPlace);
    for(int i = 0; i < NBDESTROYERS; i++) placeShip(player, ShipC("Destroyers", 2, 'd', 'D'), autoPlace);
    return player;
}

int isLose(Board *board) {

  printf("%s ISLOSE 1\n", board->name );
  for(int i = 0;i < NBSHIP; i++) {

    for(int j = 0;j < board->ship[i].size; j++) {

      if(board->ship[i].position[j].down == 0) return 0;
    }
  }

  return 1;
}
int playJ(Board *j, Board *adversary, int isIA, int isOnline) {
  int continuer = 1, x, y;
  char saisi[4];
  int result;

  while (continuer) {

    if(!isIA) showLBoard(j);
    // showBoard(j);
    // showBoardIA(j);
    // showBoardOpponent(j);
    if(isIA)  getIAPlay(j, &x, &y);
    else {

      printf("%s, Select a case to shoot (ex: B4) IA for auto-play : ", j->name );
      do { fgets(saisi, 4, stdin); } while (saisi[0] == 10 || saisi[0] == 1);
      if((saisi[0] == 'i' || saisi[0] == 'I') && (saisi[1] == 'a' || saisi[1] == 'A')) {
         getIAPlay(j, &x, &y);
      }  else {

        if (saisi[0] >= 'A') saisi[0] -= 32;
        x = saisi[0] - 'A';
        if (saisi[1] == '1' && saisi[2] == '2') y = 10;
        else y = saisi[1] - '1';
        printf("Saisi : %d / %d\n", x, y );
      }
    }

    if(x < 0 || x > SIZE || y < 0 || y > SIZE) {
      printf("Saisi incorrecte ! : %d / %d\n", x, y );
    } else if (j->opponent[x][y] != 0) {
      printf("%d / %d\n", x, y);
      showBoardIA(j);
      printf("%s avez déjà tirer sur cette case ! %d\n", j->name, saisi[0]);
    } else {

      if (!isOnline) result = isItAShip(adversary, x, y, 1);
      else {
        char tab[3] = {x, y, '\0'};
        send(conn, tab, strlen(tab), 0);
        printf("test playJ 1 %d / %d\n", tab[0], tab[1] );

        char resultC[2];
        recv(conn, resultC, 100, 0) ;
        printf("test playJ 2 %d \n", resultC[0]);

        result = resultC[0];
      }

      if(!isIA) {
        if(result == 1) printf("Touche !\n" );
        else if(result == 2) printf("Touche coule !\n" );
        else printf("Flop ...\n" );
        printf("X : %d\n", x );
      }
      j->opponent[x][y] = (result == 0 ? 1 : 2);
      continuer = 0;
    }
  }
  setIAPlay(j, x, y, result);
}

void *waitOpponentR() {
  char t[2];
  // recv(conn, t, 2, 0);
  for(int i = 0; i < 10; i++) printf("wait %d : %d / %c\n", i, t[i], t[i]);

  opponentReady = 1;
}

void hostParty () {
  opponentReady = 0;
  struct sockaddr_in servsocket;
  pthread_t thread_id;
  int filedesc, continuer = 0;
  char message[100] = "";

  servsocket.sin_family = AF_INET;
  servsocket.sin_port = htons(8096);
  servsocket.sin_addr.s_addr = INADDR_ANY;

  filedesc = socket(AF_INET, SOCK_STREAM, 0);
  printf("Waiting opponent\n" );
  bind(filedesc, (struct sockaddr *)&servsocket, sizeof(servsocket));
  listen(filedesc,5);
  printf("connected\n");

  conn = accept(filedesc, (struct sockaddr *) NULL, NULL);
  printf("Conn ! %d / %d\n", conn, filedesc);
  pthread_create(&thread_id, NULL, waitOpponentR, NULL);

  Board *j1 = initPlayer(0);

  char c[2] = { 'o', '\0' };

  send(conn, c, strlen(c), 0);
  if(!opponentReady) printf("attente de l'adversaire\n" );

  pthread_join(thread_id, NULL);

  setBoardIA(j1);

  while (continuer == 0) {
      printf("debut\n");
      playJ(j1, NULL, 0, 1);
      char tab[3];
      recv(conn, tab, 3, 0);
      for(int i = -1; i < 5; i++) printf("%d : %d / %c\n", i, tab[i], tab[i]);
      printf("TEST RECEIve %d / %d\n", tab[0], tab[1]);
      sleep(1);
      char result[2] = { isItAShip(j1, tab[0], tab[1], 1), '\0' };
      send(conn, result, strlen(result), 0);
      printf("TEST send");

      if(isLose(j1)) continuer = 1;
  }
  exit(0);
}

void joinParty() {

  opponentReady = 0;
  struct sockaddr_in servsocket;
  pthread_t thread_id;
  int filedesc, continuer = 0;
  char message[100] = "";


  filedesc = socket(AF_INET, SOCK_STREAM, 0);
  servsocket.sin_family = AF_INET;
  servsocket.sin_port = htons(8096);

  inet_pton(AF_INET, "127.0.0.1", &servsocket.sin_addr);

  connect(filedesc, (struct sockaddr *)&servsocket, sizeof(servsocket));
  conn = filedesc;


  pthread_create(&thread_id, NULL, waitOpponentR, NULL);


  Board *j1 = initPlayer(0);
  char c[2] = { 'o', '\0' };

  send(conn, c, strlen(c), 0);

  if(!opponentReady) printf("attente de l'adversaire  \n" );

  pthread_join(thread_id, NULL);

  setBoardIA(j1);

  while (continuer == 0) {
      char tab[3];
      printf("debut\n" );

      recv(conn, tab, 3, 0);
      printf("%d / %d / %d\n", tab[0], tab[1], tab[2] );
      printf("data Receive : %d, %d\n",  tab[0], tab[1]);
      char result[2] = { isItAShip(j1, tab[0], tab[1], 1), 45 };
      sleep(1);
      send(conn, result, strlen(result), 0);
      printf("data send : %d, %d\n",  result[0], result[1]);

      playJ(j1, NULL, 0, 1);
      if(isLose(j1)) continuer = 1;
  }
}
