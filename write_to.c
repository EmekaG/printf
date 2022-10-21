#include "main.h"

/**
 * to_write_char - prints a string
 * @c: char types
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int to_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char p = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FM_ZERO)
		p = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = p;

		if (flags & FM_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - prints a string
 * @is_minus: list of arguments
 * @index: char types
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_num(int is_minus, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char p = ' ', dup_ch = 0;

	UNUSED(size);

	if ((flags & FM_ZERO) && !(flags & FM_MINUS))
		p = '0';
	if (is_minus)
		dup_ch = '-';
	else if (flags & FM_PLUS)
		dup_ch = '+';
	else if (flags & FM_SPACE)
		dup_ch = ' ';

	return (write_nums(index, buffer, flags, width, precision,
				len, p, dup_ch));
}

/**
 * write_nums - write a number using a buffer
 * @index: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width required
 * @precision: precision specifier
 * @len: number length
 * @p: padding character
 * @dup_c: more character
 *
 * Return: number of printed chars
 */
int write_nums(int index, char buffer[],
		int flags, int width, int precision,
		int len, char p, char dup_c)
{
	int i, p_begin = 1;

	if (precision == 0 && index == BUFF-SIZE - 2 &&
			buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0) no character is printed */
	if (precision == 0 && ind == BUFF-SIZE - 2 && buffer[index] == '0')
		buffer[index] = p = ' '; /* width is displaying with p */
	if (precision > 0 && precision < len)
		p = ' ';
	while (precision > len)
		buffer[--index] = '0', len++;
	if (dup_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = p;
		buffer[i] = '\0';
		if (flags & FM_MINUS && padd == ' ')
		{
			if (dup_c)
				buffer[--index] = dup_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FM_MINUS) && p == ' ')
		{
			if (dup_c)
				buffer[--index] = dup_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & FM_MINUS) && p == '0')
		{
			if (dup_c)
				buffer[--p_begin] = dup_c;
			return (write(1, &buffer[p_begin], i - p_begin) +
					write(1, &buffer[index], len - (1 - p_begin)));
		}
	}
	if (dup_c)
		buffer[--index] = dup_c;
	return (write(1, &buffer[index], len));
}

/**
 * write_un - writes an unsigned number
 * @is_minus: number indicating if the number is negative
 * @index: index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars
 */
int write_un(int is_minus, int index,
		char buffer, int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, i = 0;
	char p = ' ';

	UNUSED(is_minus);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < len)
		p = ' ';

	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}

	if ((flags & FM_ZERO) && !(flags & FM_MINUS))
		p = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = p;

		*(buffer + i) = '\0';

		if (flags & FM_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
		}
		else
			return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
	}

	return (write(1, &buffer[index], len));
}

/**
 * write_ptr - writes a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: width specifier
 * @flags: Flags specifier
 * @p: Char representing the padding
 * @dup_c: Char representing extra character
 * @p_begin: Index at which padding should start
 *
 * Return: Number of written chars
 */
int write_ptr(char buffer[], int index, int len,
		int width, int flags, char p, char dup_c, int p_begin)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			*(buffer + i) = p;
		*(buffer + i) = '\0';
		if (flags & FM_MINUS && p == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (dup_c)
				buffer[--index] = dup_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & FM_MINUS) && p == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (dup_c)
				buffer[--index] = dup_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & FM_MINUS) && p == '0')
		{
			if (dup_c)
				buffer[--p_begin] = dup_c;
			*(buffer + 1) = '0';
			*(buffer + 2) = 'x';
			return (write(1, &buffer[p_begin], i - p_begin) +
					write(1, &buffer[index], len - (1 - p_begin) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (dup_c)
		buffer[--index] = dup_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
