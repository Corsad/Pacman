#ifndef Display_Score
#define Display_Score

#include <stdlib.h>
#include <curses.h>
#include <string.h>

/** Clear char from line within a certain length
  * @param row the row that will be cleared
  * @param col the column that will be cleared
  */
void clear_Line(int row,int col);

/** Display scores, lifes, powered turn left, number of pallet left
  * @param score the amount of scores
  * @param lifes the amount of lifes
  * @param powerCount the amount of powered turn left
  * @param col the column that will be printed from
  * @param bullet the amount of pallet
  */
void display_game_details(int score, int lifes, int powerCount, int col, int bullet);

#endif
