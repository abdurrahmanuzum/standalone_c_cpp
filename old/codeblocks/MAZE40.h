#define WALL 32768
#define SIZE 40
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 38
#define FINISH_Y 38


extern int maze [SIZE][SIZE] =
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
