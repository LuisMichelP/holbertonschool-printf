#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int print_string(char *str, int count);
int _printf(const char *format, ...);
int print_number_rec(unsigned int number);
int handler(char format_char, va_list args, int count);

#endif
