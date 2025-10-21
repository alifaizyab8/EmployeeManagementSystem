#include "employee.h"
#include "login.h"
#include <stdio.h>

// Emolpyee Initialization function
// This function is to be called at the start of the program to initialize the employee array
// It can also be used to reset the employee records
void initializeEmployees(struct Employee employees[], int size)
{
    // Initialize each field to default values
    for (int i = 0; i < size; i++)
    {

        employees[i].id = 0;
        // \0 to indicate empty strings
        employees[i].emp.firstname[0] = '\0';
        employees[i].emp.lastname[0] = '\0';
        employees[i].age = 0;
        employees[i].position[0] = '\0';
        employees[i].salary = 0.0f;
        employees[i].hourly_rate = 0.0f;
        employees[i].worked_hours = 0;
        employees[i].over_time = 0;
        employees[i].last_paycheck = 0.0f;
        employees[i].performance_rating = 0.0f;
    }
}

// Add Employee function
// This function adds a new employee to the employees array
// This will return 1 if the employee is added successfully, otherwise returns 0
// It takes the employees array and a pointer to the current count of employees
int addEmployee(struct Employee employees[], int *count)
{
    line();
    printf("\033[1;34mAdding New Employee\033[0m\n");
    line();
    // Check for an empty slot
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {

        if (employees[i].id == 0) // Assuming id 0 means empty slot
        {
            // Intiialize new employee
            struct Employee newEmployee;
            printf("Enter Employee ID: \n");
            printf("Progress : |                     |\n");
            scanf("%d", &newEmployee.id);

            if (newEmployee.id <= 0)
            {
                printf("Invalid ID. Must be positive.\n");
                return 0;
            }
            // Basic Check to avoid duplicate IDs
            for (int j = 0; j < MAX_EMPLOYEES; j++)
            {
                if (employees[j].id == newEmployee.id)
                {
                    printf("Employee ID %d already exists. Cannot add duplicate IDs.\n", newEmployee.id);
                    return 0; // Duplicate ID found
                }
            }
            printf("Enter First Name: \n");
            printf("Progress : |====                 |\n");
            scanf("%s", newEmployee.emp.firstname);
            printf("Enter Last Name: \n");
            printf("Progress : |======               |\n");
            scanf("%s", newEmployee.emp.lastname);
            printf("Enter Age: \n");
            printf("Progress : |=========            |\n");
            scanf("%d", &newEmployee.age);
            printf("Enter Position: \n");
            printf("Progress : |============         |\n");
            scanf("%s", newEmployee.position);
            printf("Enter Salary: \n");
            printf("Progress : |================     |\n");
            scanf("%f", &newEmployee.salary);
            printf("Enter Hourly Rate: \n");
            printf("Progress : |==================== |\n");
            scanf("%f", &newEmployee.hourly_rate);
            printf("Progress : |=====================|\n");
            // Worked hours and overtime can be initialized to 0
            newEmployee.worked_hours = 0;
            newEmployee.over_time = 0;
            newEmployee.last_paycheck = 0.0f;
            // Performance rating can be initialized to 0.0 because it is evaluated as per the formula > (TBDL)
            newEmployee.performance_rating = 0.0f;
            // Add new employee to the array
            employees[i] = newEmployee;
            (*count)++;
            return 1; // Employee added successfully
        }
    }
    printf("No empty slot available to add new employee.\n");
    return 0; // No empty slot available
}

int removeEmployee(struct Employee employees[], int *count, int id)
{
    line();
    printf("\033[1;34mRemoving Employee\033[0m\n");
    line();
    // Search for the employee by ID
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == id)
        {
            // Reset the employee record to default values
            employees[i].id = 0;
            employees[i].emp.firstname[0] = '\0';
            employees[i].emp.lastname[0] = '\0';
            employees[i].age = 0;
            employees[i].position[0] = '\0';
            employees[i].salary = 0.0f;
            employees[i].hourly_rate = 0.0f;
            employees[i].worked_hours = 0;
            employees[i].over_time = 0;
            employees[i].last_paycheck = 0.0f;
            employees[i].performance_rating = 0.0f;
            (*count)--;
            return 1; // Employee removed successfully
        }
    }
    printf("Employee with ID %d not found.\n", id);
    return 0; // Employee not found
}

void displaySingleEmployee(const struct Employee employees[], int size, int id)
{
    int found = 0;
    line();
    printf("\n\033[1;34mEmployee Details\033[0m\n");
    line();

    for (int i = 0; i < size; i++)
    {
        if (employees[i].id == id)
        {
            // TABULAR FORMAT FOR BETTER READABILITY
            // Print table header
            printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-12s %-10s %-12s %-10s\033[0m\n",
                   "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Hourly Rate",
                   "Worked Hrs", "Overtime", "Last Pay", "Rating");
            line();

            // Print employee details in tabular format
            printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12.2f %-12d %-10d %-12.2f %-10.2f\n",
                   employees[i].id,
                   employees[i].emp.firstname,
                   employees[i].emp.lastname,
                   employees[i].age,
                   employees[i].position,
                   employees[i].salary,
                   employees[i].hourly_rate,
                   employees[i].worked_hours,
                   employees[i].over_time,
                   employees[i].last_paycheck,
                   employees[i].performance_rating);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\033[1;31mEmployee with ID %d not found.\033[0m\n", id);
    }

    line();
}
