#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

/**
 * Maze Game #1
 * C
 * @author: Matthew Yu
 * @version 1.1
 * @version 1.2 2/27/18 - bugfix for when direction priority makes algorithm double back on itself coming out of a dead
 *  end, which warps pointer to some spot, added delay funct
 * @version 1.3 3/1/18 - implementation of runComputerGamePythagorean algorithm that solves the maze by prioritizing
 *  directions in terms of smallest hypotenuse by making a triangle between a tile and the end tile, added findHypotenuse funct
 *
 * This program generates a maze within a 'box' of tiles. The starting point of the maze
 * is the top left tile, and the end point of the maze in the bottom right tile.
 * An Actor is created in the start tile and must find its way to the end tile.
 * The walls of the maze are other tiles.
 * The Actor can be a either a player who controls the movement of the Actor, or a
 * computer Actor that uses some algorithm to reach the end tile.
 * TODO: add functionality for user, add user flexibility to adjust maze size, select which algorithm to run or play by self
 */
#define ROWS 45
#define COLS 45

char maze[ROWS][COLS];
int liveCellX, liveCellY;

void delay(double numberOfSeconds);
double findHypotenuse(int cellR,int cellC);
void generateMaze();
int mazeProgression(int currCellR, int currCellC);
int runComputerGameSimple(int currentCellR, int currentCellC);
int runComputerGamePythagorean(int currentCellR, int currentCellC);
int playGame(char direction);
int main()
{
    char buff[10] = {'\0'};
    char tile;
    time_t start;
    time_t stop;

    srand((unsigned int) time(0));
    printf("Hello, World!\n");

    /**
    printf("Select a mode: (1)Computer plays\t(2)Player plays\t");
    do{
        scanf("%s", &buff);
        if(buff[0] != '1' && buff[0] != '2')
            printf("Invalid input.\n");
    }while(buff[0] != '1' && buff[0] != '2');
    **/

    //build Maze constraints
    generateMaze();
    //build Maze
    mazeProgression(1, 1);
    maze[1][1] = 'S';
    maze[ROWS - 2][COLS -2] = 'E';

    //display maze START
    for(int row = 0; row < ROWS; row ++)
    {
        for(int col = 0; col < COLS; col++)
        {
            tile = maze[row][col];
            printf("%s ", &tile);
        }
        printf("\n");
    }
    printf("\n\n");

    //set start position on 'S'
    liveCellX = 1;
    liveCellY = 1;

    //start timer
    time(&start);

    //game end if endTile = 1 (ENDTILE IS TRUE)
    int endTile = 0;
    while (!endTile) {
        //make move
        //endTile = runComputerGameSimple(liveCellY, liveCellX);
        endTile = runComputerGamePythagorean(liveCellY, liveCellX);
        //display maze
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                tile = maze[row][col];
                printf("%s ", &tile);
            }
            printf("\n");
        }
        //delay(.2);

        //printf("\n\n");
        if (tile != 'E')
            system("cls");
    }
    time(&stop);

    //end output
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            tile = maze[row][col];
            printf("%s ", &tile);
        }
        printf("\n");
    }
    printf("Time elapsed: %f\n", difftime(stop, start));


    buff[0] = '\0';
    while(fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if(strcmp(buff, "exit\n") == 0)
            exit(0);
    }
}

/**
 * generateMaze fills in the maze 2d array with a template: walls around each cell and bounds.
 */
void generateMaze()
{
    //set all tiles on maze to 0
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            maze[i][j] = 'O';

    //build maze constraints
    //set top left tile to start, bottom right tile to end
    for(int xBounds = 0; xBounds < COLS; xBounds++)
    {
        maze[0][xBounds] = '#';
        maze[ROWS-1][xBounds] = '#';
    }
    for(int yBounds = 0; yBounds < ROWS; yBounds++)
    {
        maze[yBounds][0] = '#';
        maze[yBounds][COLS - 1] = '#';
    }
    //build walls between each working cell
    for(int k = 1; k < ROWS-1; k += 2)
        for(int xWalls = 2; xWalls < COLS-1; xWalls += 2)
            maze[xWalls][k] = '#';
    for(int l = 1; l < COLS-1; l += 2)
        for(int yWalls = 2; yWalls < ROWS-1; yWalls += 2)
            maze[l][yWalls] = '#';
    for(int m = 2; m < ROWS - 2; m += 2)
        for(int junction = 2; junction < COLS - 2; junction += 2)
            maze[m][junction] = '#';

    //maze[1][1] = 'S';
    //maze[ROWS-1][COLS-1] = 2;

}

