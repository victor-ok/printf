#include "main.h"

/**
 * print_number - prints an integer
 * @num: input integer parameter
 * Return: 0 (success)
 */
int print_number(int num)
{
	unsigned int xx = num < 0 ? -num : num;
	int k, count = 0;

	if (num < 0)
	{
		putch('-');
		count++;
	}
	if (xx == 0)
	{
		putch('0');
		count++;
	}
	else
	{
		int digits[20];
		int i = 0;

		while (xx != 0)
		{
			digits[i] = xx % 10;
			xx /= 10;
			i++;
		}
		for (k = i - 1; k >= 0; k--)
		{
			putch(digits[k] + '0');
			count++;
		}
	}
	return (count);
}

/**
 * print_binary - prints a binary number
 * @num: number to print
 * Return: number to count
 */
int print_binary(unsigned int n)
{
	unsigned int bint = 1 << (sizeof(unsigned int) * 8 - 1);
	int count = 0, _zero = 1;

	if (n == 0)
	{
		putch('0');
		return (1);
	}
	while (bint != 0)
	{
		if ((n & bint) == 0)
		{
			if (_zero)
			{
				putch('0');
				count++;
			}
		}
		else
		{
			putch('1');
			count++;
			_zero = 0;
		}
		bint >>= 1;
	}
	return (count);
}


/**
 * _printf - a function that produces output according to a format.
 *
 * @format: format specifier
 *
 * Return: Always 0 (Success)
*/

int _printf(const char *format, ...)
{
	unsigned int i, counter, s_counter, i_counter = 0;

	va_list words;

	va_start(words, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putch(format[i]);
			s_counter++;
		}
		else if (format == NULL || (format[i] == '%' && format[i + 1] == ' ' && !format[i + 2]))
		{
			return (-1);
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
		else if (format == NULL)
		{
			s_counter = putss(va_arg(words, char *));
			i++;
			counter += (s_counter - 1);
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
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			i_counter += print_number(va_arg(words, int));
			i++;
			counter += (i_counter - 1);
		}
		counter++;
	}
	va_end(words);
	return (counter);
}
