#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int putch(char c);
int putss( char *s); 
int custom_printf(const char *format, ...);

#endif
