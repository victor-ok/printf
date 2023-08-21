#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 *
 * @format: format specifier
 *
 * Return - no of bytes
*/

int _printf(const char *format, ...)
{
	unsigned int i, counter, s_counter = 0;

	va_list words;

	if (!format || (format[0] == '\0' && format[1] == '%'))
	{
		return (-1);
	}
	

	va_start(words, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putc(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			putc(va_arg(words, int));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s_counter = putss(va_arg(words, char *));
			i++;
			counter += (s_counter - 1);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putc('%');
		}
		counter++;
	}
	va_end(words);
	return (counter);
}
