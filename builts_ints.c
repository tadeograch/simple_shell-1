#include "holberton.h"
int findbuilt_in(char **argv)
{
        int comp, i = 0;

        built_in functions[] = {
                {"exit", fexit},
                {"help", fhelp},
                {NULL, NULL}
        };

        while (functions[i].name != NULL)
        {
                comp = strcmp(argv[0], functions[i].name);
                if (comp == 0)
                {
                                if (functions[i].f(argv) == -1)
                                {
                                        return (-1);
                                }
                                return (0);
                }
                else
                {
                        i++;
                }
        }
        return (1);
}

int fhelp(char **argv)
{
        if (argv[1] != NULL)
        {
                if (execve("/bin/cat", argv, NULL) == -1)
                        {
                                perror("Error:");
                        }
                printf("a!\n");
                
        }
        printf("HELP!\n");
        return (0);
}

int fexit(char **argv)
{
        (void)argv;
        /*printf("Exit !\n");*/
        exit(0);
}

int fcd(char **argv)
{
        if (argv[1] != NULL)
        {
                chdir(argv[1]);
        }
        else
        chdir("/home");

        return (0);
}