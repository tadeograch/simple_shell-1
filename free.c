#include "holberton.h"

/**
 * _strchr - check the code for Holberton School students.
 * @s: char pointer to be determined.
 * @c: char to compare.
 * Return: pointer or null.
 */

 void free_willy(char **ptr, char *ptr2)
 {
   /*  int i;

     for (i = 0; *(ptr + i) != NULL; i++)
     {
         free(ptr[i]);
     }*/
    free(ptr);
    free(ptr2);
    
 }