#ifndef Ghost_Phuc
#define Ghost_Phuc
#include <stdio.h> 
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "checkWall.h"

/** A function to return the direction the ghost should move
  * Make by Phuc
  * @param array the char array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  */
char ghostRandom_Phuc(char** array, int row, int col, int ghostY, int ghostX);

#endif