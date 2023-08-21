#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 *
 * @format: format specifier
 *
 * Return - no of bytes
*/
void putchs(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	unsigned int i, counter =0, s_counter = 0;


	va_list words;
	char buffer[BUFF_SIZE];
	int flags, width, precision, size, buff_ind = 0;

	if(format == NULL)

		return(-1);
	
	va_start(words, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if(buff_ind == BUFF_SIZE)
				putchs(buffer, &buff_ind);
			counter++;
		}
		else{
			putchs(buffer,&buff_ind);
			flags = get_flags(format,&i);
			width = get_width(format, &i, words);
			precision = get_precision(format,&i,words);
			size = get_sige(format, &i);
			++i;
			s_counter = handle_print(format,&i, words, buffer,flags,width,precision,size);
			if(s_counter === -1)
				return(-1);
			counter +=s_counter;
		}
	}
	putchs(buffer,&buff_ind);

	va_end(words);
	return (counter);
}

void putchs(char buffer[],int *buff_ind)
{
	if(*buff_ind >0)
		write(1,&buffer[0], *buff_ind);
	*buff_ind = 0;
}

