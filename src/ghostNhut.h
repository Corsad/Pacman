#ifndef Ghost_Nhut
#define Ghost_Nhut
#include <stdio.h> 
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "checkWall.h"

#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include "displayScore.h"

/** A recursive method to go from ghost to pacman
  * @param searchMap the int array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param currentCounter the current number of the cell
  * @param currentY the row the current cell is in
  * @param currentX the column the current cell is in
  * @param pacY the row the pacman is in
  * @param pacX the column the pacman is in
  */
void supportMethod(int** searchMap, int row, int col, int currentCounter,int currentY, int currentX, int pacY, int pacX);

/** A recursive method to go from pacman to ghost
  * @param searchMap the int array that represent the current map
  * @param result the char the represent the direction ghost should take
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param currentCounter the current number of the cell
  * @param currentY the row the current cell is in
  * @param currentX the column the current cell is in
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  */
void supportMethodReverse(int** searchMap, char* result, int row, int col, int currentCounter,int currentY, int currentX, int ghostY, int ghostX);

/** A function to return the direction the ghost should move
  * Make by Nhut
  * @param array the char array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param ghostY the row the ghost is in
  * @param ghostX the column the ghost is in
  * @param pacY the row the pacman is in
  * @param pacX the column the pacman is in
  * @param powerCount pointer to the number of turn pacman can still eat ghost
  */
char ghostMove(char** array, int row, int col, int ghostY, int ghostX, int pacY, int pacX, int powerCount);
#endif