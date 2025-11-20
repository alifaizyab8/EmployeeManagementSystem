#include "../include/libraryfunc.h"

int strlen_custom(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int strcmp_custom(const char *str1, const char *str2)
{

    while (*str1 && (*str1 == *str2))

    {

        str1++;
        str2++;
    }

    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

int isalpha_custom(char c)
{

    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' '));
}

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