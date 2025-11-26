#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"
#include "../include/libraryfunc.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu(struct Employee employees[], int *employeeCount)
{
    int choice;
    int id;
    char term; // used to catch garbage characters

    while (1)
    {
        clearScreen();

        printf("\n\033[1;36m=====================================\033[0m\n");
        printf("\033[1;33m        EMPLOYEE MANAGEMENT MENU      \033[0m\n");
        printf("     \033[1;35mDatabase Status: %d / %d Slots\033[0m    \n", *employeeCount, MAX_EMPLOYEES);
        printf("\033[1;36m=====================================\033[0m\n");

        printf("1. Employee List\n");
        printf("2. Add New Employee\n");
        printf("3. Remove Employee\n");
        printf("4. Search Employee\n");
        printf("5. Edit Employee Details\n");
        printf("6. Display Highly Paid Employees\n");
        printf("7. Exit\n");
        printf("\033[1;36m-------------------------------------\033[0m\n");
        printf("Enter your choice (1-7): ");

        // If scanf fails or if the char after the number isn't a
        if (scanf("%d%c", &choice, &term) != 2 || term != '\n')
        {
            printf("\033[1;31mInvalid input! Please enter a number.\033[0m\n");

            while (getchar() != '\n')
                ; // Clear buffer

            // Pause so user can affirm error message
            printf("Press Enter to try again...");
            getchar();
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("\n\033[1;34m--- EMPLOYEE LIST ---\033[0m\n");
            displayAllEmployees(employees, *employeeCount);
            break;

        case 2:
            // Checking return value: 1 success, 0 fail
            if (!addEmployee(employees, employeeCount))
            {
                // Only print this if it failed, success msg already in function
                printf("\033[1;31mFailed to add employee.\033[0m\n");
            }
            break;

        case 3:

            printf("Enter Employee ID to remove: ");
            // Simple check
            if (scanf("%d", &id) != 1)
            {
                printf("\033[1;31mInvalid ID input!\033[0m\n");
                while (getchar() != '\n')
                    ; // buffer
            }
            else
            {
                // Clear the enter key left by the ID scanf
                while (getchar() != '\n')
                    ;

                if (!removeEmployee(employees, employeeCount, id))
                {
                    printf("\033[1;31mRemoval failed or cancelled.\033[0m\n");
                }
            }
            break;

        case 4:
            // into submenu
            searchMenu(employees, employeeCount);
            break;

        case 5:
            // fully independent edit function with its own menu so no external menu needed
            printf("\n\033[1;34m--- EDIT EMPLOYEE ---\033[0m\n");
            printf("Enter Employee ID to edit: ");
            if (scanf("%d", &id) != 1)
            {
                printf("\033[1;31mInvalid ID input!\033[0m\n");
                while (getchar() != '\n') // clear bufer
                    ;
            }
            else
            {
                while (getchar() != '\n')
                    ; // Clear buffer
                editEmployee(employees, *(employeeCount), id);
            }

            break;
        case 6:
            highlyPaidEmployee(employees, *employeeCount);
            break;
        case 7:
            printf("\n\033[1;35mExiting program... Goodbye!\033[0m\n");
            exit(0);
        default:
            printf("\033[1;31mInvalid choice! Please select between 1-7.\033[0m\n");
        }

        // Wait for user
        printf("\nPress Enter to return to menu...");
        getchar();
    }
}

void searchMenu(struct Employee employees[], int *employeeCount)
{
    int searchChoice;
    char term;

    while (1)
    {
        clearScreen();
        printf("\n\033[1;36m=== Search Employee Menu ===\033[0m\n");
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Search by Age\n");
        printf("4. Search by Position\n");
        printf("5. Return to Main Menu\n");
        printf("\033[1;36m----------------------------\033[0m\n");
        printf("Enter your choice: ");

        // Strict Input validation
        if (scanf("%d%c", &searchChoice, &term) != 2 || term != '\n')
        {
            printf("\033[1;31mInvalid input! Try again.\033[0m\n");
            while (getchar() != '\n')
                ;
            printf("Press Enter to continue...");
            getchar();
            continue;
        }

        // Buffer clean

        if (searchChoice == 1)
        {
            searchbyID(employees, *employeeCount);
        }
        else if (searchChoice == 2)
        {
            searchbyName(employees, *employeeCount);
        }
        else if (searchChoice == 3)
        {
            searchbyAge(employees, *employeeCount);
        }
        else if (searchChoice == 4)
        {
            searchbyposition(employees, *employeeCount);
        }
        else if (searchChoice == 5)
        {
            return; // back to showMenu
        }
        else
        {
            printf("\033[1;31mInvalid choice! Try again.\033[0m\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }
}