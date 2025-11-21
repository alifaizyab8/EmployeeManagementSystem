// Necessary header files included
#include <stdio.h>
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"

int main()
{
        // Display the login screen and authenticate the user
        // Program will continue only after successful login
        displayLoginScreen();

        // Initialize an array of Employee structures to store all employee data
        // MAX_EMPLOYEES ensures we don't exceed the allocated size
        struct Employee employees[MAX_EMPLOYEES];

         // Load employee records from storage (file/database)
        // Returns the number of employees successfully loaded
        int employeeCount = loadEmployee(employees, MAX_EMPLOYEES);

        // Display and handle the main menu options
        // Pass employee data and count so menu options can modify them
        showMenu(employees, &employeeCount);

        return 0; // End of program
}
/*
To run the program, compile all the .c files together and execute the resulting binary.
Example compilation command using gcc:
        >>>gcc main.c employee.c menuHandler.c login.c search.c libraryfunc.c
Then run the program:
        >>>./a.exe

*/