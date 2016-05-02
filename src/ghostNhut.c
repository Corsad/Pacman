#include "ghostNhut.h"

//fill in the searchMap the possible movement of the ghost
void supportMethod(int** searchMap, int row, int col, int currentCounter,int currentY, int currentX, int pacY, int pacX)
{
	//do nothing if pacman and ghost are already in the same position
	if(currentX == pacX && currentY == pacY)
	{
		
		return;
	}

	//do nothing if the current position is outside the map
	if(currentX < 0 || currentY < 0 || currentX >= col || currentY >= row)
	{
		return;
	}

	//place the current counter in the current position of the map
	searchMap[currentY][currentX] = currentCounter;
	//if the upper position is not wall
	if(searchMap[currentY - 1][currentX] != -7)
	{
		//empty position
		if(searchMap[currentY - 1][currentX] == -1)
		{
			//recursively with currentCounter + 1
			supportMethod(searchMap,row, col, currentCounter + 1, currentY - 1, currentX, pacY, pacX);
		}
		else//not empty map
		{
			//the currentCounter + 1 is smaller than the number in the current position
			if(searchMap[currentY - 1][currentX] > currentCounter + 1)
			{
				//recursively with currentCounter + 1
				supportMethod(searchMap,row, col, currentCounter + 1, currentY - 1, currentX, pacY, pacX);
			}
		}
	}
//same for under, left, right position
	
	if(searchMap[currentY][currentX -1] != -7)
	{
		if(searchMap[currentY][currentX -1] == -1)
		{
			supportMethod(searchMap, row, col, currentCounter + 1, currentY, currentX -1, pacY, pacX);
		}
		else
		{
			if(searchMap[currentY][currentX -1] > currentCounter + 1)
			{
				supportMethod(searchMap, row, col, currentCounter + 1, currentY, currentX - 1, pacY, pacX);
			}
		}
	}

	if(searchMap[currentY + 1][currentX] != -7)
	{
		if(searchMap[currentY + 1][currentX] == -1)
		{
			supportMethod(searchMap, row, col, currentCounter + 1, currentY + 1, currentX, pacY, pacX);
		}
		else
		{
			if(searchMap[currentY + 1][currentX] > currentCounter + 1)
			{
				supportMethod(searchMap, row, col, currentCounter + 1, currentY + 1, currentX, pacY, pacX);
			}
		}
	}	

	if(searchMap[currentY][currentX + 1] != -7)
	{
		if(searchMap[currentY][currentX + 1] == -1)
		{
			supportMethod(searchMap, row, col, currentCounter + 1, currentY, currentX + 1, pacY, pacX);
		}
		else
		{
			if(searchMap[currentY][currentX + 1] > currentCounter + 1)
			{
				supportMethod(searchMap, row, col, currentCounter + 1, currentY, currentX + 1, pacY, pacX);
			}
		}
	}

	

}

//reversly chase from the pacman to get the direction of the ghost
void supportMethodReverse(int** searchMap, char* result, int row, int col, int currentCounter,int currentY, int currentX, int ghostY, int ghostX)
{
	//stop the recursive when counter get to 0
	if(currentCounter == 0)
	{
	
		if(currentX == ghostX - 1 && currentY == ghostY)
		{
			*result = 'l';
		}
		else if(currentX == ghostX + 1 && currentY == ghostY)
		{
			*result = 'r';
		}
		else if(currentX == ghostX && currentY == ghostY - 1)
		{
			*result = 'u';
		}
		else if(currentX == ghostX && currentY == ghostY + 1)
		{
			*result = 'd';
		}
		else
		{
			*result = 'n';
		}
		return;
		
	}
	
	//if the upper position contains the number equal to the currentCounter
	if(searchMap[currentY - 1][currentX] == currentCounter)
	{
		//recursively with the currentCounter - 1
		supportMethodReverse(searchMap, result, row, col, currentCounter - 1, currentY - 1, currentX, ghostY, ghostX);
	}

	//same for under, left, right position
	if(searchMap[currentY][currentX - 1] == currentCounter)
	{
		supportMethodReverse(searchMap, result, row, col, currentCounter - 1, currentY, currentX - 1, ghostY, ghostX);
	}

	if(searchMap[currentY + 1][currentX] == currentCounter)
	{
		supportMethodReverse(searchMap, result, row, col, currentCounter - 1, currentY + 1, currentX, ghostY, ghostX);
	}

	if(searchMap[currentY][currentX + 1] == currentCounter)
	{
		supportMethodReverse(searchMap, result, row, col, currentCounter - 1, currentY, currentX + 1, ghostY, ghostX);
	}

	return;

}

