#include "fct.h"

void copyString(char *t1, char *t2) {
    int i = 0;
    while(t2[i] != '\0') t1[i] = t2[i++];
    t1[i] = '\0';
}
