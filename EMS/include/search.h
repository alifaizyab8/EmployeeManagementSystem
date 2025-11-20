//Search Menu Funcitons header file
#ifndef SEARCH_H
#define SEARCH_H
#include "employee.h"

void searchbyID(struct Employee employees[], int size);
void searchbyName(struct Employee employees[], int size);
void searchbyAge(struct Employee employees[], int size);
void searchbyposition(struct Employee employees[], int size);

#endif