#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - produce an output according to format
 * @format: the character string
 *
 * Return: returns the number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, prints = 0, prints_chars = 0;
	int flags, width, precision, size, buff_index = 0;

	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = *(format + i);
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			prints_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = for_flags(format, &i);
			width = for_width(format, &i, lists);
			precision = for_precision(format, &i, lists);
			size = for_size(format, &i);
			++i;
			prints = to_print(format, &i, lists, buffer, flags, width, precision, size);
			if (prints == -1)
				return (-1);
			prints_chars += prints;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(lists);

	return (prints_chars);
}

/**
 * print_buffer - prints the contents of the buffer
 * @buffer: array of characters
 * @buff_index: index through the characters to get the length
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
