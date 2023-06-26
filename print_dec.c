#include "main.h"

/**
 * print_number - Entry point
 * @n: number
 * Description: to check if letter is uppercase
 * Return: 1 if upper 0 else
 */
int print_number(int n)
{
	int len = 1;
	int num = 0;
	unsigned int z;
	unsigned int final;

	if (n < 0)
	{
		num += _putchar('-');
		z = -n;
	}
	else
		z = n;
	final = z;
	while (z /= 10)
	{
		len *= 10;
	}
	for ( ; len; len /= 10)
	{
		num += _putchar(((final / len) % 10) + '0');
	}
	return (num);
}
