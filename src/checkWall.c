#include "checkWall.h"

/*check if the element at position x = col, y = row is wall or not.
return 1 if it is not wall, -1 if it is wall
 */
int checkWall(char** n, int row, int col){
			if(n[row][col] == 's' || n[row][col] == 'S'){
				return 1;
			} else if(n[row][col] == 'g' || n[row][col] == 'G'){
				return 1;
			} else if(n[row][col] == 'p' || n[row][col] == 'P'){
				return 1;
			} else if(n[row][col] == 'f' || n[row][col] == 'F'){
				return 1;
			}  else if(n[row][col] == ' '){
				return 1;
			}
	return -1;
}