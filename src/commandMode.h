#ifndef Command_Mode
#define Command_Mode

#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
#include <ctype.h>
#include "writeToFile.h"
#include "readFromFile.h"
#include "drawMap.h"
#include "displayScore.h"

/** Open the command mode when pressing ":"
  * @param author the name of the author
  * @param title the name of the level
  * @param filename the name of the file
  * @param row the width of the map
  * @param col the height of the map
  * @param array a 2D array that stored the map
  */
void commandMode(char* author, char* title, char* filename, int row, int col, char** array);

#endif