/**
 * mazeProgression generates a maze from the base template using depth recursion.
 * given a cell placement on the array maze[ROWS][COLS]
 * pick a random direction
 * check if next cell in said direction is free
 * if so, mark cell as path and run mazeProgression again with the next cell's coordinates
 * else, run mazeProgression again with the current cell's coordinates (how to optimize?)
 * continue running this algorithm until no direction is free.
 * when no direction is free, return to the previous iteration.
 * @param currCellR row number of cell position
 * @param currCellC column number of cell position
 * @return int endTile //remove when solve function is generated?
 */
int mazeProgression(int currCellR, int currCellC)
{

    int cellR, cellC;
    int northB = 0, eastB = 0, southB = 0, westB = 0;
    //0 - north, 1 - east, 2 - south, 3 - west
    int direction;

    while(northB == 0 || eastB == 0 || southB == 0 || westB == 0)
    {
        direction = rand()%4;
        if(direction == 0) //north
        {
            cellR = -2;
            cellC = 0;
            northB = 1;
        }
        else if(direction == 1) //east
        {
            cellR = 0;
            cellC = 2;
            eastB = 1;
        }
        else if(direction == 2) //south
        {
            cellR = 2;
            cellC = 0;
            southB = 1;
        }
        else //west
        {
            cellR = 0;
            cellC = -2;
            westB = 1;
        }
        if(maze[currCellR + cellR][currCellC + cellC] == 'O')
        {
            maze[currCellR][currCellC] = ' ';
            maze[currCellR + cellR/2][currCellC + cellC/2] = ' ';
            mazeProgression(currCellR + cellR, currCellC + cellC);
        }

    }
    maze[currCellR][currCellC] = ' ';
    return 0;
}


/**
 * runComputerGameSimple hands control to the computer who finds a path from tile 'S' to tile 'E' within the generated maze.
 * the Simple tag indicates that the algorithm used to traverse the maze is very rudimentary (not a depth search, recursive, etc)
 * @param currentCellR
 * @param currentCellC
 * @return int endTile 0 if current cell is not 'E', 1 if current cell is 'E'
 */
