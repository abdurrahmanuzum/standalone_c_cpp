//17.10.2019//

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

//Maze settings:
#define SIZE 40
#define FRAME_DELAY 200
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 38
#define FINISH_Y 38

#define BLOCK 'X'



int maze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48, 48, 48, 48, 48, 48, 48,254, 48, 48, 48, 48, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254,254,254, 48,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48, 48, 48,254,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48, 48,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254,254,254},
    {254, 48,254, 48,254, 48,254,254,254,254,254, 48, 48, 48, 48, 48,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254,254},
    {254, 48,254,254,254, 48,254,254, 48,254,254, 48, 48, 48,254, 48,254, 48, 48,254, 48,254, 48,254,254,254,254,254,254,254,254,254,254,254, 48, 48, 48, 48, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254,254,254,254,254,254, 48,254, 48,254,254, 48,254, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254},
    {254, 48,254,254,254,254,254,254,254,254, 48, 48, 48, 48,254, 48,254, 48,254,254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254},
    {254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254, 48, 48, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48, 48, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48,254, 48, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48, 48, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254, 48,254,254, 48,254, 48, 48, 48, 48,254, 48,254,254,254, 48,254, 48,254, 48,254,254,254,254,254,254,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254, 48, 48, 48, 48,254, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48,254,254,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48,254, 48,254, 48,254, 48,254, 48, 48,254},
    {254, 48,254,254,254,254,254,254,254, 48,254,254, 48, 48, 48, 48, 48, 48,254,254,254,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254, 48,254,254, 48,254},
    {254, 48,254,254,254,254,254,254,254, 48,254,254,254,254,254,254,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48,254, 48,254,254,254, 48,254, 48, 48,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48,254,254, 48, 48, 48,254, 48,254,254,254,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254,254,254, 48,254,254,254,254,254,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254, 48, 48, 48, 48, 48, 48, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48, 48, 48,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254,254,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48, 48,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254,254, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254, 48,254,254,254, 48,254,254,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48, 48, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254,254, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254,254,254, 48,254, 48,254,254, 48,254,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254,254,254,254,254,254, 48,254, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254, 48, 48,254},
    {254, 48,254,254,254,254,254,254,254,254, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254, 48,254,254,254,254,254},
    {254, 48,254,254,254,254,254,254,254,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254, 48,254,254,254, 48,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48,254, 48, 48,254, 48, 48, 48,254, 48,254,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254, 48,254, 48,254},
    {254,254,254, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48, 48, 48,254, 48,254,254,254,254,254,254,254, 48,254, 48, 48, 48, 48,254,254, 48,254, 48,254},
    {254, 48,254, 48,254,254, 48, 48, 48,254, 48, 48,254, 48, 48, 48, 48,254, 48,254, 48,254, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254,254, 48,254, 48,254},
    {254, 48,254, 48, 48, 48,254,254, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254,254,254, 48,254,254, 48, 48, 48, 48, 48, 48,254, 48,254, 48,254},
    {254, 48,254, 48,254, 48,254,254,254,254, 48,254,254, 48,254, 48, 48, 48, 48,254, 48, 48, 48,254, 48,254, 48, 48, 48, 48,254,254, 48,254,254,254, 48,254,254,254},
    {254, 48,254, 48,254, 48, 48, 48, 48,254, 48,254,254, 48,254,254,254,254, 48,254, 48,254, 48,254, 48,254,254,254, 48,254, 48, 48, 48, 48, 48,254, 48, 48, 48,254},
    {254, 48,254,254,254, 48,254,254, 48,254, 48,254, 48, 48, 48, 48, 48, 48,254,254, 48,254, 48,254, 48,254, 48, 48, 48,254, 48,254, 48,254, 48,254,254,254, 48,254},
    {254, 48, 48, 48, 48, 48, 48,254, 48, 48, 48,254,254,254,254,254,254, 48, 48, 48, 48,254, 48, 48, 48,254, 48,254,254,254, 48,254,254,254, 48, 48, 48,254, 48,254},
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
};

