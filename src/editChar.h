#ifndef Edit_Char
#define Edit_Char

#include <curses.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

/** Add char to screen and replace char in array
  * @param n the name of the array
  * @param a the new char that will replace the old char
  */
void edit_char(char** n, char a);

#endif