int runComputerGameSimple(int currentCellR, int currentCellC)
{
    int dN = 0, dE = 0, dS = 0, dW = 0, intersectionCtr = 0, deadEndCtr = 0; //2 is usable, 1 is usable (priority), 0 is unusable
    char mark = maze[currentCellR][currentCellC];
    //check current cell if End: if it is, exit method and return 0.
    if(maze[currentCellR][currentCellC] == 'E')
        return 1;
    //check status of current cell and adjust status/mark
    if(maze[currentCellR][currentCellC] == ' ')
        mark = '.';
    if(maze[currentCellR][currentCellC] == '.')
        mark = '-';

    //revise current cell mark if intersection
    if(maze[currentCellR - 1][currentCellC] != '#')
        intersectionCtr ++;
    if(maze[currentCellR + 1][currentCellC] != '#')
        intersectionCtr ++;
    if(maze[currentCellR][currentCellC - 1] != '#')
        intersectionCtr ++;
    if(maze[currentCellR][currentCellC + 1] != '#')
        intersectionCtr ++;
    if(intersectionCtr >= 3)
        mark = '.';

    //set for next move
    maze[currentCellR][currentCellC] = mark;

    //check directions
    if(maze[currentCellR - 1][currentCellC] == ' ' || maze[currentCellR - 1][currentCellC] == 'E')
        dN = 1;
    if(maze[currentCellR - 1][currentCellC] == '.')
        dN = 2;
    if(maze[currentCellR][currentCellC + 1] == ' ' || maze[currentCellR][currentCellC + 1] == 'E')
        dE = 1;
    if(maze[currentCellR][currentCellC + 1] == '.')
        dE = 2;
    if(maze[currentCellR + 1][currentCellC] == ' ' || maze[currentCellR + 1][currentCellC] == 'E')
        dS = 1;
    if(maze[currentCellR + 1][currentCellC] == '.')
        dS = 2;
    if(maze[currentCellR][currentCellC - 1] == ' ' || maze[currentCellR][currentCellC - 1] == 'E')
        dW = 1;
    if(maze[currentCellR][currentCellC - 1] == '.')
        dW = 2;

    //debug: if dead end, make inaccessible current tile
    if(dN == 0)
        deadEndCtr ++;
    if(dE == 0)
        deadEndCtr ++;
    if(dS == 0)
        deadEndCtr ++;
    if(dW == 0)
        deadEndCtr ++;
    if(deadEndCtr > 2)
    {
        if(deadEndCtr == 4)
        {
            printf("No way out. Fatal error.\n");
            printf("Cell location north:%c, east:%c, south:%c, west:%c, center:%c, center pos: %i, %i\n", maze[currentCellR][currentCellC + 1], maze[currentCellR + 1][currentCellC], maze[currentCellR - 1][currentCellC], maze[currentCellR][currentCellC - 1], maze[currentCellR][currentCellC], currentCellR, currentCellC);
        }
        else
            maze[currentCellR][currentCellC] = '-';
    }

    //high priority
    if(dN == 1) {
        liveCellY -= 1;
    } else if(dE == 1) {
        liveCellX += 1;
    } else if(dS == 1) {
        liveCellY += 1;
    } else if(dW == 1) {
        liveCellX -= 1;
    } else if(dN == 2) {     //low priority
        liveCellY -= 1;
    } else if(dE == 2) {
        liveCellX += 1;
    } else if(dS == 2) {
        liveCellY += 1;
    } else if(dW == 2) {
        liveCellX -= 1;
    } else {
        //maze[currentCellR][currentCellC] = 'F';
        printf("Fatal error\n");
        printf("Directions filled North:%i, East:%i, South:%i, West:%i\n", dN, dE, dW, dS);
        printf(" %c \n%c%c%c\n %c\n", maze[currentCellR - 1][currentCellC], maze[currentCellR][currentCellC - 1], maze[currentCellR][currentCellC], maze[currentCellR + 1][currentCellC], maze[currentCellR][currentCellC + 1]);
        exit(0);
    }

    return 0;
    //Tremaux's algorithm
    //check direction of walls and paths
    //check if junction or corridor (3/4 directions without walls vs only 2)
    //if corridor - move in direction with least marks
    //if junction - move in direction with least marks, do not move in direction marked with '-'.
    //definition of free: if there is no wall AND the path has not been marked with a '-'.
    //priority of directions: if north is free, go north. if north is not free, go east. if north and east are not free, go west. and so on. there must always be one direction open.
    //priority of marking: give cells priority if direction is ' ' compared to '.'.
        //mark current spot as used '.'. set liveCellX and liveCellY to new coordinates.
}

/**
 * runComputerGamePythagorean hands control to the computer who finds a path from tile 'S' to tile 'E' within the generated maze.
 * the LeastSquares tag indicates that the algorithm prioritizes directions based on the next possible tile's distance to the end point.
 * @param currentCellR
 * @param currentCellC
 * @return int endTile 0 if current cell is not 'E', 1 if current cell is 'E'
 */