int blankMaze [SIZE][SIZE] =
{
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 , 0 ,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254,254, 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254, 0 ,254,254,254,254,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 ,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254,254,254,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 , 0 ,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254, 0 ,254, 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254, 0 , 0 ,254},
    {254, 0 ,254,254,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254,254,254},
    {254, 0 ,254,254,254,254,254,254,254,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254, 0 ,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 , 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254, 0 ,254, 0 ,254},
    {254,254,254, 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 , 0 , 0 ,254, 0 ,254,254,254,254,254,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254,254, 0 , 0 , 0 ,254, 0 , 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254,254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 ,254, 0 ,254},
    {254, 0 ,254, 0 ,254, 0 ,254,254,254,254, 0 ,254,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254,254, 0 ,254,254,254, 0 ,254,254,254},
    {254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 ,254, 0 ,254,254, 0 ,254,254,254,254, 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254, 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254},
    {254, 0 ,254,254,254, 0 ,254,254, 0 ,254, 0 ,254, 0 , 0 , 0 , 0 , 0 , 0 ,254,254, 0 ,254, 0 ,254, 0 ,254, 0 , 0 , 0 ,254, 0 ,254, 0 ,254, 0 ,254,254,254, 0 ,254},
    {254, 0 , 0 , 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254,254,254,254,254,254, 0 , 0 , 0 , 0 ,254, 0 , 0 , 0 ,254, 0 ,254,254,254, 0 ,254,254,254, 0 , 0 , 0 ,254, 0 ,254},
    {254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254},
};



enum directions
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};


//Position struct to hold entity's position.
struct Position
{
    int x = 1;
    int y = 1;

} pos;


//Flag to check whether end of the maze is reached.
bool done = false;


//Just miserably prints the maze to console. Nothing fancy here.
void printMaze()
{
    int holder = maze[pos.y][pos.x];
    maze[pos.y][pos.x] = 'o';

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf(" %c", maze[i][j]);
        }
        printf("\n");
    }

    Sleep(FRAME_DELAY);
    maze[pos.y][pos.x] = holder;
}


