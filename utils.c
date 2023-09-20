#include "main.h"

/**
 * is_printable - This evaluate if a char is printable
 * @c: The char to be evaluated
 *
 * Return: 1 if c is printable or 0 Otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This Append ascci in hexadecimal code to buffer.
 * @buffer: The array of chars
 * @i: The index in which to start appending
 * @ascii_code: ASSCI CODE
 * Return: # Always
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This verifies if a char is a digit
 * @c: The char to be evaluated
 *
 * Return: 1 if c is a digit or 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This cast a number to a specific size
 * @num: The number to be casted
 * @size: The number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the spec size
 * @num: number to be casted
 * @size: the number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