int runComputerGamePythagorean(int currentCellR, int currentCellC) {
    int intersectionCtr = 0, deadEndCtr = 0;
    char mark = maze[currentCellR][currentCellC];
    double dirPriority[4][3] = {{0, 0, 0}, {0, 1, 0}, {0, 2, 0}, {0, 3, 0}}, temp[2] = {0, 0}; //hypotenuse length, direction, priority//N0:E1:S2:W3 //2 is usable, 1 is usable (priority), 0 is unusable

    //check current cell if End: if it is, exit method and return 0.
    if (maze[currentCellR][currentCellC] == 'E')
        return 1;
    //check status of current cell and adjust status/mark
    if (maze[currentCellR][currentCellC] == ' ')
        mark = '.';
    if (maze[currentCellR][currentCellC] == '.')
        mark = '-';
    //revise current cell mark if intersection
    if (maze[currentCellR - 1][currentCellC] != '#')
        intersectionCtr++;
    if (maze[currentCellR + 1][currentCellC] != '#')
        intersectionCtr++;
    if (maze[currentCellR][currentCellC - 1] != '#')
        intersectionCtr++;
    if (maze[currentCellR][currentCellC + 1] != '#')
        intersectionCtr++;
    if (intersectionCtr >= 3)
        mark = '.';
    //set for next move
    maze[currentCellR][currentCellC] = mark;

    //determine direction priority
    //assume End tile is always (maze[ROWS - 2][COLS -2])
    dirPriority[0][0] = findHypotenuse(currentCellR - 1, currentCellC);
    dirPriority[1][0] = findHypotenuse(currentCellR, currentCellC + 1);
    dirPriority[2][0] = findHypotenuse(currentCellR + 1, currentCellC);
    dirPriority[3][0] = findHypotenuse(currentCellR, currentCellC - 1);

    //manipulate dirPriority in terms of smallest hypotenuse to largest
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(dirPriority[j][0] > dirPriority[j + 1][0])
            {
                temp[0] = dirPriority[j][0];
                temp[1] = dirPriority[j][1];
                dirPriority[j][0] = dirPriority[j + 1][0];
                dirPriority[j][1] = dirPriority[j + 1][1];
                dirPriority[j + 1][0] = temp[0];
                dirPriority[j + 1][1] = temp[1];
            }
        }
    }

    //check directions
    for(int i = 0; i < 4; i++)
    {
        if(dirPriority[i][1] == 0) {
            if(maze[currentCellR - 1][currentCellC] == ' ' || maze[currentCellR - 1][currentCellC] == 'E')
                dirPriority[i][2] = 1;
            if(maze[currentCellR - 1][currentCellC] == '.')
                dirPriority[i][2] = 2;
        } else if(dirPriority[i][1] == 1) {
            if(maze[currentCellR][currentCellC + 1] == ' ' || maze[currentCellR][currentCellC + 1] == 'E')
                dirPriority[i][2] = 1;
            if(maze[currentCellR][currentCellC + 1] == '.')
                dirPriority[i][2] = 2;
        } else if(dirPriority[i][1] == 2) {
            if(maze[currentCellR + 1][currentCellC] == ' ' || maze[currentCellR + 1][currentCellC] == 'E')
                dirPriority[i][2] = 1;
            if(maze[currentCellR + 1][currentCellC] == '.')
                dirPriority[i][2] = 2;
        } else if(dirPriority[i][1] == 3) {
            if(maze[currentCellR][currentCellC - 1] == ' ' || maze[currentCellR][currentCellC - 1] == 'E')
                dirPriority[i][2] = 1;
            if(maze[currentCellR][currentCellC - 1] == '.')
                dirPriority[i][2] = 2;
        } else {
            printf("Direction priority is not 0-3. Fatal error.\n");
            exit(1);
        }
    }
    //debug: if dead end, make inaccessible current tile
    if(dirPriority[0][2] == 0)
        deadEndCtr ++;
    if(dirPriority[1][2] == 0)
        deadEndCtr ++;
    if(dirPriority[2][2] == 0)
        deadEndCtr ++;
    if(dirPriority[3][2] == 0)
        deadEndCtr ++;
    if(deadEndCtr > 2)
    {
        if(deadEndCtr == 4)
        {
            printf("No way out. Fatal error.\n");
            printf("Cell location north:%c, east:%c, south:%c, west:%c, center:%c, center pos: %i, %i\n", maze[currentCellR][currentCellC + 1], maze[currentCellR + 1][currentCellC], maze[currentCellR - 1][currentCellC], maze[currentCellR][currentCellC - 1], maze[currentCellR][currentCellC], currentCellR, currentCellC);
        }
        else
            maze[currentCellR][currentCellC] = '-';
    }


    //high priority
    for(int i = 0; i < 4; i++)
    {
        //checking in order of lowest hypotenuse length
        if (dirPriority[i][2] == 1)
        {
            //checking which direction has priority
            if (dirPriority[i][1] == 0) {
                liveCellY -= 1;
                return 0;
            } else if (dirPriority[i][1] == 1) {
                liveCellX += 1;
                return 0;
            } else if (dirPriority[i][1] == 2) {
                liveCellY += 1;
                return 0;
            } else if (dirPriority[i][1] == 3) {
                liveCellX -= 1;
                return 0;
            } else {
                maze[currentCellR][currentCellC] = 'F';
                printf("Fatal error\n");
                printf("Array result: %f/%f/%f:%f/%f/%f:%f/%f/%f:%f/%f/%f\n", dirPriority[0][0], dirPriority[0][1], dirPriority[0][2], dirPriority[1][0], dirPriority[1][1], dirPriority[1][2], dirPriority[2][0], dirPriority[2][1], dirPriority[2][2], dirPriority[3][0], dirPriority[3][1], dirPriority[3][2]);
                printf(" %c \n%c%c%c\n %c\n", maze[currentCellR - 1][currentCellC], maze[currentCellR][currentCellC - 1], maze[currentCellR][currentCellC], maze[currentCellR + 1][currentCellC], maze[currentCellR][currentCellC + 1]);
                exit(0);
            }
        }
    }
    //low priority
    for(int i = 0; i < 4; i++)
    {
        if (dirPriority[i][2] == 2)
        {
            //checking which direction has priority
            if (dirPriority[i][1] == 0) {
                liveCellY -= 1;
                return 0;
            } else if (dirPriority[i][1] == 1) {
                liveCellX += 1;
                return 0;
            } else if (dirPriority[i][1] == 2) {
                liveCellY += 1;
                return 0;
            } else if (dirPriority[i][1] == 3) {
                liveCellX -= 1;
                return 0;
            } else {
                maze[currentCellR][currentCellC] = 'F';
                printf("Fatal error\n");
                printf("Array result: %f/%f/%f:%f/%f/%f:%f/%f/%f:%f/%f/%f\n", dirPriority[0][0], dirPriority[0][1], dirPriority[0][2], dirPriority[1][0], dirPriority[1][1], dirPriority[1][2], dirPriority[2][0], dirPriority[2][1], dirPriority[2][2], dirPriority[3][0], dirPriority[3][1], dirPriority[3][2]);
                printf(" %c \n%c%c%c\n %c\n", maze[currentCellR - 1][currentCellC], maze[currentCellR][currentCellC - 1], maze[currentCellR][currentCellC], maze[currentCellR + 1][currentCellC], maze[currentCellR][currentCellC + 1]);
                exit(0);
            }
        }
    }
}

