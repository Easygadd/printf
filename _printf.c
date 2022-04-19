#include "main.h"
/**
 *_printf - prints a string with specifiers.
 *@format: the main string passed to the function.
 *
 *Return: number of total characters printed to stdout
 */
int _printf(const char *format, ...)
{
	int printed_chars;

	conver_struct print_list[] = {
		{"%", prints_percent},
		{"d", prints_numbers},
		{"i", prints_numbers},
		{"c", prints_character},
		{"s", prints_string},
		{"R", prints_rot13},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_chars = selector(format, print_list, arg_list);
	va_end(arg_list);

	return (printed_chars);
}
