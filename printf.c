#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**                                              * print_char - prints character
 * @c: character argument                        * Return: character
 */
int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints string
 * @str: string argument
 *
 * Return: count
 */
int print_str(char *str)
{
	int count;

	if (*str ==0x00)
		return (0x00);
	while (*str != '\0')
	{
		count = print_char((int)*str);
		str++;
		count++;
	}
	return (count);
}


/**
 * print_digit - prints digits
 * @num: number argument
 * Return: digit
 */
int print_digit(int num)
{
        int count;
	char *digits = "0123456789";
	
	count = 0;
	if (num < 10)
		return print_char(digits[num]);

	count = print_digit(num / 10);

	return (count + print_digit(num % 10));
}



/**
 * check_format - checks the format of an argument
 * @specifier: the format specifier
 * @ap: argument pointer
 *
 * Return: result
 */
int check_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 'd')
		count += print_digit(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	/*else if (specifier == 'f')
	//	count += print_float(va_arg(ap, double));
	//else if (specifier == 'u')
		count += print_digit(va_arg(ap,int));*/
	else if (specifier == '%')
		count += print_char(va_arg(ap, int));
	/*else if (specifier == 'p')
		count += print_str(va_arg(ap, char *));*/
	else
		return (0);

	return (count);
}


/**
 * _printf - prints arguents just like printf
 * @format: the known passed argument
 *
 * Return: expected format of result
 */
int _printf(const char *format, ...)
{
	va_list ap;

	int count;
	va_start(ap, format);

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += check_format(*(++format), ap);
		else
			write(1, format, 1);
		format++;
	}

	va_end(ap);
	return (count);
}
