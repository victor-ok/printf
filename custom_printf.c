#include <stdarg.h>
#include <stdio.h>
#include "main.h"

int custom_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int charCount = 0; // Pour compter les caractères imprimés

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Passer le caractère '%'
            if (*format == '\0')
                break; // Fin du format

            if (*format == 'd' || *format == 'i')
            {
                // Spécificateur de conversion pour un entier
                int num = va_arg(args, int); // Récupérer le prochain argument comme un int
                printf("%d", num); // Imprimer l'entier
                charCount++; // Incrémenter le compteur de caractères
            }
        }
        else
        {
            putchar(*format);
            charCount++;
        }
        format++;
    }

    va_end(args);

    return charCount;
}

