#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int check_format(char specifier, va_list ap);

int print_char(int c);

int print_digit(int num);

int print_str(char *str);

int print_float(float num);

#endif
