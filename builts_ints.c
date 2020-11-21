#include "holberton.h"
/**
* findbuilt_in - find builts in
* @argv: arguments
* Return: result 0 or -1
*/
int find_built_in_3(char **args)
{
	int comp, i = 0;

	built_in functions[] = {
		{"exit", fexit},
		{"help", fhelp},
		{NULL, NULL}
	};
	while (functions[i].name != NULL)
	{
		comp = strcmp(args[0], functions[i].name);
		if (comp == 0)
		{
			if (functions[i].f(args) == -1)
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
/**
* fhelp - command help function
* @argv: arguments
* Return: result 0 or -1
*/
int fhelp(char **args)
{
	if (args[1] != NULL)
	{
		if (execve("/bin/cat", args, NULL) == -1)
		{
			perror("");
		}
		printf("a!\n");
	}
	printf("HELP!\n");
	return (0);
}
/**
* fexit - command exit function
* @argv: arguments
* Return: result...
*/
int fexit(char **args)
{
	(void)args;
	/*printf("Exit !\n");*/
	exit(0);
}
/**
* fcd - command cd function
* @argv: arguments
* Return: result 0
*/
int fcd(char **args)
{
	if (args[1] != NULL)
	{
		chdir(args[1]);
	}
	else
	chdir("/home");
	return (0);
}
