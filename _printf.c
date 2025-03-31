#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Custom implementation of printf
 * @format: Format string containing directives
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c') /* Character */
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (format[i] == 's') /* String */
            {
                char *str = va_arg(args, char *);
                int j = 0;

                if (str == NULL)
                    str = "(null)";

                while (str[j] != '\0')
                {
                    _putchar(str[j]);
                    count++;
                    j++;
                }
            }
            else if (format[i] == '%') /* Percent Sign */
            {
                _putchar('%');
                count++;
            }
            else /* Invalid Specifier */
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else /* Normal Character */
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
