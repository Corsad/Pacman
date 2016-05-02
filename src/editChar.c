#include "editChar.h"

void edit_char(char** n, char a) {

	int x = 0;
	int y = 0;
	getyx(curscr, y, x);	
	
	if(a == 'q' || a == 'Q'){
		n[y][x]= a;
		addch(ACS_ULCORNER);
	} else if(a == 'w' || a == 'x'){
		n[y][x]= a;
		addch(ACS_HLINE);
	} else if(a == 'e' || a == 'E'){
		n[y][x]= a;
		addch(ACS_URCORNER);
	} else if(a == 'a' || a == 'd'){
		n[y][x]= a;
		addch(ACS_VLINE);
	} else if(a == 's'){
		attrset(COLOR_PAIR(8));
		n[y][x]= a;
		addch(ACS_BULLET);
		attrset(COLOR_PAIR(4));
	} else if(a == 'S'){
		attrset(COLOR_PAIR(6));
		n[y][x]= a;
		addch(ACS_DEGREE);
		attrset(COLOR_PAIR(4));
	} else if(a == 'z' || a == 'Z'){
		n[y][x]= a;
		addch(ACS_LLCORNER);
	} else if(a == 'c' || a == 'C'){
		n[y][x]= a;
		addch(ACS_LRCORNER);
	} else if(a == 'g' || a == 'G'){
		n[y][x]= a;
		addch(ACS_PI);
	} else if(a == 'p' || a == 'P'){
		n[y][x]= a;
		addch(n[y][x]);
	} else if(a == 'f' || a == 'F'){
		attrset(COLOR_PAIR(6));
		n[y][x]= a;
		addch(ACS_DIAMOND);
		attrset(COLOR_PAIR(4));
	} else if(a == 'W'){
		n[y][x]= a;
		addch(ACS_TTEE);
	} else if(a == 'A'){
		n[y][x]= a;
		addch(ACS_LTEE);
	} else if(a == 'D'){
		n[y][x]= a;
		addch(ACS_RTEE);
	} else if(a == 'X'){
		n[y][x]= a;
		addch(ACS_BTEE);
	} else if(a == ' '){
		n[y][x]= a;
		addch(' ');
	}	
}
