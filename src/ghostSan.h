//header file contain the prototype of the method ghost in file ghostSan.c 
#ifndef Ghost_San
#define Ghost_San

#include <stdio.h> 
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "checkWall.h"

/** A function to return the direction the ghost should move
  * Make by San
  * @param array the char array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  */
char ghost_nimcoompoop_san(char** array, int row, int col, int ghostY, int ghostX);

#endif