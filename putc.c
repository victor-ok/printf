#include "main.h"

/**
 * putc - writes to stdout
 *
 * @c: character to be written out
 *
 * Return - 0
*/

int putc(char c)
{
	return (write(1, &c, 1));
}
