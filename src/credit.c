#include "credit.h"

//display the credit of the pacman game
void credit(){
	
	//create a window to display the credit
	WINDOW* credit_win = newwin(40,40, 0, 0);
	keypad(credit_win, TRUE);
	
	//display credit information
	mvprintw( 0, 0, "--------------Credits-------------\n");	
	mvprintw( 2, 0, "------------Pacman Game-----------\n");	
	mvprintw( 4, 0,"----------Develped by SPNK--------\n");	
	mvprintw( 6, 0,"----------------------------------\n");
	mvprintw( 8, 0,"------------Team Members----------\n");	
	mvprintw( 10, 0,"----S3342133--Phan Thanh San------\n");
	mvprintw( 12, 0,"-s3345250--Khuu Vinh Hoang Phuc---\n");	
	mvprintw( 14, 0,"-----s3372771--Dang Kim Khanh-----\n");	
	mvprintw( 16, 0,"------s3393315--Vo Minh Nhut------\n");	
	mvprintw( 20, 0,"Press any key to continue");
	//wait for a key
	getch();
	//clear window and end the current window
	wclear(credit_win);
    wrefresh(credit_win);
	endwin();

}