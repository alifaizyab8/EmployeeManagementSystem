#include <stdio.h>
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"
int main()
{
        displayLoginScreen();
        // Very Important Lines below
        struct Employee employees[MAX_EMPLOYEES];
        int employeeCount = loadEmployee(employees, MAX_EMPLOYEES);

        showMenu(employees, &employeeCount);

        return 0;
}
/*
To run the program, compile all the .c files together and execute the resulting binary.
Example compilation command using gcc:
        >>>gcc main.c employee.c menuHandler.c login.c search.c libraryfunc.c
Then run the program:
        >>>./a.exe

*/