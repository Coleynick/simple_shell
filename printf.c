#include "main.h"
/**
 * _printf - Entry point
 * Description:  check if letter is uppercase
 * @format: string
 * Return: int
 */
int _printf(const char *format, ...)
{
	int n = 0, i = 0;
	char *s;
	va_list args;

	va_start(args, format);
	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			n += _putchar(format[i]);
			i++;
			continue;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			n += _putchar('%');
		}
		else if (format[i + 1] == 'c')
		{
			n += _putchar(va_arg(args, int));
		}
		else if (format[i + 1] == 's')
		{
			s = va_arg(args, char*);
			n += print_strings(s);
		}
		else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			n += print_number(va_arg(args, int));
		else
		{
			n += _putchar(format[i]);
			i++;
			continue;
		}
		i += 2;
	}
	va_end(args);
	return (n);
}
