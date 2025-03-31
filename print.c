#include "main.h"

/**
  * print_number_rec - prints all int as char
  * @number: int, number to print passed to function
  * Return: number of char printed
  */
int print_number_rec(unsigned int integer)
{
	int count = 0;

	if (integer / 10 > 0)
	{
	count += print_number_rec(integer / 10);
	}
	count += _putchar('0' + (integer % 10));
	return (count);
}
