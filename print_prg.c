#include "main.h"

/**
 * print_prg - Prints the '%' character
 * @a: Unused va_list (no additional arguments expected)
 * @buf: Buffer pointer to store the result
 * @i: Index for buffer pointer
 * Return: Always returns 1 (number of characters printed)
 */
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handl_buf(buf, '%', i);

	return (1);
}
