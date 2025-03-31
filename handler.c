#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * handler - Handles the format specifiers in _printf.
 * @format_char: The character to check after the '%'.
 * @args: The va_list of arguments.
 * @count: The total number of characters printed.
 *
 * Return: The number of characters printed.
 */
int handler(char format_char, va_list args, int count)
{
	if (format_char == 'c')
	{
		count += _putchar(va_arg(args, int));
	}
	else if (format_char == 's')
	{
		count = print_string(va_arg(args, char *), count);
	}
	else if (format_char == '%')
	{
		count += _putchar('%');
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int num = va_arg(args, int);
		count += print_int(num);
	}
	else
	{
		count += _putchar('%');
		count += _putchar(format_char);
	}

	return (count);
}
