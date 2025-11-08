#include "../include/extras.h"
#include "../include/employee.h"
#include <stdio.h>


void showMenu(struct Employee employees[], int *employeeCount) {
    int choice;

    while (1) {
        printf("\n====== MENU ======\n");
        printf("1. DISPLAY SINGLE EMPLOYEE\n");
        printf("2. ADD EMPLOYEE\n");
        printf("3. REMOVE EMPLOYEE\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR DESIRED OPTION: ");
        scanf("%d", &choice);  
        switch (choice) {
            case 1:
                printf("DISPLAYING SINGLE EMPLOYEE:\n");
                displaySingleEmployee(employees, *employeeCount, employees[0].id);
                break;
            case 2:
                printf("ADDING NEW EMPLOYEE:\n");
                addEmployee(employees, employeeCount);
                break;
            case 3:
                printf("REMOVING EMPLOYEE:\n");
                removeEmployee(employees, employeeCount, employees[0].id);
                break;
            case 4:
                printf("EXITING PROGRAM\n");
                return;
            default:
                printf("INVALID SELECTION!\n");
        }
    }
}
