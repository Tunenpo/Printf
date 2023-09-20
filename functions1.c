#include "main.h"

/************************* PRINT UNSGNED NUMBER *************************/

/**
 * print_unsigned - This prints an unsigned number
 * @types: This is the lists A of Arguements
 * @buffer: This is the Buffer Array to Handle
 * @flags: This calculates the active flags
 * @width: This gets width
 * @precision: The precision spec
 * @size: The size specifier
 * Return: The number of chars to be printed
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*************** PRINT UNSIGNED NUMBER IN OCTAL ***************/

/**
 * print_octal - This prints an unsigned number in octal notation
 * @types: This is the lists of a Arguements
 * @buffer: This is the buffer Array to Handle
 * @flags: This Calculates The Active Flags
 * @width: This gets width
 * @precision: This is the precision Spec
 * @size: This is the size specifier
 * Return: The number of chars to be printed.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***************/

/**
 * print_hexadecimal - This prints an unsigned number in hexadecimal notation
 * @types: This is the lists of Arguements
 * @buffer: This is the Buffer Array to Handle
 * @flags: This calculates the Active Flags
 * @width: This gets width
 * @precision: This is the Precision Spec
 * @size: this is the Size Specifier
 * Return: The number of Chars to be Printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef",
				buffer, flags, 'x', width, precision, size));
}

/*************** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***************/

/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal notation
 * @types: The list of Arguements
 * @buffer: The buffer Array to Handle
 * @flags: Calculates active flags
 * @width: Gets width
 * @precision: The precision Spec
 * @size: THe size Specifier
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'x', width, precision, size));
}

/*************** PRINT HEXX NUM IN LOWER OR UPPER ***************/

/**
 * print_hexa - This prints hexadecimal in lower or upper
 * @types: This is lists of arguements
 * @map_to: This is the Array of values to map number to
 * @buffer: The buffer of Array to Handle
 * @flags: Calculates the Active Flags
 * @flag_ch: This calculates active flags
 * @width: Gets width
 * @precision: The precision Spec
 * @size: The size Specifier
 * @size: The size Spec
 * Return: The number of chars to be Printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
