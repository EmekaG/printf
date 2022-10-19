#include "main.h"

/**
 * to_print - printd an argument based on type
 * @fmt: formatted string in which to print the arguments
 * @lists: lists of arguments to be printed
 * @index: index value
 * @buffer: buffer array to print
 * @flags: calculates active flags
 * @width: get width
 * @precision: get precision
 * @size: get size
 * 
 * Return: 1 or 2
 */
int to_print(const char *fmt, int *index, va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, prints_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent}, {'i', print_int}, {'d', print_int}, {'b', print_binary}, {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal}, {'X', print_hexa_upper}, {'p', print_ptr}, {'S', print_non_printable}, {'r', print_rev}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*index] == fmt_types[i].fmt)
			return (fmt_types[i].func(lists, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_len += write(1, &fmt[*index], 1);
		return (unknown_len);
	}
	return (prints_chars);
}
