#include "../include/employee.h"
#include "../include/login.h"
#include "../include/extras.h"
#include "../include/search.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu(struct Employee employees[], int *employeeCount)
{
    int choice;
    int id;
    while (1)
    {
        system("cls");
        printf("\n\033[1;36m=====================================\033[0m\n");
        printf("\033[1;33m        EMPLOYEE MANAGEMENT MENU      \033[0m\n");
        printf("\033[1;36m=====================================\033[0m\n");
        printf("1. Employee List\n");
        printf("2. Add New Employee\n");
        printf("3. Remove Employee\n");
        printf("4. Search Employee\n");
        printf("5. Exit\n");
        printf("\033[1;36m-------------------------------------\033[0m\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\033[1;31mInvalid input! Please enter a number.\033[0m\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {

        case 1:
            printf("\n\033[1;34m--- EMPLOYEE LIST ---\033[0m\n");
            displayAllEmployees(employees, *employeeCount);
            break;
        case 2:
            printf("\n\033[1;34m--- ADDING NEW EMPLOYEE ---\033[0m\n");
            if (addEmployee(employees, employeeCount))
                printf("\033[1;32mEmployee added successfully!\033[0m\n");
            else
                printf("\033[1;31mFailed to add employee.\033[0m\n");
            break;

        case 3:
            printf("\n\033[1;34m--- REMOVING EMPLOYEE ---\033[0m\n");
            printf("Enter Employee ID to remove: ");
            if (scanf("%d", &id) != 1)
            {
                printf("\033[1;31mInvalid ID input!\033[0m\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            if (removeEmployee(employees, employeeCount, id))
                printf("\033[1;32mEmployee removed successfully!\033[0m\n");
            else
                printf("\033[1;31mRemoval failed.\033[0m\n");
            break;
        case 4:
            printf("\n\033[1;34m--- Entering Search Menu ---\033[0m\n");
            searchMenu(employees, employeeCount);
            break;
        case 5:
            printf("\n\033[1;35mExiting program... Goodbye!\033[0m\n");
            return;

        default:
            printf("\033[1;31mInvalid choice! Please select between 133.\033[0m\n");
        }

        printf("\nPress Enter to return to menu...");
        while (getchar() != '\n')
            ;
        getchar();
    }
}

void searchMenu(struct Employee employees[], int *employeeCount)
{
    system("cls");
    int searchChoice;
    while (1)
    {
        system("cls");
        printf("\n=== Search Employee Menu ===\n");
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Search by Age\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &searchChoice) != 1)
        {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (searchChoice == 1)
        {
            // searchByID function
            printf("Search by ID selected, under development\n");
        }
        else if (searchChoice == 2)
        {
            // searchByName function
            searchbyName(employees, *employeeCount);
        }
        else if (searchChoice == 3)
        {
            // searchByAge function
            searchbyAge(employees, *employeeCount);
        }
        else if (searchChoice == 4)
        {
            return;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }
}
void displayAllEmployees(const struct Employee employees[], int employeeCount)
{
    if (employeeCount == 0)
    {
        printf("\033[1;31mNo employees found to display.\033[0m\n");
        return;
    }

    line();
    printf("\n\033[1;34mAll Employees List\033[0m\n");

    printf("\033[1;33m%-5s %-15s %-15s %-5s %-25s %-13s %-5s %-10s %-5s\033[0m\n",
           "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
    line();

    for (int i = 0; i < employeeCount; i++)
    {
        printf("%-5d %-15s %-15s %-5d %-25s %-15.2f %-10d %-10d %-5.1f\n",
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

    line();
}
