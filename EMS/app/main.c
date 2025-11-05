#include <stdio.h>
#include "../include/login.h"
#include "../include/employee.h"

// RUN COMMAND FOR NOW : gcc main.c employee.c login.c && ./a.exe
int main()
{
    // Display Login Screen
    //displayLoginScreen();
    // Employee array
    struct Employee employees[MAX_EMPLOYEES];
    
    /*
    My load employee function returns the number of employees loaded and loads
    data from employee.txt into the employees array
    */
    int employeeCount = loadEmployee(employees, MAX_EMPLOYEES);
    // Initialize employee records at the start of the program
    

    // Testing Add Employee Function
    int temp = addEmployee(employees, &employeeCount);
    if (temp)
        printf("Employee added successfully. Total Employees: %d\n", employeeCount);
    else
        printf("Failed to add employee.\n");
    displaySingleEmployee(employees, MAX_EMPLOYEES, employees[0].id);
    int temp2 = removeEmployee(employees, &employeeCount, employees[0].id);
    if (temp2)
        printf("Employee removed successfully. Total Employees: %d\n", employeeCount);
    else
        printf("Failed to remove employee.\n");
    displaySingleEmployee(employees, MAX_EMPLOYEES, employees[0].id);


 void showMenu();
    return 0;
}