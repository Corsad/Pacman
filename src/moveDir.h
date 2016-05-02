#ifndef Move_Dir
#define Move_Dir

#include "editChar.h"
#include "structEntity.h"
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/** Print the old location of the pacman and ghost based on their movement
  * Pacman will print ' ' as it previous location
  * Ghost will replace the old char to the location that it just passed
  * @param c the direction of ghost and pacman
  * @param e the current entity
  * @param n the array that represent the map
  * @param row the number of row in the map
  * @param col the number of column in the map
  * @param structReplacedChar the char that will replace pacman and ghost in their old location
  */
void moveDir(char c, struct entity e, char** n, int row, int col, char* structReplacedChar);

#endif
