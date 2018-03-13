#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * Water Fill Sim #1
 * C
 * @author: Matthew Yu
 * @version 1.1 3/3/18
 * 1.2 3/13/18  updated algorithm for water flow, flows consistently in both directions (left/right). Bug: might possibly phase through walls if empty on other side.
 *
 * This program generates a premade box with arbitrarily placed walls. It them simulates an amount of water of some density,
 * represented as a square, that falls into the box.
 */
#define ROWS 25
#define COLUMNS 50

char box[ROWS][COLUMNS][2];
void dropWater();
void waterMove();
void makeBox();
void wait(double numberOfSeconds);
int main()
{
    srand((unsigned int) time(0));
    printf("Hello, World!\n");
    makeBox();
    int waterDrops = 0;
    while(waterDrops < ((ROWS - 3)*(COLUMNS - 3)))
    {
        int waterTime = 0;
        for(int i = 0; i < rand()%5; i++)
            dropWater();
        while(waterTime < 5)
        {
            waterMove();
            //display box
            system("cls");
            for(int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                    printf("%c", box[i][j][0]);
                printf("\n");
            }
            wait(.1);
            waterTime ++;
        }
        waterDrops ++;
    }
    return 0;
}

/**
 * makeBox creates a box in the array that the water is contained in.
 */
void makeBox()
{
    //empty array
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
            box[i][j][0] = ' ';
    }
    //build walls
    for(int i = 0; i < ROWS; i++)
    {
        box[i][0][0] = '|';
        box[i][COLUMNS - 1][0] = '|';
    }
    for(int j = 0; j < COLUMNS; j++)
    {
        box[0][j][0] = '-';
        box[ROWS - 1][j][0] = '-';
    }
    //build inner walls
    //TODO: randomly generate walls of random height in random positions at the bottom of the box
    int height;
    int xPos;
    int runs = rand()%15;
    for(int i = 0; i < runs; i++)
    {
        height = rand()%(ROWS*2/3);
        xPos = rand()%(COLUMNS-1) + 1;
        for(int j = 0; j <= height; j++)
        {
            box[ROWS - j - 1][xPos][0] = '|';
        }
    }
    /**
    for(int i = 0; i < 10; i ++)
    {
        box[ROWS - i][15] = '|';
        box[ROWS - i][30] = '|';
    }**/
}

/**
 * dropWater adds a drop of water in the box at a set position.
 */
void dropWater()
{
    int position = rand()%(COLUMNS-2)+1;
    box[1][position][0] = '#';
}

/**
 * waterMove checks the position of every drop of water in the box. If there is a position in which it can move (down), move it.
 */
void waterMove()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            if(box[i][j][0] == '#' && box[i][j][1] == 0)
            {
                if(box[i + 1][j][0] == ' ') //if directly below is clear
                {
                    box[i][j][0] = ' ';
                    box[i][j][1] = 0;
                    box[i + 1][j][0] = '#'; //move there
                    box[i + 1][j][1] = 1;
                }
                else if(box[i + 1][j - 1][0] == ' ') //if below and left is clear
                {
                    box[i][j][0] = ' ';
                    box[i][j][1] = 0;
                    box[i + 1][j - 1][0] = '#'; //move there
                    box[i + 1][j - 1][1] = 1;
                }
                else if(box[i + 1][j - 1][0] == '#' || box[i + 1][j - 1][0] == '|') //if below and left is blocked
                {
                    //check if below and right is clear
                    if(box[i + 1][j + 1][0] == ' ') //if below and right is clear
                    {
                        box[i][j][0] = ' ';
                        box[i][j][1] = 0;
                        box[i + 1][j + 1][0] = '#'; //move there
                        box[i + 1][j + 1][1] = 1;
                    }
                    else if(box[i + 1][j - 2][0] == ' ') //if below and two to left is clear
                    {
                        box[i][j][0] = ' ';
                        box[i][j][1] = 0;
                        box[i + 1][j - 2][0] = '#';
                        box[i + 1][j - 2][1] = 1;
                    }
                    else if(box[i + 1][j + 1][0] == '#' || box[i + 1][j + 1][0] == '|')
                        //if below and to the right is filled but two to the right below isn't
                    {
                        if(box[i + 1][j + 2][0] == ' ')
                        {
                            box[i][j][0] = ' ';
                            box[i][j][1] = 0;
                            box[i + 1][j + 2][0] = '#';
                            box[i + 1][j + 2][1] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            box[i][j][1] = 0;
        }
    }
}

/**
 * wait delays the program for a number of seconds.
 * @param double numberOfSeconds
 */
void wait(double numberOfSeconds)
{
    double milliSeconds = 1000 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}