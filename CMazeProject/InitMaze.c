#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define MAXCHAR 1000
#define MAXDIMCHAR 2

char* PrintMaze(int Rows, int Columns, char** maze)
{
    char** mazearr = malloc(Rows * sizeof(char*)); // Allocate row pointers
    for (int i = 0; i < Rows; i++)
        mazearr[i] = malloc(Columns * sizeof(char));  // Allocate each row separately
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            mazearr[i][j] = maze[i][j];
        }
        
    }
    //a test, you can delete after adding printmaze function 
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            printf("%c", mazearr[i][j]);
        }

    }
    //print maze function here :)
    //printmaze(mazearr,rows,columns)
}

char* openfile(char* mazeFileName)
{
    FILE* filePointer;

    filePointer = fopen(mazeFileName, "r");
    if (filePointer == NULL) {
        printf("Could not open file %s", mazeFileName);
    }
    return filePointer;
}
// Initmaze - returns an empty maze so that we are ready to start the game
char** InitMaze(char* mazeFilename, int mazeNum)
{
    //FILE* filePointer
    char str[MAXCHAR];
    FILE* filePointer = openfile(mazeFilename);
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
    // Every fgets has the next row. for example in the first time it will be the first row, in the second time it will be the second row, etc...
    // In the print function, get the next numbers using the same way we did earlier, and then use the same way to print it.
    for (int i = 0; i < NumOfRows; i++)
    {
        fgets(str, MAXCHAR, filePointer);
        strcpy(maze[i], str);
    }
    
    // Now we can start reading the maze
    PrintMaze(NumOfRows, NumOfColumns, maze);
}
