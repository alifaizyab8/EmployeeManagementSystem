#include <stdio.h>
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"
#include "../include/libraryfunc.h"

int userID; 
char userPASS[7];

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
    printf("\t\tL       OOO   GGGG  III N   N    PPPP   OOO  RRRR  TTTTT  A    L\n");
    printf("\t\tL      O   O  G      I  NN  N    P   P O   O R   R   T   A A   L\n");
    printf("\t\tL      O   O  G  GG  I  N N N    PPPP  O   O RRRR    T  AAAAA  L\n");
    printf("\t\tLLLLL   OOO    GGGG III N  NN    P      OOO  R  R    T A     A LLLLL\n");
    printf("\033[0m\n");
}
void line()
{
    for (int i = 0; i < 150; i++)
    {
        printf("\033[1;36m=\033[35m");
    }
    printf("\n");
}

void displayLoginScreen()
{
    
    line();
    printf("\n\n");
    printEMS();
    printf("\n\n");
    line();
    printf("\n\n");
    printLoginTitle();
    printf("\n\n");

    FILE *fp = fopen("../data/login.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening login file.\n");
        return;
    }
    while (1)
    {
        printf("\033[1;35mUser ID: \033[0m");
        scanf("%d", &userID);
        printf("\033[1;35mPassword: \033[0m");
        scanf("%s", userPASS);

        char file_line[50];
        int login_success = 0;

        while (fgets(file_line, sizeof(file_line), fp))
        {
            int file_userID;
            char file_password[7];
            sscanf(file_line, "%d,%6s", &file_userID, file_password);

            if (userID == file_userID && strcmp_custom(userPASS, file_password) == 0)
            {
                printf("\033[1;32mLogin Successful! Welcome User %d\033[0m\n", userID);
                login_success = 1;
                break;
            }
        }

        if (login_success)
        {
            break;
        }
        else
        {
            printf("\033[31mIncorrect User ID or Password! Try Again.\033[0m\n");
            rewind(fp); // Reset file pointer to the beginning for the next attempt
        }
    }
    printf("\n");
    line();
    printf("\n\n");
    fclose(fp);
}
