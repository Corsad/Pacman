#ifndef Pacman_Executor
#define Pacman_Executor

#include <stdio.h> 
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include "displayMap.h"
#include "commandMode.h"
#include "writeHighScore.h"
#include "structEntity.h"
#include "moveDir.h"
#include "checkWall.h"
#include "editChar.h"
#include "displayScore.h"
#include "pacmanEating.h"
#include "levelChange.h"
#include "ghostNhut.h"
#include "ghostKhanh.h"
#include "ghostPhuc.h"
#include "ghostSan.h"

/** Play the pacman game
  * @param author the name of the author
  * @param title the name of the level
  * @param filename the name of the file
  * @param row the width of the map
  * @param col the height of the map
  * @param array a 2D array that stored the map
  * @param scores the pointer to scores
  * @param lifes the pointer to pacman amount of life
  * @param nextlifes the pointer to amount of scores pacman need to have still next life
  * @param lifes the pointer to pacman amount of life
  * @param choice the pointer to decide to clear the map or not
  * @param speed the speed of the game
  */
void pacmanExecutor(char* author, char* title, char* filename, int row, int col, char** array, int *scores, int *lifes, int *nextlifes, int *choice, int speed);

#endif

