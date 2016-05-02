#include "ghostSan.h"
//author Phan Thanh San s3342133

//method used for the stupid Ghost
//the ghost will try to run into a corner and stay their, act as a gardian in a random area
char ghost_nimcoompoop_san(char** array, int row, int col, int ghostY, int ghostX){
	char finalresult = ' ';
	time_t sec;
    sec = time (NULL);
    
    // the ghost will try to move in a random direction. but rather running toward pacman/player,
    //it will just go on its own way instead
    if ((sec) % 2 == 0){
		if(checkWall(array, ghostY - 1, ghostX) == 1){
			finalresult = 'u';
		} else if(checkWall(array, ghostY, ghostX-1) == 1){
			finalresult = 'l';
		} else if(checkWall(array, ghostY+1, ghostX) == 1){
			finalresult = 'd';
		} else if(checkWall(array, ghostY, ghostX+1) == 1){
			finalresult = 'r';
		}
	}else {
		if(checkWall(array, ghostY, ghostX+1) == 1){
			finalresult = 'r';
		} else if(checkWall(array, ghostY+1, ghostX) == 1){
			finalresult = 'd';
		} else if(checkWall(array, ghostY - 1, ghostX) == 1){
			finalresult = 'u';
		} else if(checkWall(array, ghostY, ghostX-1) == 1){
			finalresult = 'l';
		}
	} 
	return finalresult;
}