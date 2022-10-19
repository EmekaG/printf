#include "main.h"

/**
 * for-width - calculates the width for space before printing
 * @format: formatted character string
 * @i: list of arguments to be printed
 * @lists: list of arguments
 *
 * Return: width
 */
int for_width(const char *format, int *i, va_list lists)
{
	int icopy;
	int width = 0;

	for (icopy = *i + 1; format[icopy] != '\0'; icopy++)
	{
		if (is_digit(format[icopy]))
		{
			width *= 10;
			width += format[icopy] - '0';
		}
		else if (format[icopy] == '*')
		{
			icopy++;
			width = va_arg(lists, int);
			break;
		}
		else
			break;
	}

	*i = icopy - 1;

	return (width);
}
