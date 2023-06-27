#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string
* @i: List of args printed.
* @list: list of args.
*
* Return: Precision.
*/

int get_precision(const char *format, int *i, va_list list)
{
	int ci = *i + 1;
	int precision = -1;

	if (format[ci] != '.')
		return (precision);
	precision = 0;

	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			precision *= 10;
			precision += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = ci - 1;
	return (precision);
}
