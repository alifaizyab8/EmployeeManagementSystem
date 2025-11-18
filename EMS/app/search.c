#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "../include/search.h"
#include "../include/extras.h"
#include "../include/employee.h"
#include "../include/login.h"
#include "../include/libraryfunc.h"



// Functions for Searching Menu 
/*
    1. searchByID
    2. searchByName
    3. searchByAge
    4. searchByDepartment
*/
// 


void searchbyName(struct Employee employees[], int size){
    system("cls");
    char fName[50];
    char secName[50];
    int found = 0;

    printf("Enter First Name: ");
    scanf("%49s", fName);
    while (getchar() != '\n');
    
    toLowercase_custom(fName);
    line();
    
    // First pass: check if first name exists
    for(int i = 0; i < size; i++){
        char tempFirst[50];
        strcpy_custom(tempFirst, employees[i].emp.firstname);
        toLowercase_custom(tempFirst);
        
        if(strcmp_custom(tempFirst, fName) == 0){
            found = 1;
            break;
        } 
    }

    if (found == 0) {
        printf("No employee found with the first name: %s\n", fName);
        line();
        
        return;
    }

    // Get second name
    printf("Enter Second Name (or press Enter to skip): ");
    
    // Read character by character to detect empty input
    int idx = 0;
    char ch;
    while((ch = getchar()) != '\n' && idx < 49){
        secName[idx++] = ch;
    }
    secName[idx] = '\0';
    
    if(strlen_custom(secName) > 0){
        toLowercase_custom(secName);
    }

    // Display results
    line();
    printf("\033[1;33m%-5s %-15s %-15s %-5s %-15s %-10s %-12s %-10s %-10s\033[0m\n",
             "ID", "First Name", "Last Name", "Age", "Position", "Salary", "Working Hrs", "Overtime", "Rating");
    line();
    
    int resultsFound = 0;
    for(int i = 0; i < size; i++){
        char tempFirst[50], tempLast[50];
        strcpy_custom(tempFirst, employees[i].emp.firstname);
        strcpy_custom(tempLast, employees[i].emp.lastname);
        
        toLowercase_custom(tempFirst);
        toLowercase_custom(tempLast);
        
        // Check first name match
        if(strcmp_custom(tempFirst, fName) == 0){
            // If second name provided, check it too
            if(strlen_custom(secName) == 0 || strcmp_custom(tempLast, secName) == 0){
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
                resultsFound++;
            }
        }
    }
    
    if(resultsFound == 0){
        printf("No employee found with the name: %s %s\n", fName, secName);
    }

    line();
    
}