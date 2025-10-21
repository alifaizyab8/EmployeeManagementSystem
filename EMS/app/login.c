#include <stdio.h>
#include <string.h>
#include "../include/login.h"
int userID;
char userPASS[7];
int user_id[25] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020,
                   1021, 1022, 1023, 1024, 1025};
char passwords[25][7] = {
    "alpha1", "bravo2", "charl3", "delta4", "echo55",
    "foxtt6", "golf77", "hotel8", "india9", "julie0",
    "kilos1", "limaa2", "miken3", "novem4", "oscar5",
    "papat6", "queen7", "romeo8", "sierra", "tango9",
    "union0", "victor", "whisk1", "xray22", "yanke3"};
void printEMS()
{
    printf("\033[1;95m"); 
    printf("\n");
    printf("\t\t\t\tEEEEEEE   M     M   SSSSS  \n");
    printf("\t\t\t\tE         MM   MM  S       \n");
    printf("\t\t\t\tEEEEE     M M M M   SSSSS  \n");
    printf("\t\t\t\tE         M  M  M       S  \n");
    printf("\t\t\t\tEEEEEEE   M     M   SSSSS  \n");
    printf("\033[0m");
    printf("\n");
}
void printLoginTitle()
{
    printf("\033[1;95m"); 
    printf("\n");
    printf("\t\tL       OOO   GGGG  III  N   N    PPPP   OOO  RRRR  TTTTT  A    L\n");
    printf("\t\tL      O   O  G      I  NN  N    P   P O   O R   R   T   A A   L\n");
    printf("\t\tL      O   O  G  GG  I  N N N    PPPP  O   O RRRR    T  AAAAA  L\n");
    printf("\t\tLLLLL   OOO    GGGG III N  NN    P      OOO  R  R    T A     A LLLLL\n");
    printf("\033[0m\n");
}
void line()
{
    for (int i = 0; i < 100; i++)
    {
        printf("\033[1;36m=\033[35m");
    }
    printf("\n");
}

void displayLoginScreen()
{
    int ind;
    line();
    printf("\n\n");
    printEMS();
    printf("\n\n");
    line();
    printf("\n\n");
    printLoginTitle();
    printf("\n\n");
    while (1)
    {
        printf("\033[1;35mUser ID: \033[0m");
        scanf("%d", &userID);
        int found = 0;
        for (int i = 0; i < 25; i++)
        {
            if (userID == user_id[i])
            {
                found += 1;
                ind = i;
                break;
            }
        }
        if (found == 1)
        {
            printf("\033[1;32mWelcome User %d\033[0m\n", userID);
            break;
        }
        else
        {
            printf("\033[31mNo Such user found\033[0m\n");
        }
    }
    while (1)
    {
        printf("\033[1;35mPassword: \033[0m");
        scanf("%s", userPASS);

        if (strcmp(userPASS, passwords[ind]) == 0)
        {
            printf("\033[1;32mLogin Successful!\033[0m\n");
            break;
        }

        else
        {
            printf("\033[31mIncorrect Password! Try Again.\033[0m\n");
        }
    }
    printf("\n");
    line();
    printf("\n\n");
}

int main()
{
    displayLoginScreen();
    return 0;
}