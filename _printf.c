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
            if (format[i] == 'c')
            {
                _putchar(va_arg(args, int));
                count++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    _putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
