#include "drawMap.h"
#include "writeToFile.h"
#include "readFromFile.h"
#include "commandMode.h"
#include "pacmanExecutor.h"
#include "highScore.h"
#include "levelChange.h"
#include "credit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define NUMBEROFITEMS   5

char *pacman_menu_choices[] = {
                        "1. PlAY NORMAL GAME",
                        "2. MAP EDITOR",
                        "3. HIGH SCORE TABLE",
                        "4. CREDITS",
                        "5. EXIT PACMAN",
                        
                  };
//copy from http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/menus.html
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{   int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}
//main program contain the menu for the game

void free_pacman(char* author, char* title, char** mapArray, int row, int col)
{
    free(author);
    free(title);
    for(int i = 0; i < row; i++)
    {
        free(mapArray[i]);
    }
    free(mapArray);
}

int main(int argc, char *argv[])
{   
    

    int col = 25;
    int row = 25;

    int scores = 0;
    int *scoresPt = &scores;

    int lifes = 3;
    int *lifesPt = &lifes;    

    int nextlifes = 5000;
    int *nextlifesPt = &nextlifes;
    
    char* filename = NULL;
    char* author_df = "Khuu Vinh Hoang Phuc <s3345250@rmit.edu.vn>, Phan Thanh San <s3342133@rmit.edu.vn>";

    char* author = malloc(128*sizeof(char));
    stpcpy(author, author_df);

    char* title_df = "Level Default";
    
    char* title = malloc(128*sizeof(char));    
    stpcpy(title, title_df);
    
    char** mapArray;
    mapArray = malloc(col*sizeof(char*));  
    for (int i = 0; i < row; i++) {
            mapArray[i] = malloc(row*sizeof(char));  
    }

    if(argc == 2){
        initscr();
        filename = argv[1];
        mapArray = readFromFile(author, title, filename, &row, &col, mapArray); // return author, title, filename, col , row and map that is written in the text file
        drawMap (author, title, filename, row, col, mapArray); //call drawMap for editing
    } else {
        int selectedItem = 1;
        while(selectedItem != 5)
        {
            selectedItem = 1;
            ITEM **pacman_menu_items;
            int c;              
            MENU *pacman_menu;
            WINDOW *pacman_menu_win;
            int n_pacman_menu_choices, i;
        
            /* Initialize curses */
            initscr();
            start_color();

            init_pair(1, COLOR_BLACK, COLOR_BLACK);
            init_pair(2, COLOR_RED, COLOR_BLACK);
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
            init_pair(4, COLOR_YELLOW, COLOR_BLACK);
            init_pair(5, COLOR_BLUE, COLOR_BLACK);
            init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
            init_pair(7, COLOR_CYAN, COLOR_BLACK);
            init_pair(8, COLOR_WHITE, COLOR_BLACK);
            noecho();
            keypad(stdscr, TRUE);
            init_pair(1, COLOR_RED, COLOR_BLACK);

        /* Create items */
            n_pacman_menu_choices = ARRAY_SIZE(pacman_menu_choices);
            pacman_menu_items = (ITEM **)calloc(n_pacman_menu_choices + 1, sizeof(ITEM *));

            for(int i = 0; i < n_pacman_menu_choices; ++i)
            {
                pacman_menu_items[i] = new_item(" ",pacman_menu_choices[i]);
            }
                    

        /* Crate menu */
            pacman_menu = new_menu((ITEM **)pacman_menu_items);

        /* Create the window to be associated with the menu */
            pacman_menu_win = newwin(10, 40, 0, 0);
            keypad(pacman_menu_win, TRUE);
         
        /* Set main window and sub window */
            set_menu_win(pacman_menu, pacman_menu_win);
            set_menu_sub(pacman_menu, derwin(pacman_menu_win, 6, 38, 3, 1));

        /* Set menu mark to the string " * " */
            set_menu_mark(pacman_menu, " >>> ");

        /* Print a border around the main window and print a title */
            box(pacman_menu_win, 0, 0);
            print_in_middle(pacman_menu_win, 1, 0, 40, "WELCOME TO WORLD OF PACMAN!!!", COLOR_PAIR(1));
            mvwaddch(pacman_menu_win, 2, 0, ACS_LTEE);
            mvwhline(pacman_menu_win, 2, 1, ACS_HLINE, 38);
            mvwaddch(pacman_menu_win, 2, 39, ACS_RTEE);
            mvprintw(LINES - 2, 0, "This game is created by SPNK");
                
            /* Post the menu */
            post_menu(pacman_menu);
            wrefresh(pacman_menu_win);
            
            while((c = wgetch(pacman_menu_win)) != 10)
            {   switch(c)
                {   
                    case KEY_DOWN:
                    if(selectedItem < NUMBEROFITEMS)
                    {
                        selectedItem++;
                    }
                    menu_driver(pacman_menu, REQ_DOWN_ITEM);
                    break;
                    
                    case KEY_UP:
                    if(selectedItem > 1)
                    {
                        selectedItem--;
                    }
                    menu_driver(pacman_menu, REQ_UP_ITEM);
                    break;
                }
                
            }   

            /* Unpost and free all the memory taken up */
            unpost_menu(pacman_menu);
            free_menu(pacman_menu);

            for(i = 0; i < n_pacman_menu_choices; ++i)
            {
                free_item(pacman_menu_items[i]);
            }

            wclear(pacman_menu_win);
            wrefresh(pacman_menu_win);
            endwin();
            

            int nhut = 0;
            int* choicePt = &nhut;
            int speed = 300;
            switch(selectedItem){
                case 1:
                    mapArray = readFromFile(author, title, "level1", &row, &col, mapArray);
                    pacmanExecutor(author, title, "level1", row, col, mapArray, scoresPt, lifesPt, nextlifesPt, choicePt, speed);
                    if(nhut == 1)
                    {
                        nhut = 0;
                        wclear(stdscr);
                        wrefresh(stdscr);
                        free_pacman(author, title, mapArray, 25, 25);
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    speed = speed - 70;

                    mapArray = readFromFile(author, title, "level2", &row, &col, mapArray);
                    pacmanExecutor(author, title, "level2", row, col, mapArray, scoresPt, lifesPt, nextlifesPt, choicePt, speed);
                    if(nhut == 1)
                    {
                        nhut = 0;
                        wclear(stdscr);
                        wrefresh(stdscr);
                        free_pacman(author, title, mapArray, 25, 25);
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    speed = speed - 70;

                    mapArray = readFromFile(author, title, "level3", &row, &col, mapArray);
                    pacmanExecutor(author, title, "level3", row, col, mapArray, scoresPt, lifesPt, nextlifesPt, choicePt, speed);
                    if(nhut == 1)
                    {
                        nhut = 0;
                        wclear(stdscr);
                        wrefresh(stdscr);
                        free_pacman(author, title, mapArray, 25, 25);
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    speed = speed - 70;

                    mapArray = readFromFile(author, title, "level4", &row, &col, mapArray);
                    pacmanExecutor(author, title, "level4", row, col, mapArray, scoresPt, lifesPt, nextlifesPt, choicePt, speed);
                    if(nhut == 1)
                    {
                        nhut = 0;
                        wclear(stdscr);
                        wrefresh(stdscr);
                        free_pacman(author, title, mapArray, 25, 25);
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    speed = speed - 70;

                    askForUserName(*scoresPt);
                    break;

                case 2:

                    mapArray = readFromFile(author, title, "default", &row, &col, mapArray);
                    attrset(COLOR_PAIR(4));
                    drawMap(author, title, "default", row, col, mapArray);
                    break;

                case 3:
                    highScore();
                    break;
                    
                case 4: 
                    credit();                
                    break;
                    
                case 5:
                    free_pacman(author, title, mapArray, 25, 25);
                    exit(EXIT_SUCCESS);
                    break;
                    
            }
        }
    } 
    free_pacman(author, title, mapArray, 25, 25);
    return 0;
}

