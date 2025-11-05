#include "../include/employee.h"
#include "../include/login.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define EMPLOYEE_FILE "../data/employee.txt"

// Display a single employee by id
// same functionality can be implemented to list all the employees
void displaySingleEmployee(const struct Employee employees[], int size, int id)
{
    int found = 0;
    line();
    printf("\n\033[1;34mEmployee Details\033[0m\n");

    for (int i = 0; i < size; i++)
    {
        if (employees[i].id == id)
        {
            // Table Header
            printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                   "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
            line();

            // Employee Data
            printf("%-5d %-15s %-15s %-5d %-15s %-10.2f %-12d %-10d %-10.2f\n",
                   employees[i].id,
                   employees[i].emp.firstname,
                   employees[i].emp.lastname,
                   employees[i].age,
                   employees[i].position,
                   employees[i].salary,
                   employees[i].working_hours,
                   employees[i].over_time,
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
        employees[i].working_hours = 0;
        employees[i].over_time = 0;
        employees[i].performance_rating = 0.0f;
    }
}

// Add Employee function
// This function adds a new employee to the employees array
// This will return 1 if the employee is added successfully, otherwise returns 0
// It takes the employees array and a pointer to the current count of employees

int addEmployee(struct Employee employees[], int *count)
{

    // Check if we can add more employees
    if (*count >= MAX_EMPLOYEES)
    {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return 0;
    }

    struct Employee newEmp;
    int validID_Check = 0;
    line();
    printf("\033[1;34mEmployee Addition Window\033[0m\n");
    line();

    // ID check and input
    while (1)
    {
        printf("Enter Employee ID (1 > ID > 1000): ");
        if (scanf("%d", &newEmp.id) != 1 || newEmp.id <= 0 || newEmp.id > 10000)
        {
            printf("Invalid ID. Please enter a valid number as 1 > ID > 1000\n");
            // clear scanf buffer
            while (getchar() != '\n')
                ;
            continue;
        }

        // check for duplicates
        validID_Check = 1;
        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            if (employees[i].id == newEmp.id)
            {
                printf("Error: Employee ID %d already exists.\n", newEmp.id);
                validID_Check = 0;
                break;
            }
        }
        if (validID_Check)
            break;
    }

    while (getchar() != '\n')
        ; // clear input buffer

    // First name input and validation
    while (1)
    {
        printf("Enter First Name: ");
        if (scanf("%49[^\n]", newEmp.emp.firstname) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        int invalidInputBit = 1;
        for (int i = 0; newEmp.emp.firstname[i] != '\0'; i++)
        {
            if (!isalpha(newEmp.emp.firstname[i]) && newEmp.emp.firstname[i] != ' ')
            {
                invalidInputBit = 0;
                break;
            }
        }
        if (invalidInputBit)
            break;
        printf("Name can only contain letters and spaces.\n");
        while (getchar() != '\n')
            ;
    }

    while (getchar() != '\n')
        ; // clear input buffer

    // Last name
    while (1)
    {
        printf("Enter Last Name: ");
        if (scanf("%49[^\n]", newEmp.emp.lastname) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        int invalidInputBit = 1;
        for (int i = 0; newEmp.emp.lastname[i] != '\0'; i++)
        {
            if (!isalpha(newEmp.emp.lastname[i]) && newEmp.emp.lastname[i] != ' ')
            {
                invalidInputBit = 0;
                break;
            }
        }
        if (invalidInputBit)
            break;
        printf("Name can only contain letters and spaces.\n");
        while (getchar() != '\n')
            ;
    }
    // clear buffer
    while (getchar() != '\n')
        ;

    // Age
    while (1)
    {
        printf("Enter Age (18-70): ");
        if (scanf("%d", &newEmp.age) != 1 || newEmp.age < 18 || newEmp.age > 70)
        {
            printf("Invalid age. Try again.\n");
            while (getchar() != '\n')
                ; // clear scanf buffer
            continue;
        }
        break;
    }

    while (getchar() != '\n')
        ;

    // Position
    while (1)
    {
        printf("Enter Position: ");
        if (scanf("%49[^\n]", newEmp.position) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        if (strlen(newEmp.position) > 0)
            break;
        printf("Position cannot be empty.\n");
        while (getchar() != '\n')
            ;
    }

    while (getchar() != '\n')
        ;
    // clear buffer
    while (getchar() != '\n')
        ;
    // Salary
    while (1)
    {
        printf("Enter Salary (1000–1000000): ");
        if (scanf("%f", &newEmp.salary) != 1 || newEmp.salary < 1000 || newEmp.salary > 1000000)
        {
            printf("Invalid salary. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        break;
    }
    // clear buffer
    while (getchar() != '\n')
        ;

    // Working hours
    while (1)
    {
        printf("Enter Working Hours (0-40): ");
        if (scanf("%d", &newEmp.working_hours) != 1 || newEmp.working_hours < 0 || newEmp.working_hours > 40)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        break;
    }

    newEmp.over_time = 0;
    newEmp.performance_rating = 0.0;

    // save to first empty slot
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == 0)
        {
            employees[i] = newEmp;
            (*count)++;
            printf("\nEmployee added successfully!\n");
            break;
        }
    }
    int changesSaved = saveEmployeesToFile(employees, MAX_EMPLOYEES);
    printf("%d Records updated.\n", changesSaved);
    return 1;
}

int removeEmployee(struct Employee employees[], int *count, int id)
{
    line();
    printf("\033[1;34mRemoving Employee\033[0m\n");
    line();
    printf("\n\n\nThis Employee is being removed...\n\n");
    displaySingleEmployee(employees, MAX_EMPLOYEES, id);
    printf("\n\n\n");
    // Search for the employee by ID
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == id)
        {
            printf("Are you sure you want to remove this employee ID : %d? (y/n): ", id);
            char confirm;
            scanf(" %c", &confirm);
            if (confirm != 'y' && confirm != 'Y')
            {
                printf("Operation cancelled.\n");
                return 0;
            }

            // Reset the employee record to default values
            employees[i].id = 0;
            employees[i].emp.firstname[0] = '\0';
            employees[i].emp.lastname[0] = '\0';
            employees[i].age = 0;
            employees[i].position[0] = '\0';
            employees[i].salary = 0.0f;
            employees[i].working_hours = 0;
            employees[i].over_time = 0;
            employees[i].performance_rating = 0.0f;
            (*count)--;
            int changesSaved = saveEmployeesToFile(employees, MAX_EMPLOYEES);
            printf("%d Records updated.\n", changesSaved);
            return 1; // Employee removed successfully
        }
    }
    printf("Employee with ID %d not found.\n", id);
    return 0; // Employee not found

    line();
}

int loadEmployee(struct Employee employees[], int size)
{
    initializeEmployees(employees, size);

    FILE *fptr = fopen("EMPLOYEE_FILE", "r");
    if (fptr == NULL)
    {
        printf("No existing employee data found. Starting fresh.\n");
        return 0;
    }

    int employeeCount = 0;
    while (fscanf(fptr, "%d,%49[^,],%49[^,],%d,%49[^,],%f,%d,%d,%f\n",
                  &employees[employeeCount].id,
                  employees[employeeCount].emp.firstname,
                  employees[employeeCount].emp.lastname,
                  &employees[employeeCount].age,
                  employees[employeeCount].position,
                  &employees[employeeCount].salary,
                  &employees[employeeCount].working_hours,
                  &employees[employeeCount].over_time,
                  &employees[employeeCount].performance_rating) == 9)
    {
        employeeCount++;
        if (employeeCount >= size)
        {
            printf("Maximum employee capacity reached while loading data.\n");
            break;
        }
    }

    fclose(fptr);

    if (employeeCount == 0)
        printf("No employees found in file.\n");
    else
        printf("%d employees loaded from file.\n", employeeCount);

    return employeeCount;
}

int saveEmployeesToFile(const struct Employee employees[], int size)
{
    // const is used to prevent modification of employee data
    FILE *fptr = fopen("EMPLOYEE_FILE", "w");
    if (fptr == NULL)
    {
        printf("Error opening file for saving employees.\n");
        return 0;
    }

    int savedCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (employees[i].id != 0) // only save valid employees
        {
            fprintf(fptr, "%d,%s,%s,%d,%s,%.2f,%d,%d,%.2f\n",
                    employees[i].id,
                    employees[i].emp.firstname,
                    employees[i].emp.lastname,
                    employees[i].age,
                    employees[i].position,
                    employees[i].salary,
                    employees[i].working_hours,
                    employees[i].over_time,
                    employees[i].performance_rating);
            savedCount++;
        }
    }

    fclose(fptr);
    printf("Changes saved successfully.\n");
    return savedCount;
}
