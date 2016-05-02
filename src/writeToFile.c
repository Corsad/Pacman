#include "writeToFile.h"
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>
//method used to write to file

void writeToFile(char* author, char* title, char* filename, int row, int col, char** array){
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
	
	if(!(fp = fopen(fullpath, "w"))){
		printf("Error writing file. Exit");
		endwin();
		exit(EXIT_SUCCESS);
	}

	fprintf(fp, "%s\n", author);
	fprintf(fp, "%s\n", title);
	fprintf(fp, "%d\n", row);
	fprintf(fp, "%d\n", col);
	for (int i =0; i < row;i++)
			{
				for (int j = 0; j < col;j++)
				{
				fprintf(fp,"%c",array[i][j]);
				}
				fprintf(fp,"\n");
			}

	fclose(fp);

}