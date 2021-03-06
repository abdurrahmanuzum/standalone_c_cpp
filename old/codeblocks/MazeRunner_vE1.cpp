#include <bits/stdc++.h>
//#include <String.h>
#include <iostream>
#include <string>

#define WALL 32787
#define SIZE 20
#define INIT_X 1
#define INIT_Y 1
#define FINISH_X 18
#define FINISH_Y 18
#define FRAME_DELAY 100  //Decrement the value for less delay per step.

using namespace std;

int maze [SIZE][SIZE] =
{
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,  0 ,  0 ,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,  0 ,WALL},
    {WALL,WALL,WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,  0 ,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,  0 ,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
};

int absoluteDirection = 0;
int done = false;




double rightSensor;
double leftSensor;
double frontSensor;
bool deathEnd = false;

stack <string> stc;

string ways;



enum directions
{
    NORTH = 1,
    SOUTH = -1,
    EAST = 0,
    WEST = 2
};


int FORWARD = 0;
int RIGHT = -1;
int LEFT = 1;
int BACK = 2;


struct Position
{
    int x = 1;
    int y = 1;

} pos;




void printMaze()
{
    int holder = maze[pos.y][pos.x];
    maze[pos.y][pos.x] = 'o';

    system("cls");
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++)
        {
            printf(" ");
            switch(maze[i][j])
            {
                case WALL:
                    printf("???");
                break;

                case 'o':
                    printf("o");
                break;

                default:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }

    //Sleep(FRAME_DELAY);
    maze[pos.y][pos.x] = holder;
}


bool checkHere ( int where )
{
    int x = pos.x;
    int y = pos.y;

    switch ( where )
    {
        case NORTH:
            if ( maze[y-1][x] != WALL ) { return true; }
            else { return false; }
            break;

        case SOUTH:
            if ( maze[y+1][x] != WALL ) { return true; }
            else { return false; }
            break;

        case EAST:
            if ( maze[y][x+1] != WALL ) { return true; }
            else { return false; }
            break;
        case WEST:
            if ( maze[y][x-1] != WALL ) { return true; }
            else { return false; }
            break;

        default:
            printf("\nIn function: checkHere(int where) FATAL ERROR!");
            exit(-1);
            break;
    }
}


void turn ( int where )
{
    int prevFORWARD = FORWARD;
    int prevRIGHT = RIGHT;
    int prevLEFT = LEFT;
    int prevBACK = BACK;

    if ( where == FORWARD )
    {
        ;
    }
    else if ( where == RIGHT )
    {
        absoluteDirection--;

        FORWARD = prevRIGHT;
        RIGHT = prevBACK;
        LEFT = prevFORWARD;
        BACK = prevLEFT;
    }

    else if ( where == LEFT )
    {
        absoluteDirection++;

        FORWARD = prevLEFT;
        RIGHT = prevFORWARD;
        LEFT = prevBACK;
        BACK = prevRIGHT;
    }

    else if ( where == BACK )
    {
        absoluteDirection += 2;

        FORWARD = prevBACK;
        RIGHT = prevLEFT;
        LEFT = prevRIGHT;
        BACK = prevFORWARD;
    }
    else
    {
        printf("\nIn function turn(int where) %d passed to function.  FATAL ERROR", where);
        exit(-1);
    }

    printMaze();
}



void proceed ()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            pos.x++;
            break;

        case 1: case -3:
            pos.y--;
            break;

        case 2: case -2:
            pos.x--;
            break;

        case 3: case -1:
            pos.y++;
            break;
    }

    if ( pos.x == FINISH_X && pos.y == FINISH_Y ) { done = true; }

    printMaze();
}




bool readForward()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            return checkHere(EAST);
            break;

        case 1: case -3:
            return checkHere(NORTH);
            break;

        case 2: case -2:
            return checkHere(WEST);
            break;

        case 3: case -1:
            return checkHere(SOUTH);
            break;
    }
}


bool readRight()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            return checkHere(SOUTH);
            break;

        case 1: case -3:
            return checkHere(EAST);
            break;

        case 2: case -2:
            return checkHere(NORTH);
            break;

        case 3: case -1:
            return checkHere(WEST);
            break;
    }
}


bool readLeft()
{
    switch ( absoluteDirection%4 )
    {
        case 0:
            return checkHere(NORTH);
            break;

        case 1: case -3:
            return checkHere(WEST);
            break;

        case 2: case -2:
            return checkHere(SOUTH);
            break;

        case 3: case -1:
            return checkHere(EAST);
            break;
    }
}











