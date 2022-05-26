#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//Maze settings:
#define SIZE 40
#define FRAME_DELAY 20
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 38
#define FINISH_Y 38

#define BLOCK 999998
#define WALL 999999
#define CHARACTER 999997

bool success = true;
int runs = 0;
int succeededRuns = 0;
int failedRuns = 0;





int maze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL},
    {WALL,WALL,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL, 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 , 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL,WALL, 48 , 48 , 48 ,WALL, 48 , 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL, 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL},
    {WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL,WALL, 48 , 48 , 48 , 48 , 48 ,WALL,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL},
    {WALL, 48 ,WALL, 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 , 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL},
    {WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 , 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL},
    {WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL,WALL, 48 , 48 , 48 ,WALL, 48 , 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL},
    {WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 ,WALL, 48 ,WALL,WALL, 48 ,WALL,WALL,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL},
    {WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL, 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL},
    {WALL, 48 , 48 , 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL,WALL,WALL,WALL,WALL,WALL, 48 , 48 , 48 , 48 ,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL,WALL,WALL, 48 ,WALL,WALL,WALL, 48 , 48 , 48 ,WALL, 48 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
};


int blankMaze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL},
    {WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL},
    {WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL},
    {WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,  0 ,  0 ,  0 ,WALL,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
};

/*
int maze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL, 0 , 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL,WALL, 0 , 0 , 0 ,WALL, 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}

};


int blankMaze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL, 0 , 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL,WALL, 0 , 0 , 0 ,WALL, 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 , 0 , 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL, 0 ,WALL,WALL, 0 ,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL, 0 ,WALL,WALL,WALL, 0 ,WALL,WALL, 0 ,WALL, 0 ,WALL, 0 , 0 , 0 , 0 ,WALL,WALL,WALL,WALL},
    {WALL, 0 , 0 , 0 , 0 , 0 , 0 ,WALL, 0 , 0 , 0 ,WALL,WALL,WALL,WALL, 0 , 0 , 0 , 0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}

};*/

int mappedMaze[SIZE][SIZE];





enum directions
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};



struct Position
{
    int x = 1;
    int y = 1;

} pos, prevPos;



bool done = false;

int numberOfLoops = 0;


int breakPoints[50][2];
int decision = 0;
int direction;

void printMaze();
void printBlankMaze();
int check();
int numberOfChoices();
bool checkHere( int where );
void moveto( int where );
int whatsThere( int where );
int whatsThere1( int where );
int inverse( int inputDirection );
void follow( int where );
int followTrace( int currentDirection );
void plotMaze(void);



void printMaze()
{
    int holder = mappedMaze[pos.y][pos.x];
    mappedMaze[pos.y][pos.x] = CHARACTER;
    blankMaze[pos.y][pos.x] = CHARACTER;

    system("cls");
    for (int i=0; i<SIZE; i++)
    {



        for (int j=0; j<SIZE; j++)
        {
            if ( mappedMaze[i][j] == WALL || mappedMaze[i][j] == BLOCK || mappedMaze[i][j] == CHARACTER )
            {
                printf(" %c ", mappedMaze[i][j]);
                continue;
            }
            else if ( mappedMaze[i][j] > 9 )
            {
                printf(" %d", mappedMaze[i][j]);
            }
            else
            {
                printf(" %d ", mappedMaze[i][j]);
            }
        }

        printf(" | ");

        for (int j=0; j<SIZE; j++)
        {
            printf(" %c", blankMaze[i][j]);
        }




        printf("\n");
    }

    //For debugging:
    printf("\ndirection:%d   decisions:%d   pos:(%d,%d)   last breakpoint:(%d,%d)   Loops:%d\n", direction, decision, pos.x, pos.y, breakPoints[decision][0], breakPoints[decision][1], numberOfLoops);

    Sleep(FRAME_DELAY);
    mappedMaze[pos.y][pos.x] = holder;
    blankMaze[pos.y][pos.x] = NULL;
}


void printBlankMaze()
{
    int holder = blankMaze[pos.y][pos.x];
    blankMaze[pos.y][pos.x] = CHARACTER;

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf(" %c", blankMaze[i][j]);
        }
        printf("\n");
    }

    Sleep(FRAME_DELAY);
    blankMaze[pos.y][pos.x] = holder;
}



