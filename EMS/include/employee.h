#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#define MAX_EMPLOYEES 30


struct employee_name
{
    char firstname[20];
    char lastname[20];
};

struct Employee
{
    int id;
    struct employee_name emp;
    int age;
    char position[25];
    float salary;
    int working_hours;
    int over_time;
    float performance_rating;
    
};
int addEmployee(struct Employee employees[], int *count);

int removeEmployee(struct Employee employees[], int *count, int id);

void initializeEmployees(struct Employee employees[], int size);

void displaySingleEmployee(const struct Employee employees[], int size, int id);

#endif