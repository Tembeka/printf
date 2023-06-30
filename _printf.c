#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;
	va_start(args, format);

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
