#include "highScore.h"
#include <curses.h>
#include <string.h>
#include <stdio.h>

struct timespec delay = {0, 500000000L},rem; // delay display

struct score
{
    char* user;
    int value;
};

void sort(struct score* userScore, int n) {
    int j,i;

    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(userScore[j].value < userScore[j+1].value)
            {
                struct score temp = userScore[j];
                userScore[j] = userScore[j+1];
                userScore[j+1] = temp;
            }
        }
    }
}

void highScore(){
  //should we make a new read file to read the high score or we can just modified the old read from file
    WINDOW* highscore_win = newwin(40,40, 0, 0);
    keypad(highscore_win, TRUE);

    mvprintw( 0, 0, "------PACMAN HIGHSCORE BOARD-------\n");

    FILE *fp = fopen("highscore.txt", "r");
    if (fp == NULL) {
           exit(EXIT_FAILURE);
    }

  
    int c=0;
    char ch='\0';

    while(ch!=EOF) {
        ch=fgetc(fp);
        if(ch=='\n')  c++;
    }
    fclose(fp);
  
    fp = fopen("highscore.txt", "r");
    size_t buffer_size = 32;
    char *buffer = malloc(buffer_size * sizeof(char));
  
    int arrayLength = c/2;
  
    struct score userScore[arrayLength];
    for (int i = 0; i < arrayLength; i++){
        userScore[i].user = malloc(sizeof(char)*20);
    }
    for (int i = 0; i < arrayLength; i++){
        getline(&buffer, &buffer_size, fp);
        //mvprintw(1, 0, "Player: %s", buffer);
        strcpy(userScore[i].user, buffer);
        getline(&buffer, &buffer_size, fp);
        //mvprintw(1, 0, " Score: %s", buffer);
        userScore[i].value = atoi(buffer);
    }

    sort(userScore, arrayLength);
    free(buffer);
    if(arrayLength > 5)
    {
        arrayLength = 5;
    }
    for (int i = 0; i < arrayLength; i++){
        
        mvprintw( 3 * i + 2, 0, "%d.Player: \t%s ", (i + 1), userScore[i].user);
        mvprintw( 3 * i + 3, 0, "Score: \t\t%d", userScore[i].value);
    
    }
    
        
    fclose(fp);
    getch();
    wclear(highscore_win);
    wrefresh(highscore_win);
    endwin();
}

