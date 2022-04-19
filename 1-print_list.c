#include "main.h"

/**
 *prints_percent - prints a %.
 *@list: no args used
 *
 *Return: 1 char
 */
int prints_percent(va_list list __attribute__((unused)))
{
	put_char('%');
	return (1);
}
/**
 *prints_character - prints a char.
 *@list: entry args
 *
 *Return: 1 char
 */
int prints_character(va_list list)
{
	put_char(va_arg(list, int));
	return (1);
}
/**
 *prints_string - prints a string.
 *@list: entry args
 *
 *Return: i = number of chars printed
 */
int prints_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		put_char(str[i]);
	return (i);
}
/**
 *prints_numbers - prints an integer.
 *@list: entry args
 *
 *Return: num_length = number of chars printed
 */
int prints_numbers(va_list list)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(list, int);

	div = 1;
	len = 0;

	if (n < 0)
	{
		len += put_char('-');
		num = n * -1;
	}
	else
		num = n;
	for (; num / div > 9; )
		div *= 10;
	for (; div != 0; )
	{
		len += put_char('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (len);
}
/**
 * prints_rot13 - prints string into code rot13
 * @list: pointer of the string to code
 * Return: number of elements printed
 **/

int prints_rot13(va_list list)
{
	int i, j;
	char *s;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (s[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}
