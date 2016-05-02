#include "displayMap.h"

//display the map based on the input map in the char** array
void displayMap(char** array, int row, int col){

	//Display map old map
	for (int i = 0; i < row; i++)
	{	
		//read the map file and display it
		for (int j =0; j < col; j++)
		{
		move(i,j);
		if(strncmp(&array[i][j], "q", 1) == 0){
		addch(ACS_ULCORNER);
		} else if((strncmp(&array[i][j], "w", 1) == 0) || (strncmp(&array[i][j], "x", 1) == 0)){
		addch(ACS_HLINE);
		} else if(strncmp(&array[i][j], "e", 1) == 0){
		addch(ACS_URCORNER);
		} else if((strncmp(&array[i][j], "d", 1) == 0) || (strncmp(&array[i][j], "a", 1) == 0)){
		addch(ACS_VLINE);
		} else if(strncmp(&array[i][j], "s", 1) == 0){
		attrset(COLOR_PAIR(8));
		addch(ACS_BULLET);
		attrset(COLOR_PAIR(4));
		} else if(strncmp(&array[i][j], "S", 1) == 0){
		attrset(COLOR_PAIR(6));
		addch(ACS_DEGREE);
		attrset(COLOR_PAIR(4));
		} else if(strncmp(&array[i][j], "z", 1) == 0){
		addch(ACS_LLCORNER);
		} else if(strncmp(&array[i][j], "c", 1) == 0){
		addch(ACS_LRCORNER);
		} else if((strncmp(&array[i][j], "g", 1) == 0) || (strncmp(&array[i][j], "G", 1) == 0)){
		addch(ACS_PI);
		} else if((strncmp(&array[i][j], "p", 1) == 0) || (strncmp(&array[i][j], "P", 1) == 0)){
		addch(ACS_STERLING);
		} else if(strncmp(&array[i][j], "f", 1) == 0){
		attrset(COLOR_PAIR(6));
		addch(ACS_DIAMOND);
		attrset(COLOR_PAIR(4));
		} else if(strncmp(&array[i][j], "W", 1) == 0){
		addch(ACS_TTEE);
		} else if(strncmp(&array[i][j], "A", 1) == 0){
		addch(ACS_LTEE);
		} else if(strncmp(&array[i][j], "D", 1) == 0){
		addch(ACS_RTEE);
		} else if(strncmp(&array[i][j], "X", 1) == 0){
		addch(ACS_BTEE);
		} else {
		addch(' ');
		}
		}
	}
}