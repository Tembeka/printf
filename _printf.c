#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
* _printf - a function that produces output according to a format
* @format: format.
* Return: number of characters printed.
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*ptr == 's')
			{
				const char *s = va_arg(args, const char *);

				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*ptr == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar(*ptr);
				count++;
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
		ptr++;
	}
	va_end(args);
	return (count);
}
