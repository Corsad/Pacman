#ifndef Pacman_Eating
#define Pacman_Eating

#include "structEntity.h"

/** Counting score ,powered turn and pallet left 
  * @param array the char array that represent the current map
  * @param y the number of row in the map
  * @param x the number of column in the map
  * @param PowerCountPt the pointer to powered turn left
  * @param scores the pointer to scores
  * @param countPalletPt the pointer to pallet left
  */
void eating(char** array, int y, int x, int *PowerCountPt, int *scores, int* countPalletPt);

#endif
