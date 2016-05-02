#include "ghostPhuc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char ghostRandom_Phuc(char** array, int row, int col, int ghostY, int ghostX)
{
	char finalresult = ' ';
	srand ( time(NULL) );
	int number = (rand() % 4) + 1; //generate random number between 1 and 4
	
	switch (number){
			case 1:// prioritize up 
			if(checkWall(array, ghostY - 1, ghostX) == 1){
				finalresult = 'u';
			}
			else if(checkWall(array, ghostY + 1, ghostX) == 1){
				finalresult = 'd';
			}
			else if(checkWall(array, ghostY, ghostX - 1) == 1){
				finalresult = 'l';
			}
			else if(checkWall(array, ghostY, ghostX + 1) == 1){
				finalresult = 'r';
			}
				break;
			
			case 2:// prioritize down 
			if(checkWall(array, ghostY + 1, ghostX) == 1){
				finalresult = 'd';
			}
			else if(checkWall(array, ghostY, ghostX - 1) == 1){
				finalresult = 'l';
			}
			else if(checkWall(array, ghostY, ghostX + 1) == 1){
				finalresult = 'r';
			}
			else if(checkWall(array, ghostY - 1, ghostX) == 1){
				finalresult = 'u';
			}
				break;
			
			case 3:// prioritize left 
			if(checkWall(array, ghostY, ghostX - 1) == 1){
				finalresult = 'l';
			}
			else if(checkWall(array, ghostY, ghostX + 1) == 1){
				finalresult = 'r';
			}
			else if(checkWall(array, ghostY - 1, ghostX) == 1){
				finalresult = 'u';
			}
			else if(checkWall(array, ghostY + 1, ghostX) == 1){
				finalresult = 'd';
			}	
				break;
			
			case 4:// prioritize right 
			if(checkWall(array, ghostY, ghostX + 1) == 1){
				finalresult = 'r';
			}
			else if(checkWall(array, ghostY - 1, ghostX) == 1){
				finalresult = 'u';
			}
			else if(checkWall(array, ghostY + 1, ghostX) == 1){
				finalresult = 'd';
			}
			else if(checkWall(array, ghostY, ghostX - 1) == 1){
				finalresult = 'l';
			}
				break;
			
			default:
				break;
		} 
		
		return finalresult;
}

