#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_digit - prints digits
 * @num: number argument
 *
 * Return: digit
 */
int print_digit(int num)
{
	int last_digit, remaining_digit, count;
	char *digits = "0123456789";

	if (num < 10)
		return print_char(digits[num]);

	last_digit = num % 10;
	remaining_digit = num / 10;

	count = print_digit(remaining_digit);
	return (count + print_digit(last_digit));
}
