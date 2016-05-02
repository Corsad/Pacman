#include "drawMap.h"
#include "displayMap.h"
#include "writeToFile.h"
#include "readFromFile.h"
#include "commandMode.h"
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <time.h>
#include <assert.h>

//method used for drawing and editing map
void drawMap(char* author, char* title, char* filename, int row, int col, char** array){
    //(void) signal(SIGINT, finish);      /* arrange interrupts to terminate */
    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) noecho();         /* echo input - in color */
	
	//Display map old map
	displayMap(array, row, col);
		
	//Edit map
    for (;;) {
        int c = getch();     /* refresh, accept single keystroke of input */
        /* process the command keystroke */
		if ((getcurx(stdscr) < col) && (getcury(stdscr) < row))
		{
        if(c == KEY_RIGHT){
            move(getcury(stdscr), getcurx(stdscr) + 1);

        }else if(c == KEY_LEFT){
            move(getcury(stdscr), getcurx(stdscr) - 1);

        }else if(c == KEY_UP){
            move(getcury(stdscr) - 1, getcurx(stdscr));

        }else if(c == KEY_DOWN){
            move(getcury(stdscr) + 1, getcurx(stdscr));

        }else if (c == 'w' || c == 'x') {
			array[getcury(stdscr)][getcurx(stdscr)] = 'w';
            addch(ACS_HLINE);//horizontal line
        }else if(c == 'q' || c == 'Q'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'q';
            addch(ACS_ULCORNER);//upper left corner
        }else if(c == 'e' || c == 'E'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'e';
            addch(ACS_URCORNER);//upper right corner
        }else if(c == 'a' || c == 'd'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'd';
            addch(ACS_VLINE);//vertical line
        }else if(c == 's'){
            attrset(COLOR_PAIR(8));
			array[getcury(stdscr)][getcurx(stdscr)] = 's';
            addch(ACS_BULLET);//pellet
            attrset(COLOR_PAIR(4));
        }else if(c == 'S'){
            attrset(COLOR_PAIR(6));
			array[getcury(stdscr)][getcurx(stdscr)] = 'S';
            addch(ACS_DEGREE);//power pellet
            attrset(COLOR_PAIR(4));
        }else if(c == 'z' || c == 'Z'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'z';
            addch(ACS_LLCORNER);//lower left corner
        }else if(c == 'c' || c == 'C'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'c';
            addch(ACS_LRCORNER);//lower right corner
        }else if(c == 'g' || c == 'G'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'g';
            addch(ACS_PI);//ghost starting location
        }else if(c == 'p' || c == 'P'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'p';
            addch(ACS_STERLING);//Pacman starting location
        }else if(c == 'f' || c =='F'){
            attrset(COLOR_PAIR(6));
			array[getcury(stdscr)][getcurx(stdscr)] = 'f';
            addch(ACS_DIAMOND);//fruit location
            attrset(COLOR_PAIR(7));
        }else if(c == 'W'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'W';
            addch(ACS_TTEE);//top T line
        }else if(c == 'A'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'A';
            addch(ACS_LTEE);//left T line
        }else if(c == 'D'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'D';
            addch(ACS_RTEE);//right T line
        }else if(c == 'X'){
			array[getcury(stdscr)][getcurx(stdscr)] = 'X';
            addch(ACS_BTEE);//bottom T line
        }else if(c == ' '){
            move(getcurx(stdscr)-1, getcury(stdscr));
		}else if(c == ':'){
            //enter command mode
            commandMode(author, title, filename, row, col, array);
		}
		else if(c == 'n'){
            //testing array
			writeToFile(author, title, "test.txt", row, col, array);
		}
		}else 
		{
		      move(getcury(stdscr) - 1 ,getcurx(stdscr) - 1); //move back if cursor go off the grid
		}
        
    }       

}





