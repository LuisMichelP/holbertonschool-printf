#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * print_int - Helper function to print an integer.
 * @n: Integer to print.
 * 
 * Return: Number of characters printed.
 */

int print_int(int n)
{
    int count = 0;
    if (n == 0)
    {
        count += _putchar('0');
        return count;
    }

    if (n < 0)
    {
        count += _putchar('-');
        n = -n; // Make the number positive for printing
    }

    // Calculate and print each digit
    char buffer[10];
    int i = 0;
    
    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    // Print the digits in reverse order
    for (--i; i >= 0; i--)
    {
        count += _putchar(buffer[i]);
    }
    
    return count;
}