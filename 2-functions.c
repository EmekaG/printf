#include "main.h"

/**
 * print_ptr - print the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: space required
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_ptr(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char dup_c = 0, p = ' ';
	int index = BUFF_SIZE - 2, len = 2, p_begin = 1; /* len = 2, for 0x */
	unsigned long num_ptr;
	char reference[] = "0123456789abcdef";
	void *ptr = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_ptr = (unsigned long)ptr;

	while (num_ptr > 0)
	{
		buffer[index--] = reference[num_ptr % 16];
		num_ptr /= 16;
		len++;
	}

	if ((flags & FM_ZERO) && !(flags & FM_MINUS))
		p = '0';
	if (flags & FM_PLUS)
		dup_c = '+', len++;
	else if (flags & FM_SPACE)
		dup_c = ' ', len++;

	index++;

	/* return (write(1, &buffer[i], BUFF_SIZE - i - 1)); */
	return (write_ptr(buffer, index, len, width, flags,
				p, dup_c, p_begin));
}

/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (*(str + i) != '\0')
	{
		if (can_print(*(str + i)))
			buffer[i + offset] = *(str + i);
		else
			offset += add_hexa_code(*(str + i), buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_rev - prints a reverse string
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */
int print_rev(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; *(str + i); i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = *(str + i);

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - prints a string in rot13
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; *(str + i); i++)
	{
		for (j = 0; *(in + j), j++)
		{
			if (*(in + j) == *(str + i))
			{
				x = *(out + j);
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!*(in + j))
		{
			x = *(str + i);
			write(1, &x, i);
			count++;
		}
	}
	return (count);
}
