#include "commandMode.h"
#include <stdio.h>
#include <string.h>
#include <curses.h>
//method used for open command mode in edit map
/*
*@param author the author from main
*/


void commandMode(char* author, char* title, char* filename, int row, int col, char** array){
    //initialise the ncurses
    (void) initscr();
    (void) nonl();
    (void) cbreak();

    // display curses at the bottom screen for command mode
    int h = 0;
    int w = 0;
    getmaxyx(stdscr, h, w); 
    //move curses to the bottom of the screen
    move(h-1, 0); 
    clrtoeol();

    char buffer[20];
    char *keySearch = " ";
    char* token1 = NULL;
    char* token2 = NULL;
    char* token3 = "0";
    char* token4 = "0";
    
    //reset string buffer
    for (int i =0; i<20;i++){
        buffer[i] = ' ';
    }
    
    addch(':');//add : as default 
    for(;;){
        int ch = getch();
        if(ch == ERR){
            

        }else if(ch == 13){
            if(buffer != NULL){
                char *cstr = strdup(buffer); //clone the buffer 
                token1 = strtok(cstr, keySearch);   //cut it
                token2 = strtok(NULL, keySearch);
                token3 = strtok(NULL, keySearch);
                token4 = strtok(NULL, keySearch);
                
                if(strcmp(token1, "q") == 0){
                    //exit
                    for (int i = 0; i < 20;i++){
                        buffer[i] = ' ';
                    }
                    //free(cstr);
                    clear();
                    refresh();
                    endwin();
                    exit(EXIT_SUCCESS);
                    //system("clear");
                    break;
                } else if ((strcmp(token1, "w") == 0) && ((strcmp(token2, "q") == 0) || (strcmp(token2, "P") == 0))){
                    //write level to current file
                    writeToFile(author, title, filename, row, col, array);
                    
                    move(h - 1, 0);
                    clrtoeol();
                    printw("Saved");
                    move(0,0);
                    break;
                } else if ((strcmp(token1, "w") == 0)  && (token2 != NULL)){
                    //write level to current file with specific name
                    writeToFile(author, title, token2, row, col, array);
                    
                    move(h - 1, 0);
                    clrtoeol();
                    printw("Saved to %s.pac", token2);
                    move(0,0);
                    break;
                } else if(strcmp(token1, "wq") == 0 && ((strcmp(token2, "q") == 0) || (strcmp(token2, "P") == 0))){
                    //write then quit
                    writeToFile(author, title, filename, row, col, array);
                    //free(cstr);
                    clear();
                    refresh();
                    endwin();
                    exit(EXIT_SUCCESS);
                    
                } else if(strcmp(token1, "wq") == 0 && token2 != NULL){
                    //write to specific file then quit;
                    writeToFile(author, title, token2, row, col, array);
                    
                    //free(cstr);
                    clear();
                    refresh();
                    endwin();
                    exit(EXIT_SUCCESS);
                } else if(strcmp(token1, "r") == 0 && token2 != NULL){
                    //read file name
                    filename = token2;
                    array = readFromFile(author, title, filename, &row, &col, array);
                    clear();
                    refresh();
                    drawMap(author, title, filename, row, col, array);
                } else if(strcmp(token1, "n") == 0 && token2 != NULL && token3 != NULL && token4 != NULL && isdigit(*token3) && isdigit(*token4)){
                    //create new map with specific row and collumn
                    int inputRow = atoi(token3);
                        //int *inputRowPt = &inputRow;
                    int inputCol = atoi(token4);
                        //int *inputColPt = &inputCol;
                    //initialize new array for writing
                    char** newArray;
                    newArray = malloc(inputCol*sizeof(char*));  
                    for (int i = 0; i < inputRow; i++) {
                        newArray[i] = malloc(inputRow*sizeof(char));  
                    }
                    
                    for (int i = 0; i < inputRow; i++)
                    {
                        for (int j = 0; j < inputCol; j++)
                        {
                            newArray[i][j] = 's';
                        }
                    }
                    
                    writeToFile(author, title, token2, inputRow, inputCol, newArray);

                    //free(cstr);
                    clear();
                    refresh();
					endwin();                   
                    exit(EXIT_SUCCESS);
                } else if ((strcmp(token1, "m") == 0)  && (token2 != NULL) && (token3 != NULL)){
                    //modify author and title
                    writeToFile(token2, token3, filename, row, col, array);
                    
                    move(h - 1, 0);
                    clrtoeol();
                    printw("%s.pac modified", filename);
                    move(0,0);
                    break;
                } else {
					clear_Line(h-1,0);
					move(h-1,0);
                    printw("Error input");
                    break;
                }
            } else {
                for (int i =0; i<20;i++){
                    buffer[i] = ' ';
                    //free(buffer);
                }
                move(h - 1, 0);
                clrtoeol();
                move(0,0);
                break;
            }

        }else if (ch == 27){
            //exit command mode with escape
            for (int i =0; i<20;i++){
                buffer[i] = ' ';
            }
            move(h - 1, 0);
            clrtoeol();
            move(0,0);
            break;
        } else if(ch == KEY_BACKSPACE){
            int x = getcurx(stdscr);
			
            if(x != 1){
                //erase character
                move(h-1, getcurx(stdscr)-1);
                delch();
                buffer[getcurx(stdscr)-1] = '\0';           
            }
        }
        
        else {
            //read the character user input in command mode            
            buffer[getcurx(stdscr)-1] =  ch;
            addch(ch);
        }
            
    }
}