int check()
{
    int x = pos.x;
    int y = pos.y;

    int up = (int)mappedMaze[y-1][x];
    int down = (int)mappedMaze[y+1][x];
    int right = (int)mappedMaze[y][x+1];
    int left = (int)mappedMaze[y][x-1];

    srand ( time(NULL) );

    while ( 1 )
    {
        switch ( rand()%4 )
        {
            case UP:
                if ( up<=down && up<=right && up<=left )
                {
                    return UP;
                }
            break;

            case DOWN:
                if ( left<=up && left<=down && left<=right )
                {
                    return LEFT;
                }
            break;

            case RIGHT:
                if ( right<=up && right<=down && right<=left )
                {
                    return RIGHT;
                }
            break;

            case LEFT:
                if ( down<=up && down<=right && down<=left )
                {
                    return DOWN;
                }
            break;
        }
    }
}


int numberOfChoices()
{
    int x = pos.x;
    int y = pos.y;

    int choices = 0;

    if ( mappedMaze[y-1][x] != WALL && mappedMaze[y-1][x] != BLOCK )  //UP
    {
        choices++;
    }
    if ( mappedMaze[y+1][x] != WALL && mappedMaze[y+1][x] != BLOCK )  //DOWN
    {
        choices++;
    }
    if ( mappedMaze[y][x+1] != WALL && mappedMaze[y][x+1] != BLOCK )  //RIGHT
    {
        choices++;
    }
    if ( mappedMaze[y][x-1] != WALL && mappedMaze[y][x-1] != BLOCK )  //LEFT
    {
        choices++;
    }

    return choices;
}


