#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h> /* used to define symbolic constants */

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024 /* macro used as symbolic name for numeric constants */

/* Flag modifiers */
#define FM_MINUS 1
#define FM_PLUS 2
#define FM_ZERO 4
#define FM_HASH 8
#define FM_SPACE 16

/* sizes */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct for the format string fmt
 * @fmt: the format string
 * @func: similiar function
 */
struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - reference to the struct above
 * @fmt: the format
 * @fmt_t: similiar function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int to_print(const char *fmt, int *i, va_list lists, char buffer[], int flags, int width, int precision, int size);

/* functions */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* print numbers functions */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

int print_hexa(va_list types, char reference[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* functions to print non printable characters*/
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* function to print memory address*/
int print_ptr(va_list types, char buffer[], int flags, int width, int precision, int size);

/* functions to handle other specifiers*/
int for_flags(const char *format, int *i);
int for_width(const char *format, int *i, va_list lists);
int for_precision(const char *format, int *i, va_list lists);
int for_size(const char *format, int *i);

/* function to print reverse string */
int print_rev(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int to_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_num(int is_plus, int index, char buffer[], int flags, int width, int precision, int size);
int write_nums(int index, char buff[], char buffer[], int flags, int width, int precision, int len, char p, char dup_c);
int write_ptr(char buffer[], int index, int len, int width, int flags, char p, char dup_c, int p_begin);

int write_un(int is_minus, int index, char buffer[], int flags, int width, int precision, int size);

/* utils */
int is_canprint(char);
int add_hexa_code(char, char[], int);
int is_digit(char);

long int get_size_number(long int num, int size);
long int get_size_un(unsigned long int num, int size);

#endif
