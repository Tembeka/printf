#include "main.h"

/**
* get_size - Calc size to cast the arg
* @format: Formatted string
* @i: List of arguments to be printed.
*
* Return: Precision.
*/

int get_size(const char *format, int *i)
{
	int ci = *i + 1;
	int size = 0;

	if (format[ci] == 'l')
		size = S_LONG;
	else if (format[ci] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = ci - 1;
	else
		*i = ci;
	return (size);
}
