#ifndef Write_High_Score
#define Write_High_Score

/** Write high score to file
  * @param playername the name of the player
  * @param highscore the score the player got
  */
void writeHighScore(char *playername, int highscore);

/** Ask the user for his name
  * @param highscore the score the player got
  */
void askForUserName(int highscore);

#endif