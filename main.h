#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * printf func
*/
int _printf(const char *format, ...);

/**
 * write func
*/
int putch(char c);
int putss(char *s);

#endif
