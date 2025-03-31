#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int print_string(char *str, int count);
int _printf(const char *format, ...);
int handler(char format_char, va_list args, int count);

#endif
