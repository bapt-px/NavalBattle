#include "fct.h"
#include <string.h>


void copyString(char *t1, char *t2) {
  strncpy(t1, t2, 20);
    // int i = 0;
    // while(t2[i] != '\0') {printf("%c", t1[i]); t1[i] = t2[i++];}
    // t1[i] = '\0';
}
