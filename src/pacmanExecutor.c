#include "pacmanExecutor.h"
#include <stdio.h> 
#include <unistd.h>
#include <signal.h>

void pacmanExecutor(char* author, char* title, char* filename, int row, int col, char** array, int *scores, int *lifes,int *nextlifes, int *choice, int speed){
	initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    nonl();         /* tell curses not to do NL->CR/NL on output */
    timeout(-1);	/* tell curses to wait for input forever */
    noecho();         /* echo input - in color */
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    attrset(COLOR_PAIR(4));

    struct timespec delay = {1, 0},rem; // delay display

	int isCheat = 0;
    int cheat = 0;
    char* cheatCode = malloc(sizeof(char) * 4);
//----------------------------------------------------------------------------------------------------------

	displayMap(array, row, col);

	
	int countEntity = 0;
	int countPallet = 0;
	int *countPalletPt = &countPallet;
	int PowerCount = 0;
	int *PowerCountPt = &PowerCount;
	
	//count the number of ghost and pacman
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(array[i][j] == 'p' || array[i][j] == 'P' || array[i][j] == 'g' || array[i][j] == 'G'){
				countEntity++;
			} else if(array[i][j] == 's' || array[i][j] == 'S'){
				countPallet++;
			}
		}
	}

	struct entity *ptr[countEntity];

	for(int i = 0; i < countEntity; i++)
	{
		ptr[i] = malloc(sizeof(struct entity));
	}

	int originalRow[countEntity];
	int originalCol[countEntity];
	
	//pacman will be the first element(element 0) while the first ghost will be element 1
	int count = 1;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(array[i][j] == 'p' || array[i][j] == 'P')
			{
				struct entity temp;
				temp.x = j;
				temp.y = i;
				
				originalRow[0] = i;
				originalCol[0] = j;
				temp.dir = 'r';
				temp.type = 'p';
				temp.replacedChar = ' ';
				ptr[0] = &temp;
				
			} else if ( array[i][j] == 'g' || array[i][j] == 'G')
			{
				struct entity *temp = malloc(sizeof(struct entity));
				temp->x = j;
				temp->y = i;

				originalCol[count] = temp->x;
				originalRow[count] = temp->y;

				temp->type = 'g';
				temp->replacedChar = ' ';
				temp->dir = 'u';
				ptr[count] = temp;
				
				count++;
				array[temp->y][temp->x] = ' ';
			}
		}
	}
	
	int deathCount[count-1];	
	int deathStatus[count-1];
	
	for(int i = 0; i < count-1; i++){
		deathCount[i]=0;
		deathStatus[i]=0;
	}

	int turn = 0;
	while(*lifes > 0){

		timeout(speed);
		int x = ptr[0]->x;
		int y = ptr[0]->y;
		move(y,x);
		int countAnnouncement = 0;
		if(isCheat == 1)
		{
			PowerCount = 100;
		}
//------------------------------------------------------------------------------------------------------------	

	    int c = getch();
	    if(c == -1)
	    {
	    	if(ptr[0]->dir == 'u')
			{
				c = KEY_UP;
			}else if (ptr[0]->dir == 'd')
			{
				c = KEY_DOWN;
			}else if(ptr[0]->dir == 'l')
			{
				c = KEY_LEFT;
			}else if(ptr[0]->dir == 'r')
			{
				c = KEY_RIGHT;
			}	
	    }else
	    {
	    	if(ptr[0]->dir == 'u' && c == KEY_UP)
			{
				c = -2;
			}else if (ptr[0]->dir == 'd' && c == KEY_DOWN)
			{
				c = -2;
			}else if(ptr[0]->dir == 'l' && c == KEY_LEFT)
			{
				c = -2;
			}else if(ptr[0]->dir == 'r' && c == KEY_RIGHT)
			{
				c = -2;
			}
	    }
	    
//------------------------------------------------------------------------------------------------------------
		/* refresh, accept single keystroke of input */
        /* process the command keystroke */

		char* replacedCharPt = &ptr[0]->replacedChar;
		if (c == KEY_UP) {
			if(y > 0 && checkWall(array, y-1, x) == 1){
				eating(array, y-1, x, PowerCountPt, scores, countPalletPt);
				
				moveDir('u', *ptr[0],array, y,x, replacedCharPt);
				ptr[0]->y -= 1; 
				ptr[0]->dir = 'u';			
			}
		} else if (c == KEY_DOWN){
			if(checkWall(array, y+1, x) == 1){
				eating(array, y+1, x, PowerCountPt, scores, countPalletPt);
				
				moveDir('d', *ptr[0],array, y,x, replacedCharPt);
				ptr[0]->y += 1; 
				ptr[0]->dir = 'd';
			}
		} else if (c == KEY_LEFT){
			if(x > 0 && checkWall(array, y, x-1) == 1){
				eating(array, y, x-1, PowerCountPt, scores, countPalletPt);
				
				moveDir('l', *ptr[0],array, y,x, replacedCharPt);
				ptr[0]->x -= 1; 
				ptr[0]->dir = 'l';
			}
		} else if (c == KEY_RIGHT){
			if(checkWall(array, y, x+1) == 1){
				eating(array, y, x+1, PowerCountPt, scores, countPalletPt);
				
				moveDir('r', *ptr[0],array, y,x, replacedCharPt);
				ptr[0]->x += 1; 
				ptr[0]->dir = 'r';
			}
		} else if(c == ':'){
			timeout(-1);
			int ch = getch();
			if(ch == 'q')
			{
				*choice = 1;

				break;
			}
			
		} else
		{
			
			cheatCode[cheat] = c;
			cheat++;
			if(cheat == 4)
			{
				if(cheatCode[0] == 's' && cheatCode[1] == 'p' && cheatCode[2] == 'n' && cheatCode[3] == 'k')
				{
					isCheat = 1;
				}
				cheat = 0;
			}

			if(c == 'r')
			{
				cheat = 0;
			}else if(c == 'q')
			{
				isCheat = 0;
				PowerCount = 5;
			}

		}
					
		

		if(countPallet == 0){
			break;
		}
		
		//gain 1 life if player get enough score
		if(*scores >= *nextlifes){
			*lifes += 1;
			*nextlifes += 5000;
		}
		
		
		//ghost check
		int isDead = 0;
		for(int i = 1; i < countEntity; i++){ //check if ghost is dead

			if(deathCount[i-1] > 0){
				deathCount[i-1] --;
			}
			
			//check ghost condition to re-sqpawn ghost
			if(deathStatus[i-1] == 1 && deathCount[i-1] == 0){
				move(ptr[i]->y,ptr[i]->x);
				edit_char(array,'g');
				deathStatus[i-1]=0;
			}
			
			//for ghost move
			if(ptr[0]->x == ptr[i]->x && ptr[0]->y == ptr[i]->y && PowerCount == 0 && deathStatus[i-1] != 1){
				*lifes -= 1;
				move(ptr[0]->y,ptr[0]->x);
				edit_char(array,'g');
				
				ptr[0]->x = originalCol[0];
				ptr[0]->y = originalRow[0];
				move(originalRow[0],originalCol[0]);
				edit_char(array,'p');
				ptr[i]->replacedChar = ' ';					
				array[ptr[0]->y][ptr[0]->x] = ' ';

				attrset(COLOR_PAIR(2));
				clear_Line(4, col + 1);							
				mvprintw(4, col + 1, "Pacman is killed by ghost no.%d", i);
				attrset(COLOR_PAIR(4));
				countAnnouncement++;
				isDead = 1;

			} else if (ptr[0]->x == ptr[i]->x && ptr[0]->y == ptr[i]->y && PowerCount != 0 && deathStatus[i-1] != 1){					
				deathCount[i-1] = 5;
				deathStatus[i-1] = 1;

				ptr[i]->x = originalCol[i];
				ptr[i]->y = originalRow[i];

				*scores += 1000;
				ptr[i]->replacedChar = ' ';						
				array[ptr[0]->y][ptr[0]->x] = ' ';

				attrset(COLOR_PAIR(2));
				clear_Line(4, col + 1);						
				mvprintw(4, col + 1, "Pacman kills ghost no.%d", i);
				attrset(COLOR_PAIR(4));
				countAnnouncement++;

			}	else {
								
				x = ptr[i]->x;
				y = ptr[i]->y;
				
				move(y,x);
				
				if(deathStatus[i-1] != 1){
					char ghostDir = 'n';
					
					replacedCharPt = &ptr[i]->replacedChar;
					if(i == 1)
					{
						ghostDir = ghostMove(array, row, col, ptr[i]->y, ptr[i]->x, ptr[0]->y, ptr[0]->x, PowerCount);	
					}
					else if(i == 2)
					{
						ghostDir = ghostMoveDir_Khanh(array, row, col, ptr[i]->y, ptr[i]->x, ptr[0]->y, ptr[0]->x, PowerCount);

					}
					else if(i == 3)
					{
						ghostDir = ghostRandom_Phuc(array, row, col, ptr[i]->y, ptr[i]->x);
					}
					else if(i == 4)
					{
						ghostDir = ghost_nimcoompoop_san(array, row, col, ptr[i]->y, ptr[i]->x);
					}

					
					moveDir( ghostDir, *ptr[i], array, y,x, replacedCharPt);
					
					
					if(ghostDir == 'u')
					{
						ptr[i]->y -= 1;

					} else if(ghostDir == 'd')
					{
						ptr[i]->y += 1;							

					} else if(ghostDir == 'l')
					{
						ptr[i]->x -= 1;

					} else if(ghostDir == 'r')
					{
						ptr[i]->x += 1;

					}
					

				}

				//check pacman and ghost collision condition.
				if(ptr[0]->x == ptr[i]->x && ptr[0]->y == ptr[i]->y && PowerCount == 0 && deathStatus[i-1] != 1){
					*lifes -= 1;
					move(ptr[0]->y,ptr[0]->x);
					edit_char(array,'g');
					
					ptr[0]->x = originalCol[0];
					ptr[0]->y = originalRow[0];
					move(originalRow[0],originalCol[0]);
					edit_char(array,'p');
					ptr[i]->replacedChar = ' ';						
					array[ptr[0]->y][ptr[0]->x] = ' ';

					
					attrset(COLOR_PAIR(2));
					clear_Line(4, col + 1);						
					mvprintw(4, col + 1, "Pacman is killed by ghost no.%d", i);
					attrset(COLOR_PAIR(4));
					countAnnouncement++;

					isDead = 1;
				} else if (ptr[0]->x == ptr[i]->x && ptr[0]->y == ptr[i]->y && PowerCount != 0 && deathStatus[i-1] != 1){					
					deathCount[i-1] = 5;
					deathStatus[i-1] = 1;	


					ptr[i]->x = originalCol[i];
					ptr[i]->y = originalRow[i];


					*scores += 1000;
					ptr[i]->replacedChar = ' ';
					array[ptr[0]->y][ptr[0]->x] = ' ';

					attrset(COLOR_PAIR(2));
					clear_Line(4, col + 1);						
					mvprintw(4, col + 1, "Pacman kills ghost no.%d", i);
					attrset(COLOR_PAIR(4));
					

				}
			}	
		}		

		for(int k = 1; k < countEntity; k++)
		{
			if (PowerCount!= 0)
    		{
    			attrset(COLOR_PAIR(3));
    		} 
    		else
    		{
    			if(k == 1)
    			{
    				attrset(COLOR_PAIR(2));	
    			}
    			else if(k == 2)
    			{
    				attrset(COLOR_PAIR(5));
    			}
    			else if(k == 3)
    			{
    				attrset(COLOR_PAIR(7));

    			}else if(k == 4)
    			{
    				attrset(COLOR_PAIR(8));
    			}

    		}
			if(deathStatus[k-1] == 0)
			{
				move(ptr[k]->y,ptr[k]->x);
				edit_char(array,'g');
			}
		}
		
		attrset(COLOR_PAIR(4));
		attrset(COLOR_PAIR(1));	

		move(ptr[0]->y, ptr[0]->x);
		edit_char(array,'p');
		attrset(COLOR_PAIR(4));
					
		if(PowerCount > 0){
			PowerCount--;
		}
		if(turn % 2 == 0)
		{
			attrset(COLOR_PAIR(8));	
		}
		else
		{
			attrset(COLOR_PAIR(3));
		}
		turn++;
		
		display_game_details(*scores,*lifes,PowerCount,col, countPallet);
		attrset(COLOR_PAIR(4));

		if(isDead == 1)
		{
			attrset(COLOR_PAIR(8));
			mvprintw(10, col + 1, "Pacman is coming back in 1 second. Revengeee!");
			attrset(COLOR_PAIR(4));
			move(originalRow[0], originalCol[0]);
			refresh();
			nanosleep(&delay, &rem);
			clear_Line(10, col + 1);
			PowerCount = 5;
		}
	}

	if(*lifes == 0){
	clear();
	askForUserName(*scores);

    } else 
    {
    	clear();

    }
}