#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char blankName[20];
char blankPassword[20];
char blankSSI[20];

char passwordConfirm[20];

bool match;



char Users [][3][20] = {
                    "username", "password", "secret",
                    "Ahmet", "Ahmet", "Ahmet",
                       };

int n;
char user[20];
int i;

int nou;

int nouC;

int Length(int x, int y) {
    int length;
    for (length = 0; length <= 20; length++) {
        if(Users[x][y][length] == '\0') { break; }
    }
    return length;
}



bool Match(int userNumber, int nameOrPassword, char stringToCheck[20]) {

        n = Length(userNumber, 0);

        for (i=0; i<20; i++) {

                if(i == n) { break; }
                if( stringToCheck[i] == Users[userNumber][nameOrPassword][i] ) { match = true; continue; }

                match = false;
                break;

        }
    return match;

}

void Register(char tempString[20], int userCounter) {          //call with the arguments: (blankName, nou)


    n = strlen(tempString);

    for ( i=0; i<20; i++) {
            if(i == n) { break; }
            Users[userCounter][0][i] = tempString[i];
    }
    userCounter++;
    nou++;

    setPassword:
        printf("Please set a password: ");
        fgets(blankPassword, 20, stdin);

        printf("Please confirm your password: ");
        fgets(passwordConfirm, 20, stdin);

    if ( strcmp(blankPassword, passwordConfirm ) == 0 ) {

            for (i=0; i<strlen(blankPassword); i++) {
                Users[userCounter][1][i] = blankPassword[i];
            }

            printf("You have sucessfully registered. ");
            printf("Please enter your super secret information: ");
            fgets(blankSSI, 20, stdin);
            for (i=0; i<strlen(blankSSI); i++) {
                Users[userCounter][2][i] = blankSSI[i];
            }
    }
    else {
            printf("Not confirmed.");
            goto setPassword;

    }
}





int j;
int main() {
    nou = 2;

    begin:

    strcpy(blankName, "");
    strcpy(blankPassword, "");
    strcpy(blankSSI, "");


    printf("Enter your username: ");
    fgets(blankName, 20, stdin);

    while(nouC < nou) {
        if(Match(nouC, 0, blankName)) { break; }
        nouC++;
        Register(blankName, nou);




    for (j=0; j<nou; j++) {

        if(Match(j, 0, blankName)) { break; }

        Register(blankName, nou);
        break;

    }

    printf("%d", j);




    if(Match(j, 0, blankName)) {
        printf("Match for %d.user\n", j);

        enterPassword:
            printf("Please enter your password: ");
            fgets(blankPassword, 20, stdin);


        if( Match(j, 1, blankPassword) ) { printf("You have logged in!"); }
        else {
                printf("Wrong password");
                goto enterPassword;
        }
    }






    goto begin;
    return 0;

}