char ghostMove(char** array, int row, int col, int ghostY, int ghostX, int pacY, int pacX, int powerCount)
{
	if(powerCount != 0)
	{


	}else
	{
		//check the case that pacman and ghost are next to each other
		if(ghostY == pacY - 1 && ghostX == pacX)
		{
			return 'd';

		}

		if(ghostY == pacY + 1 && ghostX == pacX)
		{
			return 'u';
		}

		if(ghostY == pacY && ghostX == pacX - 1)
		{
			return 'r';
		}

		if(ghostY == pacY && ghostX == pacX + 1)
		{
			return 'l';
		}	
	}
	
	//draw an integer map which everything else is -1 and wall is -7
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
				searchMap[i][j] = -7;
			}
			else
			{
				searchMap[i][j] = -1;
			}
		}

	}

	
	//fill in the searchMap the possible movement counter by recursive go through all the possible path from the ghost to the pacman
	supportMethod(searchMap, row, col, 0, ghostY, ghostX, pacY, pacX);
	int minCounter = 25 * 25;
	//find the shortest path to the pacman by getting the smallest movement counter around the pacman
	if(pacY - 1 >= 0)
	{
		if(searchMap[pacY - 1][pacX] < minCounter && searchMap[pacY - 1][pacX] > 0)
		{
			minCounter = searchMap[pacY - 1][pacX];
		}	
	}

	if(pacX - 1 >= 0)
	{
		if(searchMap[pacY][pacX - 1] < minCounter && searchMap[pacY][pacX - 1] > 0)
		{
			minCounter = searchMap[pacY][pacX - 1];
		}
	}

	if(pacY + 1 < row)
	{
		if(searchMap[pacY + 1][pacX] < minCounter && searchMap[pacY + 1][pacX] > 0)
		{
			minCounter = searchMap[pacY + 1][pacX];
		}
	}

	if(pacX + 1 < col)
	{
		if(searchMap[pacY][pacX + 1] < minCounter && searchMap[pacY][pacX + 1] > 0)
		{
			minCounter = searchMap[pacY][pacX + 1];
		}	
	}

	if(minCounter == 25 * 25)
	{
		return 'n';
	}

	char finalresult = ' ';

	//recursively go reversely from the pacman to the ghost to find the direction of the ghost
	supportMethodReverse(searchMap, &finalresult, row, col, minCounter, pacY, pacX, ghostY, ghostX);

	//if pacman is powered up then find other way to go
	if(powerCount != 0)
	{
		char temp = ' ';
		if(finalresult == 'u')
		{
			if(checkWall(array, ghostY + 1, ghostX) == 1)
			{
				temp = 'd';
			}
			else if(checkWall(array, ghostY, ghostX - 1) == 1)
			{
				temp = 'l';
			}
			else if(checkWall(array, ghostY, ghostX + 1) == 1)
			{
				temp = 'r';
			}
			else
			{
				temp = finalresult;
			}
		}else if(finalresult == 'd')
		{
			if(checkWall(array, ghostY - 1, ghostX) == 1)
			{
				temp = 'u';
			}
			else if(checkWall(array, ghostY, ghostX - 1) == 1)
			{
				temp = 'l';
			}
			else if(checkWall(array, ghostY, ghostX + 1) == 1)
			{
				temp = 'r';
			}
			else
			{
				temp = finalresult;
			}
		}else if(finalresult == 'r')
		{
			if(checkWall(array, ghostY, ghostX - 1) == 1)
			{
				temp = 'l';
			}
			else if(checkWall(array, ghostY + 1, ghostX) == 1)
			{
				temp = 'd';
			}
			else if(checkWall(array, ghostY - 1, ghostX) == 1)
			{
				temp = 'u';
			}
			else
			{
				temp = finalresult;
			}
		}else if(finalresult == 'l')
		{
			if(checkWall(array, ghostY, ghostX + 1) == 1)
			{
				temp = 'r';
			}
			else if(checkWall(array, ghostY + 1, ghostX) == 1)
			{
				temp = 'd';
			}
			else if(checkWall(array, ghostY - 1, ghostX) == 1)
			{
				temp = 'u';
			}
			else
			{
				temp = finalresult;
			}
		}
		finalresult = temp;
	}
	return finalresult;
}