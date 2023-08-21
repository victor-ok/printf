#include "main.h"

/**
 * putch - writes to stdout
 *
 * @c: character to be written out
 *
 * Return - 0
*/

int putch(char c[], int *index)
{
	if(*index > 0)
		return (write(1, &c, 1));
	*index = 0;
}
