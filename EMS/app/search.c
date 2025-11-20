#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../include/search.h"
#include "../include/menuHandler.h"
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/libraryfunc.h"

// Functions for Searching Menu
/*
    1. searchByID
    2. searchByName
    3. searchByAge
    4. searchByDepartment
*/
//


void searchbyID(struct Employee employees[], int size)
{
    system("cls");
    int id;
    printf("Enter Employee ID to search: ");
    char term;
    while(1){

        if (scanf("%d%c", &id, &term) != 2 || term != '\n')
            {
                printf("Invalid input. Please enter numbers only (no letters or symbols).\n");
                printf("Enter Employee ID to search: ");
                // flush the whole buffer to remove the "digit" part
                while (getchar() != '\n'); 
                continue;
            }
        else{

            break;
        }

    }
    

    line();
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (employees[i].id == id)
        {

            printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                   "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");

            line();

            printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                   employees[i].id,
                   employees[i].emp.firstname,
                   employees[i].emp.lastname,
                   employees[i].age,
                   employees[i].position,
                   employees[i].salary,
                   employees[i].working_hours,
                   employees[i].over_time,
                   employees[i].performance_rating);

            found = 1;

            break;
        }
    }

    if (!found)
    {

        printf("No employee found with ID: %d\n", id);
        line();
    }
    line();
}




void searchbyName(struct Employee employees[], int size)
{
    system("cls");
    char fName[50];
    char secName[50];
    int found = 0;

    printf("Enter First Name: ");
    scanf("%49s", fName);
    while (getchar() != '\n')
        ;

    toLowercase_custom(fName);
    line();

    // First pass: check if first name exists
    for (int i = 0; i < size; i++)
    {
        char tempFirst[50];
        strcpy_custom(tempFirst, employees[i].emp.firstname);
        toLowercase_custom(tempFirst);

        if (strcmp_custom(tempFirst, fName) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("No employee found with the first name: %s\n", fName);
        line();

        return;
    }

    // Get second name
    printf("Enter Second Name (or press Enter to skip): ");

    // Read character by character to detect empty input
    int idx = 0;
    char ch;
    while ((ch = getchar()) != '\n' && idx < 49)
    {
        secName[idx++] = ch;
    }
    secName[idx] = '\0';

    if (strlen_custom(secName) > 0)
    {
        toLowercase_custom(secName);
    }

    // Display results
    line();
    printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
           "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
    line();

    int resultsFound = 0;
    for (int i = 0; i < size; i++)
    {
        char tempFirst[50], tempLast[50];
        strcpy_custom(tempFirst, employees[i].emp.firstname);
        strcpy_custom(tempLast, employees[i].emp.lastname);

        toLowercase_custom(tempFirst);
        toLowercase_custom(tempLast);

        // Check first name match
        if (strcmp_custom(tempFirst, fName) == 0)
        {
            // If second name provided, check it too
            if (strlen_custom(secName) == 0 || strcmp_custom(tempLast, secName) == 0)
            {
                printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                       employees[i].id,
                       employees[i].emp.firstname,
                       employees[i].emp.lastname,
                       employees[i].age,
                       employees[i].position,
                       employees[i].salary,
                       employees[i].working_hours,
                       employees[i].over_time,
                       employees[i].performance_rating);
                resultsFound++;
            }
        }
    }

    if (resultsFound == 0)
    {
        printf("No employee found with the name: %s %s\n", fName, secName);
    }

    line();
}

void searchbyAge(struct Employee employees[], int size)
{

    system("cls");
    printf("1. Search by Exact Age\n");
    printf("2. Search by Age Range\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;
    line();

    if (choice != 1 && choice != 2)
    {

        printf("Invalid choice!\n");
        return;
    }

    if (choice == 1)
    {
        int age, l = 0;
        printf("Enter Age: ");
        scanf("%d", &age);
        while (getchar() != '\n')
            ;
        line();

        for (int i = 0; i < size; i++)
        {
            if (employees[i].age == age)
            {

                if (l == 0)
                {

                    printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                           "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
                    line();
                    l++;
                }

                printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                       employees[i].id,
                       employees[i].emp.firstname,
                       employees[i].emp.lastname,
                       employees[i].age,
                       employees[i].position,
                       employees[i].salary,
                       employees[i].working_hours,
                       employees[i].over_time,
                       employees[i].performance_rating);
            }
        }
    }

    if (choice == 2)
    {

        int minAge, maxAge, l = 0;
        printf("Enter minimum age: ");
        scanf("%d", &minAge);
        while (getchar() != '\n')
            ;
        printf("\nEnter maximum age: ");
        scanf("%d", &maxAge);
        while (getchar() != '\n')
            ;

        for (int i = 0; i < size; i++)
        {

            if (employees[i].age >= minAge && employees[i].age <= maxAge)
            {

                if (l == 0)
                {

                    printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                           "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
                    line();
                    l++;
                }

                printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                       employees[i].id,
                       employees[i].emp.firstname,
                       employees[i].emp.lastname,
                       employees[i].age,
                       employees[i].position,
                       employees[i].salary,
                       employees[i].working_hours,
                       employees[i].over_time,
                       employees[i].performance_rating);
            }
        }
    }

    line();
}


void searchbyposition(struct Employee employees[], int size)
{

    system("cls");
    char pos[50];
    
    printf("Enter Employee Position: ");
    scanf(" %49[^\n]", pos);
    while (getchar() != '\n');

    toLowercase_custom(pos);
    line();

    int found = 0;
    for(int i = 0; i < size; i++)
    {   
        char temppos[50];
        strcpy_custom(temppos, employees[i].position);

        toLowercase_custom(temppos);
        if(strcmp_custom(temppos, pos)==0)
        {

            found = 1;
            break;

        }
    }
        if(!found)
        {

            printf("No employee found in the department: %s\n", pos);
            line();
            return;

        }

        else{

            printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                   "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
            line();

            for(int i = 0; i < size; i++)
            {
                char temppos2[50];
                strcpy_custom(temppos2, employees[i].position);

                toLowercase_custom(temppos2);

                if(strcmp_custom(temppos2, pos)==0)
                {

                    printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                           employees[i].id,
                           employees[i].emp.firstname,
                           employees[i].emp.lastname,
                           employees[i].age,
                           employees[i].position,
                           employees[i].salary,
                           employees[i].working_hours,
                           employees[i].over_time,
                           employees[i].performance_rating);
                }
            }
        }

    
    
    line();

}