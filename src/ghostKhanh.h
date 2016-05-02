#ifndef Ghost_Khanh
#define Ghost_Khanh
#include <stdio.h> 
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "checkWall.h"

/** Recursive method to turn a char array into an int array that show the distance from pacman to ghost
  * @param n the integer array
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  * @param curY the row of the current cell
  * @param curX the column of the current cell
  * @param curNum the current number of the cell
  */
void mapping(int **n, int ghostY, int ghostX, int curY, int curX, int curNum);

/** A function to return the direction the ghost should move
  * Make by Khanh
  * @param array the char array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  * @param pacY the row the pacman is in
  * @param pacX the column the pacman is in
  * @param countPowerPt pointer to the number of turn pacman can still eat ghost
  */
char ghostMoveDir_Khanh(char** array, int row, int col, int ghostY, int ghostX, int pacY, int pacX, int countPowerPt);

#endif