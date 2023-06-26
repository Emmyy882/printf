#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_char - prints character
 * @c: character argument
 * Return: character
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
{                                                       int result;

        count = 0;
        while (str != '\0')
        {
                result += print_char((int)*str);
                s++;
                count++;
        }
        return (count);
}
