#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - Prints a string, replacing NULL with "(null)".
 * @str: The string to print.
 * @count: The total number of characters printed.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str, int count)
{
    if (str == NULL)
        str = "(null)";
    
    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }

    return count;
}
