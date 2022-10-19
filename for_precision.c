#include "main.h"

/**
 * for_precision - calculates the prcision for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @lists; list of arguments
 *
 * Return: precision
 */
int for_precision(const char *format, int *i, va_list lists)
{
	int icopy = *i + 1;
	int precision = -1;

	if (format[icopy]!= '.')
		return (precision);

	precision = 0;

	for (icopy += 1; format[icopy] != '\0'; icopy++)
	{
		if (is_digit(format[icopy]))
		{
			precision *= 10;
			precision += format[icopy] - '0';
		}
		else if (format[icopy] == '*')
		{
			icopy++;
			precision = va_arg(lists, int);
			break;
		}
		else
			break;
	}

	*i = icopy - 1;

	return (precision);
}
