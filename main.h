#ifndef _PRINT_F
#define _PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct conversion - This struct content.
 *@spec: specifier char
 *@f: pointer to function in print list
 */
struct conversion
{
	char *spec;
	int (*f)(va_list);
};
typedef struct conversion conver_struct;

int _printf(const char *format, ...);
int selector(const char *format, conver_struct print_list[], va_list arg_list);
int put_char(char);
int prints_character(va_list);
int prints_string(va_list);
int prints_percent(va_list);
int prints_numbers(va_list);
int prints_rot13(va_list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_dec(va_list d);
int print_rev(va_list r);
int print_bin(va_list b);
int print_unsig(va_list u);
int print_octal(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_rot13(va_list R);

#endif
