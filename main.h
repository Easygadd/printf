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

#endif
