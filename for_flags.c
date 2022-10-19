#include "main.h"

/**
 * for_flags - calculates active flags
 * @format: formatted string to print arguments
 * @i: parameter
 *
 * Return: flaags
 */
int for_flags(const char *format, int *i)
{
	/* '-', '+', '0', ' ', '#' */
	/*  1, 2, 4, 8, 16 repectively */
	int j, icopy;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', ' ', '#', '\0'};
	const int FLAGS_ARR[] = {FM_MINUS, FM_PLUS, FM_ZERO, FM_SPACE, FM_HASH, 0};

	for (icopy = *i + 1; format[icopy] != '\0'; icopy++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[icopy] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = icopy - 1;

	return (flags);
	
}
