#include "main.h"

/**
 * prinpint - Prints integers
 * @arguments: va_list containing the number to print
 * @buf: Buffer pointer to store the result
 * @ibuf: Index for buffer pointer
 * Return: Number of characters printed
 */
int prinpint(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = handl_buf(buf, '+', ibuf);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + 1);
}
