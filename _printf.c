#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - a function that produces output according to a format.
 *
 * @format: format specifier
 *
 * Return: Always 0 (Success)
*/
int putch(char c);
int putss(char *s);

int _printf(const char *format, ...)
{
	unsigned int i, counter =0, s_counter = 0;

	va_list words;

	if (format == NULL)

		return (-1);
	va_start(words, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			counter++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(words,int);
			putch(c);
			i++;
			counter++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *s = va_arg(words,char *);
			counter += putss(s);
			i++;
			
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			putch('%');
			i++;
			counter++;
		}
	}

	va_end(words);
	return (counter);
}

int putch(char c)
{
	return (write(1, &c, 1));
}

int putss(char *s)
{
	int counter = 0;

	if (s)
	{
		for (counter = 0; s[counter] != '\0'; counter++)
		{
			putch(s[counter]);
		}
	}
	return (counter);
}

