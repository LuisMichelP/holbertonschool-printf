#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string containing the characters and specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);

            if (format[i] == 'c')
            {
                count += _putchar(va_arg(args, int));
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                
                /* Directly use _strlen_recursion in the loop */
                for (int j = 0; j < _strlen_recursion(str); j++)
                {
                    _putchar(str[j]);
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}