// Search Menu Funcitons header file
#ifndef SEARCH_H
#define SEARCH_H
#include "employee.h"

// Function prototypes for search functionalities

void searchbyID(struct Employee employees[], int size);       // Search employee by ID
void searchbyName(struct Employee employees[], int size);     // Search employee by Name
void searchbyAge(struct Employee employees[], int size);      // Search employee by Age
void searchbyposition(struct Employee employees[], int size); // Search employee by Position

#endif