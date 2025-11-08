#include "../include/extras.h"
#include "../include/employee.h"
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
        printf("1. Add New Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Exit\n");
        printf("\033[1;36m-------------------------------------\033[0m\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\033[1;31mInvalid input! Please enter a number.\033[0m\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("\n\033[1;34m--- ADDING NEW EMPLOYEE ---\033[0m\n");
            if (addEmployee(employees, employeeCount))
                printf("\033[1;32mEmployee added successfully!\033[0m\n");
            else
                printf("\033[1;31mFailed to add employee.\033[0m\n");
            break;

        case 2:
            printf("\n\033[1;34m--- REMOVING EMPLOYEE ---\033[0m\n");
            printf("Enter Employee ID to remove: ");
            if (scanf("%d", &id) != 1)
            {
                printf("\033[1;31mInvalid ID input!\033[0m\n");
                while (getchar() != '\n');
                break;
            }
            if (removeEmployee(employees, employeeCount, id))
                printf("\033[1;32mEmployee removed successfully!\033[0m\n");
            else
                printf("\033[1;31mEmployee not found or removal failed.\033[0m\n");
            break;

        case 3:
            printf("\n\033[1;35mExiting program... Goodbye!\033[0m\n");
            return;

        default:
            printf("\033[1;31mInvalid choice! Please select between 133.\033[0m\n");
        }

        printf("\nPress Enter to return to menu...");
        while (getchar() != '\n');
        getchar();
    }
}

