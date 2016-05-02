#ifndef Read_From_File
#define Read_From_File

/** Read and display map from file
  * @param author the name of the author
  * @param title the name of the level
  * @param filename the name of the file
  * @param row the width of the map
  * @param col the height of the map
  * @param array a 2D array that stored the map
  */
char** readFromFile(char* author, char* title, char* filename, int* row, int* col, char** array);

#endif
