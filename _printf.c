#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Entry point
 * @format: string of printf
 * @...: the arguments of printf
 * Return: the length of the entered string 
 */

int _printf(const char *format, ...)
{
	int i, j, len = 0;
	va_list args;
	va_start (args, format);

	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == 'c')
			{
				char ch = va_arg(args, int);
				putchar(ch);
				i++;
				len++;
			}
			else if (*(format + i + 1) == 's')
			{
				char *s = va_arg(args, char *);
				for (j = 0; *(s + j) != '\0'; j++)
				{
					putchar(s[j]);
					len++;
					i++;
				}
			}
			else if (*(format + i + 1) == '%')
			{
				putchar('%');
				len++;
			}
			else if (*(format + i + 1) == 'd')
			{
				int dou = va_arg(args, int);
				printf("%d", dou);
				i++;
				len++;
			}
			else if (*(format + i + 1) == 'o')
			{
				unsigned int oc = va_arg(args, unsigned int);
				printf("%o", oc);
				i++;
			}
			else if (*(format + i + 1) == 'u')
			{
				unsigned un = va_arg(args, unsigned);
				printf("%u", un);
				i++;
			}
			else if (*(format + i + 1) == 'x')
			{
				unsigned int hex1 = va_arg(args, unsigned int);
				printf("%x", hex1);
				i++;
			}
			else if (*(format + i + 1) == 'X')
			{
				unsigned int hex2 = va_arg(args, unsigned int);
				printf("%X", hex2);
				i++;
			}
		}
		else if (*(format + i) != '%')
		{
			putchar(*(format + i));
			len++;
		}
	}

	va_end(args);

	return (i - 1);
}
