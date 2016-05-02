#include "readFromFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

//method used to read file

char** readFromFile(char* author, char* title, char* filename, int* row, int* col, char** array){
	FILE *fp;
	
	//append string for file path
	char* path = "levels/";
	char* ext = ".pac";
	char * fullpath = NULL;
	if((fullpath = malloc(strlen(path)+strlen(filename)+strlen(ext)+1)) != NULL){
    fullpath[0] = '\0';   // ensures the memory is an empty string
    strcat(fullpath,path);
    strcat(fullpath,filename);
	strcat(fullpath,ext);
	} else {
		endwin();
	}
	
	fp = fopen(fullpath, "r");
	

				
    size_t buffer_size = 128;
    char *buffer = malloc(buffer_size * sizeof(char));
	
	//parsing author
	getline(&buffer, &buffer_size, fp);
	for(int i = 0; i < buffer_size; i++)
	{
		author[i] = buffer[i];
		if (buffer[i] == '\n'){
		author[i] = '\0';
		}
	}
	printf("%s\n", author);


	//parsing title
	getline(&buffer, &buffer_size, fp);
	for(int i = 0; i < buffer_size; i++)
	{
		title[i] = buffer[i];
		if (buffer[i] == '\n'){
		title[i] = '\0';
		}
	}
	printf("%s\n", title);
	
	getline(&buffer, &buffer_size, fp);
	*row = atoi(buffer);
	getline(&buffer, &buffer_size, fp);
	*col = atoi(buffer);
	
	printf("%d\n",*row);
	printf("%d\n",*col);

	
	
	for (int i = 0; i < *row;i++)
			{
				getline(&buffer, &buffer_size, fp);
				for (int j = 0; j < *col;j++)
				{
				array[i][j] = buffer[j];
				}
			}
	
	for (int i =0; i < *row;i++)
			{
				for (int j =0; j < *col;j++)
				{
				printf("%c",array[i][j]);
				}
				printf("\n");
			}
    fflush(stdout);

    fclose(fp);
    //free(buffer);
	
	return array;

}
