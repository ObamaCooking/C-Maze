#include <stdio.h>
#include <malloc.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAXCHAR 1000
#define MAXDIMCHAR 2

// Initmaze - returns an empty maze so that we are ready to start the game
char** InitMaze(char* mazeFilename, int mazeNum)
{
    FILE* filePointer;
    char str[MAXCHAR];
    char strNumOfColumns[MAXDIMCHAR];
    char strNumOfRows[MAXDIMCHAR];
    int isCommaFound = 0, commaLocation = 0;


    filePointer = fopen(mazeFilename, "r");
    if (filePointer == NULL) {
        printf("Could not open file %s", mazeFilename);
    }

    fgets(str, MAXCHAR, filePointer);
    printf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ',')
        {
            if (isCommaFound == 0)
                strNumOfColumns[i] = str[i];

            else
                strNumOfRows[i - commaLocation - 1] = str[i];
        }
        else
        {
            isCommaFound = 1;
            commaLocation = i;
        }
    }
    
    // We declare and allocate a pointer for each of ther rows
    char** maze = malloc((int)strNumOfRows * sizeof(char*));
    // For each row pointer, we allocate an array for the row {
        for (int i = 0; i< (int)strNumOfColumns; i++)
    {
         maze[i] = malloc((int)strNumOfColumns * sizeof(char)); 
    }


    // Now that we have our pointers allocated, we need to fill them with the values for the current maze
    
    // In order to do so, we need to go to the second row


    // Now we can start reading the maze

    for (int l = 0; l< (int)strNumOfColumns; l++)
    {
        for (int x = 0; x < (int)strNumOfRows; x++)
        {
            maze = scanf(" %c", maze[l][x]);
        }
    }

    
}
