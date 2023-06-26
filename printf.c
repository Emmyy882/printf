#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * check_format - checks the format of an argument
 * @specifier: the format specifier
 * @ap: argument pointer
 *
 * Return: result
 */
int check_format(char specifier, va_list ap)
{
	int result;

	result = 0;
	if (specifier == 'c')
		result += print_char(va_arg(ap, int));
	else if (specifier == 'd')
		result += print_digit(va_arg(ap, int));
	else if (specifier == 's')
		result += print_str(va_arg(ap, char *));
	else if (specifier == 'f')
		result += print_float(va_arg(ap, double));
	else if (specifier == '%')
		result += print_char(va_arg(ap, char));
	else if (specifier == 'u')
		result += print_digit(va_arg(ap,int));
	else if (specifier == '%')
		result += print_char(va_arg(ap, int));
	else if (specifier == 'p')
		result += print_str(va_arg(ap, char *));
	else
		result += write(1, &f_specifier, 1);

	return (result);
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

	va_start(ap, format);
	int count;

	count = 0;
	while (*format != '\0')
	{
		if (format == '%')
			count += check_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}

	va_end(ap);
	return (count);
}
