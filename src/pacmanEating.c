#include "pacmanEating.h"

void eating(char** array, int y, int x, int *PowerCountPt, int *scores, int* countPalletPt){
	if(array[y][x] == 'S'){
        *scores += 200;    
        *PowerCountPt = Power;
		*countPalletPt -= 1;
    } else if(array[y][x] == 's'){
        *scores += 100;
		*countPalletPt -= 1;
    } else if(array[y][x] == 'f' || array[y][x] == 'F'){
        *scores += 500;
    }    
}