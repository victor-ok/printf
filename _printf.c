#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 *
 * @format: format specifier
 *
 * Return: Always 0 (Success)
*/

int _printf(const char *format, ...)
{
	unsigned int i, counter, s_counter = 0;

	va_list words;

	if (format == NULL)

		return (-1);

	va_start(words, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putch(format[i]);
			s_counter++;
		}
		else if (format[i] == '\0')
		{
			return (i);
		}
		else if (format[i] == '%' && (format[i + 1] == '\0' || format[i + 1] == ' '))
		{
			return (-1);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			putch(va_arg(words, int));
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
			putch('%');
		}
		counter++;
	}
	va_end(words);
	return (counter);
}
