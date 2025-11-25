#include <stdio.h>
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"
#include "../include/libraryfunc.h"

int userID;
char userIDstr[7];
char userPASS[7];

// Function to print EMS in stylized text format
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

// Function to print Login Title in stylized text format
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

// Function to print a line separator
void line()
{
    for (int i = 0; i < 150; i++)
    {
        printf("\033[1;36m=\033[35m");
    }
    printf("\n");
}

// Function to display the login screen and handle user authentication
// Prompts user for ID and password, verifies against stored credentials from file
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
        scanf("%s", userIDstr);
        while (getchar() != '\n')
            ;
        while (1)
        {
            if (!isDigitString_custom(userIDstr))
            {
                printf("\033[31mUser ID must be numeric. Try Again.\033[0m\n");
                printf("\033[1;35mUser ID: \033[0m");
                scanf("%s", userIDstr);
                while (getchar() != '\n')
                    ;
            }
            else
            {
                userID = atoi_custom(userIDstr);
                break;
            }
        }
        while (1)
        {
            printf("\033[1;35mPassword: \033[0m");
            scanf("%s", userPASS);
            while (getchar() != '\n')
                ;

            // Password length check. Length should be 6-7 characters
            if (strlen_custom(userPASS) < 6)
            {
                printf("\033[31mPassword must be atleast 6 characters long. Try Again.\033[0m\n");
                continue;
            }
            else
            {

                break;
            }
        }

        char file_line[50];
        int login_success = 0;

        while (fgets(file_line, sizeof(file_line), fp))
        {
            int file_userID;
            char file_password[7];
            sscanf(file_line, "%d,%6s", &file_userID, file_password);

            // Compare input credentials with file credentials
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
