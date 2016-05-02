#include "ghostKhanh.h"
#include <stdio.h>

void mapping(int **n, int ghostY, int ghostX, int curY, int curX, int curNum){
	//current cell number
	curNum ++;
	
	//check if the recursive method reach ghost of not
	if(curY == ghostY && curX == ghostX){
		n[ghostY][ghostX] = curNum;
		return;
	}
	
	//check wall and check if the surrounding cell is reachable from another shorter path
	//if not, adding the current integer to the cell and run the method again with that cell
	
	if(n[curY -1][curX] != -1){
		if(n[curY][curX] < n[curY - 1][curX] || n[curY - 1][curX] == 0){
			n[curY -1][curX] = curNum;
			mapping(n, ghostY, ghostX, curY - 1, curX, curNum);
		}
	}
	
	if(n[curY +1][curX] != -1){
		if(n[curY][curX] < n[curY + 1][curX] || n[curY + 1][curX] == 0){
			n[curY + 1][curX] = curNum;
			mapping(n, ghostY, ghostX, curY + 1, curX, curNum);
		}
	}
	
	if(n[curY][curX -1] != -1){
		if(n[curY][curX] < n[curY][curX -1] || n[curY][curX -1] == 0){
			n[curY][curX -1] = curNum;
			mapping(n, ghostY, ghostX, curY, curX - 1, curNum);
		}
	}
	
	if(n[curY][curX +1] != -1){
		if(n[curY][curX] < n[curY][curX + 1] || n[curY][curX + 1] == 0){
			n[curY][curX + 1] = curNum;
			mapping(n, ghostY, ghostX, curY, curX + 1, curNum);
		}
	}
	
}

char ghostMoveDir_Khanh(char** array, int row, int col, int ghostY, int ghostX, int pacY, int pacX, int countPowerPt)
{
	//check if pacman is next to you or not and whether pacman can eat ghost
	if(ghostY == pacY - 1 && ghostX == pacX)
	{
		if(countPowerPt == 0){
			return 'd';
		}
	}

	if(ghostY == pacY + 1 && ghostX == pacX)
	{
		if(countPowerPt == 0){			
			return 'u';
		}
	}
	
	if(ghostY == pacY && ghostX == pacX - 1)
	{
		if(countPowerPt == 0){			
			return 'r';
		}
	}

	if(ghostY == pacY && ghostX == pacX + 1)
	{
		if(countPowerPt == 0){
			return 'l';
		}		
	}
	
	//make an int array
	int** searchMap;
	searchMap = malloc(col*sizeof(int*));  
	for (int i = 0; i < row; i++) {
			searchMap[i] = malloc(row*sizeof(int));  
	}

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(checkWall(array, i, j) == -1)
			{
				searchMap[i][j] = -1;
			}
			else
			{
				searchMap[i][j] = 0;
			}
		}
	}
	
	// -1 so that the recursive didn't run for pacman location
	searchMap[pacY][pacX] = -1;
	char finalresult = 'u';

	mapping(searchMap, ghostY, ghostX, pacY, pacX, 0);
	
	//to compare
	int temp = 255;
	
	//check wall and compare for shortest path
	if(checkWall(array, ghostY -1, ghostX) == 1){
		if(temp >= searchMap[ghostY -1][ghostX] && searchMap[ghostY -1][ghostX] != 0){
			temp = searchMap[ghostY -1][ghostX];
			finalresult = 'u';
		}
	}
		
	if(checkWall(array, ghostY + 1, ghostX) == 1){
		if(temp >= searchMap[ghostY + 1][ghostX] && searchMap[ghostY +1][ghostX] != 0){
			temp = searchMap[ghostY + 1][ghostX];
			finalresult = 'd';
		}
	}
	
	if(checkWall(array, ghostY, ghostX - 1) == 1){
		if(temp >= searchMap[ghostY][ghostX - 1] && searchMap[ghostY][ghostX - 1] != 0){
			temp = searchMap[ghostY][ghostX - 1];
			finalresult = 'l';
		}
	}
		
	if(checkWall(array, ghostY, ghostX + 1) == 1){
		if(temp >= searchMap[ghostY][ghostX + 1] && searchMap[ghostY][ghostX + 1] != 0){
		temp = searchMap[ghostY][ghostX + 1];
			finalresult = 'r';
		}
	}
	
	// if pacman can eat ghost and the distance is less than 2 cells, run away from pacman 
 	if(countPowerPt != 0 && temp <= 2){
		temp = 0;
		
		if(checkWall(array, ghostY -1, ghostX) == 1){
			if(temp <= searchMap[ghostY -1][ghostX] && searchMap[ghostY -1][ghostX] != 0){
				temp = searchMap[ghostY -1][ghostX];
				finalresult = 'u';
			}
		}
		
		if(checkWall(array, ghostY + 1, ghostX) == 1){
			if(temp <= searchMap[ghostY + 1][ghostX] && searchMap[ghostY +1][ghostX] != 0){
				temp = searchMap[ghostY + 1][ghostX];
				finalresult = 'd';
			}
		}
		
		if(checkWall(array, ghostY, ghostX - 1) == 1){
			if(temp <= searchMap[ghostY][ghostX - 1] && searchMap[ghostY][ghostX - 1] != 0){
				temp = searchMap[ghostY][ghostX - 1];
				finalresult = 'l';
			}
		}
		
		if(checkWall(array, ghostY, ghostX + 1) == 1){
			if(temp <= searchMap[ghostY][ghostX + 1] && searchMap[ghostY][ghostX + 1] != 0){
				temp = searchMap[ghostY][ghostX + 1];
				finalresult = 'r';
			}
		}	
	}

	return finalresult;
}