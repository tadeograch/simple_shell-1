#include "holberton.h"

int space_check(char *buffer)
{
    int i, r = 0;

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] != ' ')
        {
            r++;
            break;
        }
    }
    return (r);
}