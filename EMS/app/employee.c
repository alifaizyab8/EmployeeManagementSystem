#include "../include/employee.h"
#include "../include/login.h"
#include "../include/menuHandler.h"
#include "../include/search.h"
#include "../include/libraryfunc.h"
#include <stdio.h>
#include <stdlib.h>
// Display a single employee by id
// reuse this logic if you ever need to print the whole list, just loop it
void displaySingleEmployee(const struct Employee employees[], int size, int id)
{
    // Bit that will turn high if employee with the passed id is found
    int found = 0;
    printf("\n\033[1;34mEmployee Details\033[0m\n\n"); // Blue header

    // id search loop, iterate through the whole array
    for (int i = 0; i < size; i++)
    {
        if (employees[i].id == id)
        {
            // Table Header - Yellow for visibility
            printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
                   "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
            line();

            // Employee Data Printing
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

    // If Employee not found then found bit remains zero
    if (!found)
    {
        // Red for error
        printf("\033[1;31mEmployee with ID %d not found.\033[0m\n", id);
    }

    printf("\n\n");
}

// Employee Initialization function
// Call this at start to wipe the struct or prepare for loading
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
// Returns 1 on success, 0 on failure
int addEmployee(struct Employee employees[], int *count)
{

    // Check if we can add more employees
    if (*count >= MAX_EMPLOYEES)
    {
        printf("\033[1;31mCannot add more employees. Maximum limit reached.\033[0m\n");
        return 0;
    }

    // Define single Employee struct
    struct Employee newEmp;
    int validID_Check = 0;
    char term; // used to catch the newline after numbers to prevent glitches

    line();
    printf("\033[1;34mEmployee Addition Window\033[0m\n"); // Blue Header
    line();

    // Populate the struct with input validation at each step
    // --- ID CHECK (STRICT) ---
    while (1)
    {
        printf("Enter Employee ID (1 < ID < 1000): ");
        // We read the Int AND the char after it.
        // if user types "111" and enter, term becomes '\n'.
        // if user types "111efu", term becomes 'a'.
        if (scanf("%d%c", &newEmp.id, &term) != 2 || term != '\n')
        {
            printf("Invalid ID. Please enter a numeric value only.\n");
            // clear scanf buffer to prevent infinite loops
            while (getchar() != '\n')
                ;
            continue;
        }

        if (newEmp.id <= 0 || newEmp.id > 1000)
        {
            printf("Invalid ID range. Please enter 1 < ID < 1000\n");
            continue;
        }

        // check for duplicates
        validID_Check = 1;
        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            if (employees[i].id == newEmp.id)
            {
                // Red for error
                printf("\033[1;31m ERROR : Employee with ID %d already Exists\033[0m\n", newEmp.id);
                validID_Check = 0;
                break;
            }
        }
        if (validID_Check)
            break;
    }

    // No extra getchar() needed here

    // --- FIRST NAME ---
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

        // Check for numbers or symbols in name
        int invalidInputBit = 1;
        for (int i = 0; newEmp.emp.firstname[i] != '\0'; i++)
        {
            if (!isalpha_custom(newEmp.emp.firstname[i]) && newEmp.emp.firstname[i] != ' ')
            {
                invalidInputBit = 0;
                break;
            }
        }
        if (invalidInputBit)
        {
            NameFormat_custom(newEmp.emp.firstname);
            break;
        }

        printf("Name can only contain letters and spaces.\n");
        while (getchar() != '\n')
            ; // clear garbage before retrying
    }

    while (getchar() != '\n')
        ; // clear input buffer after string read

    // --- LAST NAME ---
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
            if (!isalpha_custom(newEmp.emp.lastname[i]) && newEmp.emp.lastname[i] != ' ')
            {
                invalidInputBit = 0;
                break;
            }
        }
        if (invalidInputBit)
            NameFormat_custom(newEmp.emp.lastname);
        break;

        printf("Name can only contain letters and spaces.\n");
        while (getchar() != '\n')
            ;
    }

    while (getchar() != '\n')
        ; // clear buffer

    // --- AGE (STRICT) ---
    while (1)
    {
        printf("Enter Age (18-70): ");
        // Strict check to catch things like "25yrs"
        if (scanf("%d%c", &newEmp.age, &term) != 2 || term != '\n')
        {
            printf("Invalid age. Please enter a number only.\n");
            while (getchar() != '\n')
                ; // clear garbage
            continue;
        }

        if (newEmp.age < 18 || newEmp.age > 70)
        {
            printf("Age must be between 18 and 70.\n");
            continue;
        }
        break;
    }

    // --- POSITION ---
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
        if (strlen_custom(newEmp.position) > 0)
            NameFormat_custom(newEmp.position);
        break;

        printf("Position cannot be empty.\n");
    }

    while (getchar() != '\n')
        ;

    // --- SALARY (STRICT) ---
    while (1)
    {
        printf("Enter Salary (1000-1000000): ");
        // Check for float and clean newline
        if (scanf("%f%c", &newEmp.salary, &term) != 2 || term != '\n')
        {
            printf("Invalid salary. Please enter a numeric value.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (newEmp.salary < 1000 || newEmp.salary > 1000000)
        {
            printf("Salary must be between 1000 and 1,000,000.\n");
            continue;
        }
        break;
    }

    // --- WORKING HOURS (STRICT) ---
    while (1)
    {
        printf("Enter Working Hours (0-40): ");
        if (scanf("%d%c", &newEmp.working_hours, &term) != 2 || term != '\n')
        {
            printf("Invalid input. Numbers only.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (newEmp.working_hours < 0 || newEmp.working_hours > 40)
        {
            printf("Working hours must be between 0 and 40.\n");
            continue;
        }
        break;
    }

    // new employees start with 0 overtime and 0 rating
    newEmp.over_time = 0;
    newEmp.performance_rating = 0.0;

    // Find the first empty slot to save the employee
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

    // Save changes immediately
    int changesSaved = saveEmployeesToFile(employees, MAX_EMPLOYEES);

    // Green for success
    printf("\033[0;32m%d Records updated.\n\033[0m", changesSaved);
    return 1;
}

int removeEmployee(struct Employee employees[], int *count, int id)
{
    line();
    printf("\033[1;34mRemoving Employee\033[0m\n"); // Blue Header
    line();

    printf("\n\n\nThis Employee is being removed...\n\n");
    displaySingleEmployee(employees, MAX_EMPLOYEES, id);
    printf("\n\n\n");

    // Search for the employee by ID
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == id)
        {
            printf("Are you sure you want to remove this employee (ID : %d) ? (y/n): ", id);
            char confirm;
            scanf(" %c", &confirm); // space before %c eats whitespace

            if (confirm != 'y' && confirm != 'Y')
            {
                printf("Operation cancelled.\n");
                return 0;
            }

            // Reset the employee record to default values manually
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

            // Green for success (Consistent with Add function now)
            printf("\033[0;32m%d Records updated.\n\033[0m", changesSaved);
            return 1;
        }
    }

    // Red for error
    printf("\033[1;31mEmployee with ID %d not found.\033[0m\n", id);
    line();
    return 0;
}

int loadEmployee(struct Employee employees[], int size)
{
    // Wipe array clean first
    initializeEmployees(employees, size);

    FILE *fptr = fopen("../data/employee.txt", "r");
    if (fptr == NULL)
    {
        printf("No existing employee data found. Starting fresh.\n");
        return 0;
    }

    int employeeCount = 0;
    // reading CSV format
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
    // const is used so we don't accidentally mess up data while saving
    FILE *fptr = fopen("../data/employee.txt", "w");
    if (fptr == NULL)
    {
        printf("\033[1;31mError opening file for saving employees.\033[0m\n");
        return 0;
    }

    int savedCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (employees[i].id != 0) // only save valid slots
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
void displayAllEmployees(const struct Employee employees[], int employeeCount)
{
    if (employeeCount == 0)
    {
        printf("\033[1;31mNo employees found to display.\033[0m\n");
        return;
    }

    line();
    printf("\n\033[1;34mAll Employees List\033[0m\n");

    printf("\033[1;33m%-5s %-15s %-15s %-5s %-20s %-15s %-12s %-10s %-10s\033[0m\n",
           "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
    line();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id != 0)
        {
            printf("%-5d %-15s %-15s %-5d %-22s %-20.1f %-12d %-10d %-10.2f\n",
                   employees[i].id,
                   employees[i].emp.firstname,
                   employees[i].emp.lastname,
                   employees[i].age,
                   employees[i].position,
                   employees[i].salary,
                   employees[i].working_hours,
                   employees[i].over_time,
                   employees[i].performance_rating);
            printf("\n");
        }
    }

    line();
}

// Add this prototype to your employee.h as well:
// int editEmployee(struct Employee employees[], int count, int id);

int editEmployee(struct Employee employees[], int count, int id)
{
    int index = 0;
    // 1. Find the employee index
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == 0)
    {
        printf("\033[1;31mEmployee with ID %d not found.\033[0m\n", id);
        return 0;
    }

    int choice;
    char term; // For strict input validation

    while (1)
    {
        system("cls");
        line();
        printf("\033[1;34m        EDITING EMPLOYEE--ID:  %d        \033[0m\n", id);
        line();

        // Show current state
        printf("1. First Name         : %s\n", employees[index].emp.firstname);
        printf("2. Last Name          : %s\n", employees[index].emp.lastname);
        printf("3. Age                : %d\n", employees[index].age);
        printf("4. Position           : %s\n", employees[index].position);
        printf("5. Salary             : %.2f\n", employees[index].salary);
        printf("6. Working Hours      : %d\n", employees[index].working_hours);
        printf("7. Overtime           : %d\n", employees[index].over_time);
        printf("8. Performance Rating : %.2f\n", employees[index].performance_rating);
        printf("\033[1;32m9. SAVE & RETURN\033[0m\n");
        printf("\033[1;31m10. CANCEL CHANGES\033[0m\n");
        line();
        printf("Select field to edit: ");

        // Strict Menu Input
        if (scanf("%d%c", &choice, &term) != 2 || term != '\n')
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            printf("Press Enter...");
            getchar();
            continue;
        }

        // --- EDIT LOGIC START ---

        if (choice == 9)
            break; // Save and exit (to be called after all the required fields are updated)
        if (choice == 10)
            return 0; // Cancel (No save)

        switch (choice)
        {
        case 1: // Edit First Name
            while (1)
            {
                printf("\nUpdate First Name (Current: %s): ", employees[index].emp.firstname);
                if (scanf("%49[^\n]", employees[index].emp.firstname) != 1)
                {
                    while (getchar() != '\n')
                        ; // Buffer
                    continue;
                }
                // Validation
                int invalid = 0;
                for (int k = 0; employees[index].emp.firstname[k] != '\0'; k++)
                {
                    if (!isalpha_custom(employees[index].emp.firstname[k]) && employees[index].emp.firstname[k] != ' ')
                    {
                        invalid = 1;
                        break;
                    }
                }
                if (!invalid)
                    NameFormat_custom(employees[index].emp.firstname);
                break;
                printf("Name can only contain letters and spaces.\n");
                while (getchar() != '\n')
                    ;
            }
            while (getchar() != '\n')
                ; // Clear buffer
            break;

        case 2: // Edit Last Name
            while (1)
            {
                printf("\nUpdate Last Name (Current: %s): ", employees[index].emp.lastname);
                if (scanf("%49[^\n]", employees[index].emp.lastname) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                int invalid = 0;
                for (int k = 0; employees[index].emp.lastname[k] != '\0'; k++)
                {
                    if (!isalpha_custom(employees[index].emp.lastname[k]) && employees[index].emp.lastname[k] != ' ')
                    {
                        invalid = 1;
                        break;
                    }
                }
                if (!invalid)
                    NameFormat_custom(employees[index].emp.lastname);
                break;
                printf("Name can only contain letters and spaces.\n");
                while (getchar() != '\n')
                    ;
            }
            while (getchar() != '\n')
                ;
            break;

        case 3: // Edit Age
            while (1)
            {
                printf("\nUpdate Age (Current: %d): ", employees[index].age);
                // same scanf type of input validation
                if (scanf("%d%c", &employees[index].age, &term) != 2 || term != '\n')
                {
                    printf("Invalid input. Number only.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (employees[index].age < 18 || employees[index].age > 70)
                {
                    printf("Age must be 18-70.\n");
                    continue;
                }
                break;
            }
            break;

        case 4: // Edit Position
            while (1)
            {
                printf("\nUpdate Position (Current: %s): ", employees[index].position);
                if (scanf("%49[^\n]", employees[index].position) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (strlen_custom(employees[index].position) > 0)
                    break;
                printf("Position cannot be empty.\n");
            }
            NameFormat_custom(employees[index].position);

            while (getchar() != '\n')
                ;
            break;

        case 5: // Edit Salary
            while (1)
            {
                printf("\nUpdate Salary (Current: %.2f): ", employees[index].salary);
                if (scanf("%f%c", &employees[index].salary, &term) != 2 || term != '\n')
                {
                    printf("Invalid input. Numeric value only.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (employees[index].salary < 1000 || employees[index].salary > 1000000)
                {
                    printf("Range: 1000 - 1,000,000.\n");
                    continue;
                }
                break;
            }
            break;

        case 6: // Edit Hours
            while (1)
            {
                printf("\nUpdate Working Hours (Current: %d): ", employees[index].working_hours);
                if (scanf("%d%c", &employees[index].working_hours, &term) != 2 || term != '\n')
                {
                    printf("Invalid input. Number only.\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (employees[index].working_hours < 0 || employees[index].working_hours > 40)
                {
                    printf("Range: 0 - 40.\n");
                    continue;
                }
                break;
            }
            break;

        default:
            printf("\033[1;31mInvalid choice.\033[0m\n");
            printf("Press Enter...");
            getchar();
        }
    }

    // Save to file only when  choice is  7 i.e break form while (1) lop
    int changesSaved = saveEmployeesToFile(employees, MAX_EMPLOYEES);
    printf("\033[0;32m%d Records updated. Changes saved.\n\033[0m", changesSaved);
    return 1;
}
void highLYPaidEmployee(const struct Employee employees[], int size)
{
    int found = 0;

    printf("\n\033[1;34m--- Highly Paid Employees (Salary >= 100000) ---\033[0m\n\n");

    printf("\033[1;33m%-5s %-15s %-15s %-5s %-20s %-15s %-12s %-10s %-10s\033[0m\n",
           "ID", "First Name", "Last Name", "Age",
           "Position", "Salary", "Work Hrs", "Overtime", "Rating");

    for (int i = 0; i < size; i++)
    {
        if (employees[i].salary >= 100000)
        {
            printf("\033[1;35m%-5d %-15s %-15s %-5d %-22s %-20f %-12d %-10d %-10.2f\033[0m\n",
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
            printf("\n");
        }
    }

    if (!found)
    {
        printf("\033[1;31mNo employees found with salary >= 100000.\033[0m\n");
    }

    printf("\n");
}

// END OF ADD EMPLOYEE DEVELOPMENT 