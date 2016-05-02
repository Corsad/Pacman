#ifndef Map_Display
#define Map_Display

#include <stdlib.h>
#include <curses.h>
#include <string.h>

/** Print out the map to the screen based on the array
  * @param array the char array that represent the current map
  * @param row the number of row in the map
  * @param col the number of column in the map
  */
void displayMap(char** array, int row, int col);

#endif
