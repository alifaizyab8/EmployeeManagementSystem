#include <stdio.h>
#include "../include/login.h"
#include "../include/employee.h"

// RUN COMMAND FOR NOW : gcc main.c employee.c login.c && ./a.exe
int main()
{
    // Display Login Screen
    displayLoginScreen();
    // Employee array
    struct Employee employees[MAX_EMPLOYEES];
    // Where ever *count is used, it is to keep track of the number of employees currently in the system
    // we pass employeeCount with & to send its address
    int employeeCount = 0;
    // Initialize employee records at the start of the program
    initializeEmployees(employees, MAX_EMPLOYEES);

    // Testing Add Employee Function
   // addEmployee(employees, &employeeCount);
    //displaySingleEmployee(employees, MAX_EMPLOYEES, employees[0].id);
   // removeEmployee(employees, &employeeCount, employees[0].id);
    //displaySingleEmployee(employees, MAX_EMPLOYEES, employees[0].id);


 void showMenu();
    return 0;
}