bool checkHere ( int where )
{
    int x = pos.x;
    int y = pos.y;

    switch ( where )
    {
        case UP:
            if ( mappedMaze[y-1][x] != WALL && mappedMaze[y-1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case DOWN:
            if ( mappedMaze[y+1][x] != WALL && mappedMaze[y+1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case RIGHT:
            if ( mappedMaze[y][x+1] != WALL && mappedMaze[y][x+1] != BLOCK ) { return true; }
            else { return false; }
            break;
        case LEFT:
            if ( mappedMaze[y][x-1] != WALL && mappedMaze[y][x-1] != BLOCK ) { return true; }
            else { return false; }
            break;

        default:
            printf("\nIn function: checkHere(int where) FATAL ERROR!");
            //exit(-1);
            success = false;
            break;
    }
}



void moveto( int where )
{
    if ( whatsThere1(where) == WALL || whatsThere1(where) == 'X' )
    {
        printf("\nA problem occurred.\n");
        success = false;
        //exit(-1);
    }
    prevPos = pos;

    (int)mappedMaze[pos.y][pos.x]++;

    switch ( where )
    {
        case UP:
            pos.y--;
            break;

        case DOWN:
            pos.y++;
            break;

        case RIGHT:
            pos.x++;
            break;

        case LEFT:
            pos.x--;
            break;

        default:
            printf("\nIn function: moveto(int where)  FATAL ERROR!\n");
            //exit(-1);
            success = false;
    }

    plotMaze();

    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        mappedMaze[pos.y][pos.x] = '1';
        done = true;
    }
}



int inverse( int inputDirection )
{
    int returnDirection;
    switch ( inputDirection )
    {
    case UP:
        returnDirection = DOWN;
        break;
    case DOWN:
        returnDirection = UP;
        break;
    case RIGHT:
        returnDirection = LEFT;
        break;
    case LEFT:
        returnDirection = RIGHT;
        break;
    }

    return returnDirection;
}




int whatsThere( int where )
{
    struct Position temp;
    temp = pos;

    switch ( where )
    {
        case UP:
            temp.y--;
            break;

        case DOWN:
            temp.y++;
            break;

        case RIGHT:
            temp.x++;
            break;

        case LEFT:
            temp.x--;
            break;

        default:
            printf("\nIn function: moveto(int where)  FATAL ERROR!\n");
            //exit(-1);
            success = false;
    }

    return (int)maze[temp.y][temp.x];
}



int whatsThere1( int where )
{
    struct Position temp;
    temp = pos;

    switch ( where )
    {
        case UP:
            temp.y--;
            break;

        case DOWN:
            temp.y++;
            break;

        case RIGHT:
            temp.x++;
            break;

        case LEFT:
            temp.x--;
            break;

        default:
            printf("\nIn function: whatsThere(int where)  FATAL ERROR!\n");
            //exit(-1);
            success = false;
    }

    return (int)mappedMaze[temp.y][temp.x];
}




void follow( int where )
{
    switch ( where )
    {
        case UP:
            //blankMaze[pos.y][pos.x] = '|';
            pos.y--;
            break;

        case DOWN:
            //blankMaze[pos.y][pos.x] = '|';
            pos.y++;
            break;

        case RIGHT:
            //blankMaze[pos.y][pos.x] = 196;
            pos.x++;
            break;

        case LEFT:
            //blankMaze[pos.y][pos.x] = 196;
            pos.x--;
            break;

        default:
            printf("\nIn function: follow(int where)  FATAL ERROR!\n");
            //exit(-1);
            success = false;
    }
    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        done = true;
    }
}



int followTrace( int currentDirection )
{
    int x = pos.x;
    int y = pos.y;


    int up = (int)mappedMaze[y-1][x] != WALL ? (int)mappedMaze[y-1][x] :0;

    int down = (int)mappedMaze[y+1][x] != WALL ? (int)mappedMaze[y+1][x] :0;

    int right = (int)mappedMaze[y][x+1] != WALL ? (int)mappedMaze[y][x+1] :0;

    int left = (int)mappedMaze[y][x-1] != WALL ? (int)mappedMaze[y][x-1] :0;

    bool allChecked = false;


    while ( 1 )
    {

        if ( ( up!=0 && up!=BLOCK ) && ( currentDirection!=DOWN || allChecked ) )
        {
            return UP;
        }
        if ( ( down!=0 && down!=BLOCK ) && ( currentDirection!=UP || allChecked ) )
        {
            return DOWN;
        }
        if ( ( right!=0 && right!=BLOCK ) && ( currentDirection!=LEFT || allChecked ) )
        {
            return RIGHT;
        }
        if ( ( left!=0 && left!=BLOCK ) && ( currentDirection!=RIGHT || allChecked ) )
        {
            return LEFT;
        }

        allChecked = true;

    }
}



int findReverseDirection ( struct Position firstPos, struct Position secPos )
{
    if ( secPos.y == firstPos.y - 1 )
    {
        return DOWN;
    }

    if ( secPos.y == firstPos.y + 1 )
    {
        return UP;
    }

    if ( secPos.x == firstPos.x + 1 )
    {
        return LEFT;
    }

    if ( secPos.x == firstPos.x - 1 )
    {
        return RIGHT;
    }

    printf("\nIn function: findDirection  FATAL ERROR!\n");
    //exit(-1);
    success = false;
}



void plotMaze()
{
    if ( whatsThere(UP) == WALL || whatsThere(UP) == BLOCK ) { mappedMaze[pos.y-1][pos.x] = WALL; }

    if ( whatsThere(DOWN) == WALL || whatsThere(DOWN) == BLOCK ) { mappedMaze[pos.y+1][pos.x] = WALL; }

    if ( whatsThere(RIGHT) == WALL || whatsThere(RIGHT) == BLOCK ) { mappedMaze[pos.y][pos.x+1] = WALL; }

    if ( whatsThere(LEFT) == WALL || whatsThere(LEFT) == BLOCK ) { mappedMaze[pos.y][pos.x-1] = WALL; }
}





void penmark ( int IncrDecr )
{
    if ( IncrDecr == '+' )
    {
        for ( int i=0; i<SIZE; i++ )
        {
            for ( int j=0; j<SIZE; j++ )
            {
                if ( mappedMaze[i][j]!=0 && mappedMaze[i][j]!=WALL && mappedMaze[i][j]!=BLOCK && mappedMaze[i][j]!=CHARACTER )
                {
                    mappedMaze[i][j] = (int)mappedMaze[i][j] + 5;
                }
            }
        }
    }
    else if ( IncrDecr == '-' )
    {
        for ( int i=0; i<SIZE; i++ )
        {
            for ( int j=0; j<SIZE; j++ )
            {
                if ( mappedMaze[i][j]!=0 && mappedMaze[i][j]!=WALL && mappedMaze[i][j]!=BLOCK && mappedMaze[i][j]!=CHARACTER  )
                {
                    mappedMaze[i][j] = (int)mappedMaze[i][j] - 5;
                }
            }
        }
    }
}



void reset()
{
    int i,j;

    ///Reset maze
    for ( i=0; i<SIZE; i++ )
    {
        for ( j=0; j<SIZE; j++ )
        {
            mappedMaze[i][j] = 0;
        }
    }

    ///Reset breakpoints
    for ( i=0; i<50; i++ )
    {
        for ( j=0; j<2; j++ )
        {
            breakPoints[i][j] = 0;
        }
    }

    ///Reset positions
    pos.x = INIT_X;
    pos.y = INIT_Y;
    prevPos = pos;


    ///Reset control variables
    decision = 0;
    done = false;

}






int main()
{
    clock_t time;
    double timepp, timeav, timetot;

    while ( true )
    {
        reset();

        time = clock();


        /// STEP #1 : Solving the maze. ///

        breakPoints[0][0] = pos.x;
        breakPoints[0][1] = pos.y;

        direction = check();

        plotMaze();


        while ( !done && success )
        {
            while (  numberOfChoices() <= 2  && !done && success )
            {
                direction = check();
                moveto ( direction );
                //printMaze();
            }


            if ( numberOfChoices() > 2 )
            {
                decision++;

                breakPoints[decision][0] = pos.x;
                breakPoints[decision][1] = pos.y;

                penmark('+');

                direction = check();
            }


            while ( decision > 0 && !done && success )
            {

                /// Loop handling:

                if ( whatsThere1(direction) > 0 && whatsThere(direction)!=WALL && whatsThere1(direction)!=BLOCK && numberOfChoices() == 2 )
                {
                    numberOfLoops++;
                    //printf("\n Loop detected.  ");
                    //system("pause");

                    mappedMaze[pos.y][pos.x] = BLOCK-1;

                    direction = check();
                    moveto(direction);
                    //printMaze();

                    direction = check();
                }
                ///


                ///Dead-end handling:

                if ( numberOfChoices() == 1 )
                {
                    while ( !(pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1]) && numberOfChoices() <= 1 && success )
                    {
                        mappedMaze[pos.y][pos.x] = BLOCK -1;

                        direction = check();
                        moveto ( direction );

                        //printMaze();
                    }

                    if ( pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1] )
                    {
                        decision--;
                        //penmark('-');
                    }
                    direction = check();
                }
                else
                {
                    direction = check();
                }


                ///Moving if there is nothing to worry:

                direction = check();

                if ( whatsThere1(direction) == 0 )
                {

                    moveto(direction);
                    //printMaze();

                    if ( numberOfChoices() > 2 )
                    {
                        decision++;

                        breakPoints[decision][0] = pos.x;
                        breakPoints[decision][1] = pos.y;

                        penmark('+');

                        direction = check();
                    }
                }
            }
        }



        //printf("\nMapping is finished.");
        //system("pause");



        /// STEP #2 : Starting at the beginning again and following the correct path. ///

        done = false;

        pos.x = INIT_X;
        pos.y = INIT_Y;

        //printBlankMaze();
        //system("pause");

        while ( !done && success )
        {
            direction = followTrace( direction );
            follow ( direction );
            //printBlankMaze();

            if ( pos.x == FINISH_X && pos.y == FINISH_Y ) { done = true; }
        }

        //printf("\nMAZE COMPLETED!");

        if ( success )
        {
            runs++;
            succeededRuns++;
        }
        else
        {
            runs++;
            failedRuns++;
        }

        time = clock() - time;
        timepp = ((double)time)/CLOCKS_PER_SEC;

        timetot += timepp;
        timeav = timetot/runs;


        printf("Runs:%d   Succeeded runs:%d   Failed runs:%d   Time:%f   Average time(s)%f   Total time(m)%d\n", runs, succeededRuns, failedRuns, timepp, timeav, (int)(timetot/60));
        //system("pause");

        success = true;




    }


    return 0;
}



/*
    When it detects a loop, it supposed to mark it's current position, and return back. But it always(i guess) enters
    the loop handling part AFTER making a random decision, so when program inverses the direction, that direction
    is not necessarily the direction following which it came there, but rather a random one.

*/

























