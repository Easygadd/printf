#include "main.h"
/**
*put_char - write  a single character.
*@c: The character to print
*
*Return: 0
*/
int put_char(char c)
{
	return (write(1, &c, 1));

}
