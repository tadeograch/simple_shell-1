#include "holberton.h"
/**
 * str_concat - concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to str.
 */

char *str_concat(char *s1, char *s2)
{
        char *str;
        int a, b, size1, size2;
        if (s1 == NULL)
        {
                s1 = "";
        }
        if (s2 == NULL)
        {
                s2 = "";
        }
        for (size1 = 0; *(s1 + size1) != '\0'; size1++)
        {
        }
        for (size2 = 0; *(s2 + size2) != '\0'; size2++)
        {
        }
        str = (char *)malloc(sizeof(char) * (size1 + size2) + 1);
        if (str == NULL)
	{
                return (NULL);
        }
        for (a = 0; a < size1; a++)
        {
                *(str + a) = *(s1 + a);
        }
        for (b = 0; b <= (size2); b++, a++)
        {
                *(str + a) = *(s2 + b);
        }
        return (str);
}