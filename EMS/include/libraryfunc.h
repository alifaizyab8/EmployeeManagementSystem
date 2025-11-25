#ifndef LIBRARYFUNC_H
#define LIBRARYFUNC_H

int strlen_custom(const char *str);                    // Get length of a string
int strcmp_custom(const char *str1, const char *str2); // Compare two strings
int isalpha_custom(char c);                            // Check if character is alphabet letter or space
void toLowercase_custom(char *str);                    // Convert string to lowercase
void NameFormat_custom(char *str);                     // Format name string (capitalize first letters and remove leading spaces)
void strcpy_custom(char *dest, const char *src);       // copy string from src to dest
int isDigitString_custom(const char *str);             // Check if string contains only digit characters (0-9)
int atoi_custom(const char *str);                      // Convert string to integer

#endif