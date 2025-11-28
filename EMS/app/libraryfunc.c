/* This file has fucntions that are required in our Project (EMS)
   Without this file we have to include other headers to use these functions*/
#include "../include/libraryfunc.h"
#include <stdio.h>
#include<stdlib.h>

// like function in string.h but custom made.
// This function returns length of string
int strlen_custom(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

// like function in string.h but custom made.
// This function compares two strings and returns 0 if they are equal,
// a negative value if str1 < str2, and a positive value if str1 > str2
int strcmp_custom(const char *str1, const char *str2)
{

    while (*str1 && (*str1 == *str2))

    {

        str1++;
        str2++;
    }

    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

// like function in ctype.h but custom made.
// This function checks if a character is an alphabet letter (A-Z, a-z) or space
// Returns 1 if true, 0 otherwise
int isalpha_custom(char c)
{

    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' '));
}

// like function in ctype.h but custom made.
// This function converts a string to lowercase
// e.g "ALI FAIZYAB" becomes "ali faizyab"
void toLowercase_custom(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

// This function formats the name string to have the first letter of each word capitalized
//  and the rest in lowercase, also removes leading spaces
//  e.g "aLi faIzyab kHAN" becomes "Ali Faizyab Khan"
void NameFormat_custom(char *str)
{
    toLowercase_custom(str);
    while (1)
    {

        if (str[0] == ' ')
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                str[i] = str[i + 1];
            }
        }
        else
        {
            break;
        }
    }

    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - ('a' - 'A');
    }

    for (int i = 1; str[i] != '\0'; i++)

    {
        if (str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

// like function in string.h but custom made.
// This function copies the source string to the destination string assumed to have enough space
// e.g src: "Hello", dest: "" => dest: "Hello"
void strcpy_custom(char *dest, const char *src)
{

    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// This function checks if a string contains only digit characters (0-9)
//  Returns 1 if all characters are digits, 0 otherwise
int isDigitString_custom(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 0; // not a digit
        i++;
    }
    return 1; // all digits
}

// This function converts a numeric string to an integer
//  e.g "123" becomes 123
int atoi_custom(const char *str)
{
    int result = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

// screen clearing using ANSI for OS Support

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
    \033 is ESC key
    [2J is screen clear command
    [H is cursor shift command

*/