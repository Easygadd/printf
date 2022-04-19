#include "main.h"
/**
 * selector - function that selects the correct % with print_list function
 * @arg_list: list of n elements from printf
 * @print_list: array of identifiers and printing functions
 * @format: identifier char
 * Return: numbers chars printed
 **/
int selector(const char *format, conver_struct print_list[], va_list arg_list)
{
	int i, j;
	int validator = 0, num_chars = 0;
/* i, j iterators, validator true/false, num return n number of char printed */
	for (i = 0; format[i] != '\0'; i++)
		/* loop for the main str*/
	{
		if (format[i] == '%') /*Checking for format specifier*/
		{
/* loop for struct to check function to use*/
			for (j = 0; print_list[j].spec != NULL; j++)
			{
				if (format[i + 1] == print_list[j].spec[0])
				{
					validator = print_list[j].f(arg_list);
					if (validator == -1)
						return (-1);
					num_chars += validator;
					break;
				}
			}
			if (print_list[j].spec == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					put_char(format[i]);
					put_char(format[i + 1]);
					num_chars = num_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /* to avoid printing specifier*/
		}
		else
		{
			put_char(format[i]); /*prints the current char*/
			num_chars++; /* adds 1 to n chars printed */
		}
	}
	return (num_chars);
}
