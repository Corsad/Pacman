#ifndef Write_To_File
#define Write_To_File

/** Write the map into file
  * @param author the name of the author
  * @param title the name of the level
  * @param filename the name of the file
  * @param row the width of the map
  * @param col the height of the map
  * @param array a 2D array that stored the map
  */
void writeToFile(char* author, char* title, char* filename, int row, int col, char** array);

#endif
