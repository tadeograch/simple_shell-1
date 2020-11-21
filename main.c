#include "holberton.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    char *buffer = NULL;
    char **args = NULL;
    int built_in = 0;
    char *path = NULL;

    signal(SIGINT, controlcfun);
    while (1)
    {
        prompt_0();
        buffer = getline_1();
        if (/*buffer[0] != '\n' && */buffer[0] != '\0')
        {
        args = split_line_2(buffer);
        built_in = find_built_in_3(args);
        path = getpath_4(args[0], env);
        execute_5 (path, args, env); 
        }
        else
        {
            continue;
        }
    }
    return (0);
}
