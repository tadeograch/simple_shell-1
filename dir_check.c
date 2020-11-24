#include "holberton.h"
/**
*
*
*/

int dir_check (char *dir_name)
{
    DIR *dir = NULL;

    dir = opendir(dir_name);
    if (dir)
    {
        print_error(dir_name, "Is a directory");
        closedir(dir);
        return (1);
    }
    return (0);
}