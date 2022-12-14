#include "main.h"

/**
 * _printf - variadic function that formats and prints data.
 * @format: the format string
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	unsigned int i = 0, chars_written = 0;

	int (*temp_func)(va_list), no_conversion;


	if (!format)

		return (0);


	va_start(arg_list, format);

	while (format[i])

	{
		no_conversion = 1;

		if (format[i] == '%')
		{	
			temp_func = match_specifier(format[++i]);
			if (temp_func)
			{
				chars_written += temp_func(arg_list);
				i++;
				no_conversion = 0;
			}
		}
		if (no_conversion)
		{
			_putchar(format[i++]);
			chars_written++;
		}
	}
	va_end(arg_list);

	return (chars_written);
}
