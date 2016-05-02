#include "displayScore.h"

//clear the line on stdscr starting from the x = col, y = row
void clear_Line(int row,int col){
	move(row,col);
	for(int i = 0; i < 50; i++){
		addch(' ');
	}
}

//display a game details table netx to the map
void display_game_details(int score, int lifes, int power_count, int col, int bullet){
	int x = col;
	int y = 0;
	
	clear_Line(y,x+1);
	move(y,x+1);	
	printw("Scores: \t%i", score);
	
	clear_Line(y + 1,x + 1);
	move(y + 1,x + 1);
	printw("Lifes: \t%i", lifes);
	
	clear_Line(y + 2,x + 1);
	move(y + 2,x + 1);
	printw("bullets: \t%i", bullet);

	clear_Line(y + 3,x + 1);
	move(y + 3,x + 1);
	printw("Power: \t%i", power_count);

}