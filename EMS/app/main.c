#include <stdio.h>
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/extras.h"
#include "../include/search.h"
int main()
{

    // Very Important Lines below
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = loadEmployee(employees, MAX_EMPLOYEES);

    showMenu(employees, &employeeCount);

    return 0;
}