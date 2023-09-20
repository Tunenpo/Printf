#include "main.h"

/******************** PRINT CHAR *********************/

/**
 * print_char - This Function prints Char
 * @types: The list A of Arguements
 * @buffer: The buffer Array to Handle print
 * @flags: This will calculate The Active flags
 * @width: The width
 * @precision: The Precision Spec
 * @size: The Size Specifier
 * Return: The numbers of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer,
				flags, width, precision, size));
}

/******************** PRINT A STRING *********************/

/**
 * print_string - This will print A string
 * @types: This is the list of Arguements
 * @buffer: The buffer Array to handle print
 * @flags: This Calculate Active flags
 * @width: This gets actie widths
 * @precision: The precision spec
 * @size:The size specifier
 * Return: The number of chars
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null);
		if (precision >= 6)
			str = "  ";
	}

	while (str[length] != '\0')
		length++;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, "", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/***************** PRINT PERCENT SIGN ******************/
/**
 * print_percent - This prints a percent sign
 * @types: The Lists of arguements
 * @buffer: The buffer Array to handle prints
 * @flags: This Function Calculates Active Flags
 * @width: This will Get width
 * @precision: The precision spec
 * @size: The Size Sppecifier
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/********************* PRINT INT *****************/
/**
 * print_int - This prints int
 * @types: The lists of arguements
 * @buffer: The buffer array to handle prints
 * @flags: This calculates active flags
 * @width This will gets the width
 * @precision: The precision spec
 * @size: The size specifier
 * Return: The number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i,
				buffer, width, flags, precision, size));
}

/************************* PRINT BINARY ********************/
/**
 * print_binary - This will print an unsigned number
 * @types: The lists of arguements
 * @buffer: The buffer Array to Handle
 * @flags: This will Calculate the active flags
 * @width: This gets the width
 * @precision: The precision spec
 * @size: The size specifier
 * Return: The numbers of chars printed
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigne int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
