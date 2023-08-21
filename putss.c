#include "main.h"

/**
 * putss - a func to print string
 *
 * @s: pointer to the string
 *
 * Return - 0
*/

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
