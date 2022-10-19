#include "main.h"

/**
 * for_size - calculates the size in bytes of arguments
 * @format: formatted character string
 * @i: list of arguments to be printed
 *
 * Return: size
 */
int for_size(const char *format, int *i)
{
	int icopy = *i + 1;
	int size = 0;

	if (format[icopy] == 'l')
		size = S_LONG;
	else if (format[icopy] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = icopy - 1;
	else
		*i = icopy;

	return (size);
}