void removeDeathEnd()
{
      //motor 180 d??ner
      turn(BACK);

      while (true)
      {
           // poplanan move da possible way ????kana kadar d??necek
            string returnWay;
            returnWay = stc.pop();

            if (returnWay.length() < 2)
            {
                  // e??er poplanan move possible way i??ermiyorsa poplanan move u yap

                  if (returnWay.charAt(0) == 'r')
                  {
                      // poplanana g??re tersine d??ner ve devam eder
                      while( !readLeft() )
                      {
                        //d??z git
                        proceed();
                      }
                      //sola d??n
                      turn(LEFT);
                  }
                  else if (returnWay.charAt(0) == 'l')
                  {
                      while( !readRight() )
                      {
                         //d??z git
                         proceed();
                      }
                      //sa??a d??n????
                      turn(RIGHT);
                  }
            }

            // e??er possible way varsa
            else
            {

                  if ( returnWay.charAt(0) == 'f' )
                  {
                        if (returnWay.charAt(1) == 'r') // sa??a d??nd??ysem sol sens??r?? s??rekli kontrol ediyorum
                        {
                              while ( !readLeft() )
                              {
                                  //d??z git
                                  proceed();
                              }
                              //sol tarafta yol var, sola d??n


                              //junctionday??m stci d??zeltmem gerekiyor
                              returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i al??nan yol olarak pushluyorum
                              returnWay.setCharAt(1, '\0'); // possible wayi sildim
                              stc.push(returnWay);

                              //sola d??n????
                              turn(LEFT);
                        }
                        else if (returnWay.charAt(1) == 'l') // ??sttekinin tam ters y??n??
                        {
                              while ( !readRight() )
                              {
                                //d??z git
                                proceed();
                              }
                              //sa??a d??n??cem
                              turn(RIGHT);

                              //junctionday??m stci d??zeltmem gerekiyor
                              returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i al??nan yol olarak pushluyorum
                              returnWay.setCharAt(1, '\0'); // possible wayi sildim
                              stc.push(returnWay);
                        }
                  }
                  else
                  {
                      if(returnWay.charAt(0) == 'r')
                      {
                           while ( !readLeft() )
                           {
                               //d??z git
                               proceed();
                           }
                          returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i al??nan yol olarak pushluyorum
                          returnWay.setCharAt(1, '\0'); // possible wayi sildim
                          stc.push(returnWay);
                      }

                      else if(returnWay.charAt(0) == 'l')
                      {
                           while ( !readRight() )
                           {
                              //d??z git
                              proceed();
                           }
                           //returnWay right olarak pushlad??m.
                          returnWay.setCharAt(0, returnWay.charAt(1)); // possible way i al??nan yol olarak pushluyorum
                          returnWay.setCharAt(1, '\0'); // possible wayi sildim
                          stc.push(returnWay);
                      }

                      break; //bu else ten sonra possible wayin ba????na geldim
                      // bu yola daha ??nce girmedi??im i??in bu fonksiyondan ????k??p normal yol alma d??ng??s??ne giriyorum
                  }
            }
        }
}
void checkPoints()
{

      //daha mant??kl?? say??lar doubke a g??re ayarla. tmm.
      if ( readRight() && readLeft() )
      {
            switch ( rand()%2 )
            {
                case 0:
                    //ways[1] null eklemem gerekiyor mu ? bilmem.
                    stc.push("rl");
                    //sa??a d??n
                    turn(RIGHT);
                break;

                case 1:

                    stc.push("lr");
                    //sola d??n
                    turn(LEFT);
                break;
            }

      }
      else if ( readRight() )
      {
            stc.push("r");
            //sa??a d??n
            turn(RIGHT);
      }
      else if ( readLeft() )
      {
            stc.push("l");
            //sola d??n
            turn(LEFT);
      }
      else if ( !readForward() && readRight()  && !readLeft() )
      {
            //deathend ise
            deathEnd = true;
      }
}



void possibleWays()
{
      if ( readRight() && readLeft() )
      {
          stc.push("fr");
          stc.push("fl");
      }
      else if ( readRight() )
      {
          stc.push("fr");
      }
      else if ( readLeft() )
      {
          stc.push("fl");
      }

}








int main()
{
    printMaze();
    deathEnd = false;
    int i = 0;

    while ( !done )
    {

          if ( !(deathEnd) )
          {
                while ( readForward() )
                {

                      //Serial.print("repeats: ");
                      //Serial.println(i++);

                      //motor d??z ??al????t??r
                      proceed();

                      // right, left sensor bilgilerini al saniyede bir
                      possibleWays();
                }
                checkPoints();

          }
          else
          {
                //while: bir possible wayde daha fazla ilerleyemiyorsan di??er possible a bak. varsa di??erine gerek yok.
                //possiblewaysleri ziyaret etmesi i??in
                //deathendler kar??????yor.DENEEE??????????????


                //motor d??z, normale g??re yava?? ??al????s??n
                proceed(); ///!!!!!!///

                // checkPoints(); // deathEnd true ise checkPoints yapmaya gerek yok
                removeDeathEnd();
                deathEnd = false;
          }


    }
    Serial.println("DONE !");
    return 0;

}
