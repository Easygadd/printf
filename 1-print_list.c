#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * prints_percent - prints a %.
 * Return: 1 char
 */
int prints_percent(void)
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
	unsigned char my_char;

	my_char = va_arg(list, int);
	_putchar(my_char);
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
	int i = 0;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	while (my_string[i])
	{
		_putchar(my_string[i]);
		i++;
	}
	return (i);
}
/**
 * print_int - prints an integer.
 * @i: number to print
 * Return: size of the output text
 */
int print_int(va_list i)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* print_bin - convert to binary
* @b: number in decinal
* Return: number of chars printed
*/
int print_bin(va_list b)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* print_hex - function that prints an unsigned int in hexadecimal
* @n: unsigned to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Descriptions: prints unsigned in hexadecimal with _putchar
* Return: size the output
*/
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int len, powten, j, digit, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 16;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (digit < 10)
				_putchar(digit + '0');
			else
				_putchar(digit + '0' + diff);
			count++;
			n -= digit * powten;
			powten /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
* print_x - takes an unsigned int an prints it in lowercase hex
* @x: unsigned int to print
* Descriptions: prints in lowercase hex with _putchar
* Return: size of the output
*/
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
* print_X - takes an unsigned int an prints it in uppercase hex
* @X: unsigned int to print
* Descriptions: prints in uppercase hex with _putchar
* Return: size of the output
*/
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
/**
* print_dec - function that prints an decimal
* @d: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text
*/
int print_dec(va_list d)
{
	int len, powten, j, digit, n, count = 0, num;

	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
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