/**
 * delay delays the program for a number of seconds.
 * @param double numberOfSeconds
 */
void delay(double numberOfSeconds)
{
    double milliSeconds = 1000 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}

/**
 * playGame takes a direction input from the user and attempts to move in that direction. If it can't, it doesn't move and if it can, it moves.
 * @param direction (a = left, s = down, d = right, w = up)
 * @return boolean value if valid move (0 invalid, 1 valid
 */
int playGame(char direction)
{
    //check direction
    if(direction == 'a')
    {
        if(maze[liveCellX - 1][liveCellY] == '#')
            return 0;
        else
        {
            maze[liveCellX][liveCellY] = '.';
            liveCellX -= 1;
            return 1;
        }
    }
    else if(direction == 'd')
    {
        if(maze[liveCellX + 1][liveCellY] == '#')
            return 0;
        else
        {
            maze[liveCellX][liveCellY] = '.';
            liveCellX += 1;
            return 1;
        }
    }
    else if(direction == 'n')
    {
        if(maze[liveCellX][liveCellY - 1] == '#')
            return 0;
        else
        {
            maze[liveCellX][liveCellY] = '.';
            liveCellY -= 1;
            return 1;
        }
    }
    else if(direction == 's')
    {
        if(maze[liveCellX][liveCellY + 1] == '#')
            return 0;
        else
        {
            maze[liveCellX][liveCellY] = '.';
            liveCellY += 1;
            return 1;
        }
    }
    else
    {
        printf("Invalid input\n");
        return 0;
    }
}

/**
 * findHypotenuse takes the indicated tile in some direction from the current tile and checks its hypotenuse length to the end tile
 * assume End tile is always: maze[ROWS - 2][COLS -2] = 'E';
 * @param cellR tile coordinate Y
 * @param cellC tile coordinate X
 * @return double length of the hypotenuse
 */
double findHypotenuse(int cellR,int cellC)
{
    int xDist = 0, yDist = 0;
    xDist = COLS - 2 - cellC;
    yDist = ROWS - 2 - cellR;
    return sqrt(xDist*xDist + yDist*yDist);
}