void printBlankMaze()
{
    int holder = blankMaze[pos.y][pos.x];
    blankMaze[pos.y][pos.x] = 'o';

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



//Checks every direction and returns direction to square which has smallest value on it (if more than one, randomly returns one).
int check()
{
    int x = pos.x;
    int y = pos.y;

    int up = (int)maze[y-1][x];
    int down = (int)maze[y+1][x];
    int right = (int)maze[y][x+1];
    int left = (int)maze[y][x-1];

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


//Returns how many possible paths there are.
int numberOfChoices()
{
    int x = pos.x;
    int y = pos.y;

    int choices = 0;

    if ( maze[y-1][x] != 254 && maze[y-1][x] != BLOCK )  //UP
    {
        choices++;
    }
    if ( maze[y+1][x] != 254 && maze[y+1][x] != BLOCK )  //DOWN
    {
        choices++;
    }
    if ( maze[y][x+1] != 254 && maze[y][x+1] != BLOCK )  //RIGHT
    {
        choices++;
    }
    if ( maze[y][x-1] != 254 && maze[y][x-1] != BLOCK )  //LEFT
    {
        choices++;
    }

    return choices;
}


//Checks whether a specific path is available.
bool checkHere ( int where )
{
    int x = pos.x;
    int y = pos.y;

    switch ( where )
    {
        case UP:
            if ( maze[y-1][x] != 254 && maze[y-1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case DOWN:
            if ( maze[y+1][x] != 254 && maze[y+1][x] != BLOCK ) { return true; }
            else { return false; }
            break;

        case RIGHT:
            if ( maze[y][x+1] != 254 && maze[y][x+1] != BLOCK ) { return true; }
            else { return false; }
            break;
        case LEFT:
            if ( maze[y][x-1] != 254 && maze[y][x-1] != BLOCK ) { return true; }
            else { return false; }
            break;

        default:
            printf("\nIn function: checkHere(int where) FATAL ERROR!");
            exit(-1);
            break;
    }
}



//Moves the entity to a direction (not position).
void moveto( int where )
{
    (int)maze[pos.y][pos.x]++;

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
            printf("\nIn function: moveto(int where)  FATAL ERROR!");
            exit(-1);
    }
    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        maze[pos.y][pos.x] = '1';
        done = true;
    }
}

//Modified version of 'moveto' function, does not increment value of passed square.
void follow( int where )
{
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
            printf("\nIn function: follow(int where)  FATAL ERROR!");
            exit(-1);
    }
    if ( pos.x == FINISH_X && pos.y == FINISH_Y )
    {
        blankMaze[pos.y][pos.x] = '1';
        done = true;
    }
}



//Returns the direction to a square which has non-zero value. (Has built-in mechanism to prevent returning back to where it came.)
int followTrace( int currentDirection )
{
    int x = pos.x;
    int y = pos.y;

    //If <DIRECTION> doesn't point to walls of maze, value of square that it points is assigned to <direction> variable. Else, 48 will be assigned ( ASCII code for 0 ).

    int up = (int)maze[y-1][x] != 254 ? (int)maze[y-1][x] :48;

    int down = (int)maze[y+1][x] != 254 ? (int)maze[y+1][x] :48;

    int right = (int)maze[y][x+1] != 254 ? (int)maze[y][x+1] :48;

    int left = (int)maze[y][x-1] != 254 ? (int)maze[y][x-1] :48;

    bool allChecked = false;


    while ( 1 )
    {
        //If <direction> is available and won't cause entity to return where it was one step ago, return <DIRECTION>

        if ( ( up!=48 && up!=BLOCK ) && ( currentDirection!=DOWN || allChecked ) )
        {
            return UP;
        }
        if ( ( down!=48 && down!=BLOCK ) && ( currentDirection!=UP || allChecked ) )
        {
            return DOWN;
        }
        if ( ( right!=48 && right!=BLOCK ) && ( currentDirection!=LEFT || allChecked ) )
        {
            return RIGHT;
        }
        if ( ( left!=48 && left!=BLOCK ) && ( currentDirection!=RIGHT || allChecked ) )
        {
            return LEFT;
        }

        allChecked = true; //If program run through all possible ways yet function hasn't been terminated,
                           //that means entity has no other chance than returning back where it was one step ago.
                           //This logic variable allows it to do that if there is no other option.
                           //(That actually would mean that algorithm is broken, but still can be useful to have this ability to spot errors.)
    }
}






int main()
{
    /// STEP #1 : Solving the maze. ///

    //Setting the starting point.
    pos.x = INIT_X;
    pos.y = INIT_Y;

    int direction;
    int decision = 0;

    //This 2D array holds the coordinates where algorithm has to decide between possible paths to go if there is more than one.
    int breakPoints[50][2];

    breakPoints[0][0] = pos.x;
    breakPoints[0][1] = pos.y;

    direction = check();

    printMaze();
    system("pause");


    while ( !done )
    {
        //As long as there is no choices other than going forward or backward, entity keeps moving to wherever is available.
        while (  numberOfChoices() <= 2  && !done )
        {
            direction = check();
            moveto ( direction );
            printMaze();
        }

        //Saves the coordinates if a decision has to be made and increments the decision variable which is used to access the correct place on breakpoints array.
        if ( numberOfChoices() > 2 )
        {
            decision++;

            breakPoints[decision][0] = pos.x;
            breakPoints[decision][1] = pos.y;


            direction = check();
        }

        //If a decision has been made, program enters this while loop and stays in it unless it reaches the place where the fist decision was made.
        //Notice that there can be more decisions to be made after the fist one.
        while ( decision > 0 && !done )
        {
            if ( !checkHere(direction) )
            {
                //If entity reaches a dead-end, it starts moving back, and marks the squares behind it to know not to enter there again.
                //Keeps doing this until reaches where the last decision was made. Then decrements the decision variable.
                if ( numberOfChoices() == 1 )
                {
                    while ( !(pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1]) && numberOfChoices() <= 1 )
                    {
                        maze[pos.y][pos.x] = BLOCK -1;  // -1 is because moveto function will increment whatever value it will find at where entity is, before moving to the next square.

                        direction = check();
                        moveto ( direction );
                        printMaze();
                    }
                    // If reached where the last decision was made, decrement the number of decisions.
                    if ( pos.x == breakPoints[decision][0] && pos.y == breakPoints[decision][1] )
                    {
                        decision--;
                    }
                    direction = check();
                }
                else
                {
                    direction = check();
                }
            }
            //If it can keep moving without any problem, keeps moving,
            //and if reaches another point where it has to decide again, stores that point too next to the previous one(s).
            else
            {
                moveto(direction);
                printMaze();

                if ( numberOfChoices() > 2 )
                {
                    decision++;
                    breakPoints[decision][0] = pos.x;
                    breakPoints[decision][1] = pos.y;

                    direction = check();
                }
            }
        }
    }

    //Notice that algorithm does not check whether it reached the end in the main function explicitly.
    //That's because this is done in the function 'moveto'.

    printf("\nMapping is finished.");
    system("pause");



    /// STEP #2 : Starting at the beginning again and following the correct path. ///

    done = false;

    //Reset the position of entity.
    pos.x = INIT_X;
    pos.y = INIT_Y;

    printBlankMaze();
    system("pause");

    //Until it reaches the end, follows the previously constructed path in the mapping phase.
    while ( !done )
    {
        direction = followTrace( direction );
        follow ( direction );
        printBlankMaze();

        if ( pos.x == FINISH_X && pos.y == FINISH_Y ) { done = true; }
    }

    printf("\nMAZE COMPLETED!");






    return 0;
}



















