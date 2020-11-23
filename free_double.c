#include "holberton.h"

void free_double(char **ptr)
{
    int i;

    for (i = 0; ptr[i] != '\0'; i++)
    {
        free(ptr[i]);
    }
    free(ptr);
}