#include "main.h"

/**
* get_flags - Calculates active flags
* @format: Formatted string
* @i: take a parameter.
* Return: Flags:
*/

int get_flags(const char *format, int *i)
{
	int a, ci;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
		F_SPACE, 0};

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[ci] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		if (FLAGS_CH[a] == 0)
			break;
	}
	*i = ci - 1;
	return (flags);
}
