#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define MAXCHAR 1000
#define MAXDIMCHAR 2

char* PrintMaze(int Rows, int Columns, char** maze)
{
    char** array1 = malloc(Rows * sizeof(char*)); // Allocate row pointers
    for (int i = 0; i < Rows; i++)
        array1[i] = malloc(Columns * sizeof(char));  // Allocate each row separately
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            //array1[i][j] = maze[i][j];
            printf("%c", maze[i][j]);
            //printf("%c",array1[i][j]);
        }
    }
}
// Initmaze - returns an empty maze so that we are ready to start the game
char** InitMaze(char* mazeFilename, int mazeNum)
{
    FILE* filePointer;
    char str[MAXCHAR];
    //char strNumOfColumns[MAXDIMCHAR];
    //char strNumOfRows[MAXDIMCHAR];
    int isCommaFound = 0, commaLocation = 0;


    filePointer = fopen(mazeFilename, "r");
    if (filePointer == NULL) {
        printf("Could not open file %s", mazeFilename);
    }

    fgets(str, MAXCHAR, filePointer);
    printf("%s", str);
    //save number of rows and columns using the first line 
    char* token = strtok(str, ",");
    int NumOfColumns = atoi(token);
    token = strtok(NULL, " ");
    int NumOfRows = atoi(token);


    // We declare and allocate a pointer for each of their rows
    char** maze = malloc(NumOfColumns * sizeof(char*));
    // For each row pointer, we allocate an pointer for the row {
    for (int i = 0; i < NumOfRows; i++)
    {
        maze[i] = malloc(NumOfColumns * sizeof(char));
    }


    // Now that we have our pointers allocated, we need to fill them with the values for the current maze
    for (int i = 0; i < NumOfRows; i++)
    {
        fgets(str, MAXCHAR, filePointer);
        strcpy(maze[i], str);
    }
    for (int i = 0; i < 7; i++)
    {
        printf("%s", maze[i]);
    }
    
    // Now we can start reading the maze
    PrintMaze(NumOfRows, NumOfColumns, maze);
}
