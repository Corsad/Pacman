#include "writeHighScore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

void askForUserName(int highscore){
	printw("Game Over!\n");
	int stringLen = 0;
	char playerName[30];
	//char playerName[64];
	for (int i =0; i<30;i++){
        playerName[i] = ' ';
    }
	printw("Please enter your name: \n");
	

	for(;;){
		int ch = getch();
        if(ch == ERR){
            
            

        }else if(ch == 13){
        	printw("%d", highscore);
			printw("%s", playerName);
			playerName[stringLen] = '\0';
        	writeHighScore(playerName, highscore);
        	break;
        } else {
        	playerName[getcurx(stdscr)] =  ch;
        	stringLen++;
        	addch(ch);
        }
	}
	
}

void writeHighScore(char* playerName, int highscore){
	FILE *myfile = fopen("highscore.txt", "a++");
	if (myfile == NULL)
	{
	    printw("Error opening file!\n");
	    exit(EXIT_FAILURE);
	}
	
fprintf(myfile,"%s\n", playerName);
fprintf(myfile,"%d\n",highscore);
//fprintf(myfile,"\n");


fclose(myfile);
endwin();
exit(EXIT_SUCCESS);
}