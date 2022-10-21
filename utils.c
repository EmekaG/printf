#include "main.h"

/**
 * can_print - evaluates if a char can print
 * @c: char to be evaluated
 *
 * Return: 1 if c can print, 0 otherwise
 */
int can_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code -add ascii in hexadecimal code to buffer
 * @buffer: array of chars.
 * @i: index at which to start adding
 * @ascii_code: main ASCII
 *
 * Return: Always 3
 */
int add_hexa_code(char ascii_code, char buffer[], int i)
{
	char reference[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = reference[ascii_code / 16];
	buffer[i] = reference[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if a char is a digit
 * @c: char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * get_size_number - casts a number to a specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int get_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * get_size_un - cast a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int get_size_un(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
