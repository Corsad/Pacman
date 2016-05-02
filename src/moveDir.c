#include "moveDir.h"

void moveDir(char c, struct entity e, char** n, int row, int col, char* structReplacedChar){

		char replacedChar;
		if(c == 'u'){
			if(e.type == 'p'){				

				
				move(row, col);
				edit_char(n,' ');
				
				n[row - 1][col] = 'p';
			} else if (e.type == 'g'){
				if(n[row - 1][col] != 'p' && n[row - 1][col] != 'P'){
					if(n[row - 1][col] != 'g' && n[row - 1][col] != 'G'){
						replacedChar = n[row - 1][col];
					} else {
						replacedChar = ' ';
					}
				} else {
					replacedChar = ' ';
				}
				
				move(row, col);
				edit_char(n,e.replacedChar);
				
				*structReplacedChar = replacedChar;
			}
			
		}   else if(c == 'd'){
			if(e.type == 'p'){				
				
				move(row, col);
				edit_char(n,' ');
				
				n[row + 1][col] = 'p';
			} else if (e.type == 'g'){
				if(n[row + 1][col] != 'p' && n[row + 1][col] != 'P'){
					if(n[row + 1][col] != 'g' && n[row + 1][col] != 'G'){
						replacedChar = n[row + 1][col];
					} else {
						replacedChar = ' ';
					}
				} else {
					replacedChar = ' ';
				}
				move(row, col);
				edit_char(n,e.replacedChar);
				
				*structReplacedChar = replacedChar;
			}
		}	else if(c == 'l'){
			if(e.type == 'p'){
				
				move(row, col);
				edit_char(n,' ');
			
				n[row][col - 1] = 'p';
				
			} else if (e.type == 'g'){
				if(n[row][col - 1] != 'p' && n[row][col - 1] != 'P'){
					if(n[row][col - 1] != 'g' && n[row][col - 1] != 'G'){
						replacedChar = n[row][col - 1];
					} else {
						replacedChar = ' ';
					}
				} else {
					replacedChar = ' ';
				}
				
				move(row, col);
				edit_char(n,e.replacedChar);
				

				
				*structReplacedChar = replacedChar;
			}
		}	else if(c == 'r'){			
			if(e.type == 'p'){

				
				move(row, col);
				edit_char(n,' ');
			
				n[row][col + 1] = 'p';
				
			} else if (e.type == 'g'){
				
				if(n[row][col + 1] != 'p' && n[row][col + 1] != 'P'){
					if(n[row][col + 1] != 'g' && n[row][col + 1] != 'G'){
						replacedChar = n[row][col + 1];
					} else {
						replacedChar = ' ';
					}
				} else {
					replacedChar = ' ';
				}
				
				move(row, col);
				edit_char(n,e.replacedChar);
				

				
				*structReplacedChar = replacedChar;
			}
		}
}