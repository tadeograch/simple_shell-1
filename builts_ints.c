#include "holberton.h"
/**
* findbuilt_in - find builts in
* @argv: arguments
* Return: result 0 or -1
*/
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
		comp = _strcmp(argv[0], functions[i].name);
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
/**
* fhelp - command help function
* @argv: arguments
* Return: result 0 or -1
*/
int fhelp(char **argv)
{
	if (argv[1] != NULL)
	{
		if (execve("/bin/cat", argv, NULL) == -1)
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
int fexit(char **argv)
{
	free(argv);
	exit(0);
}
/**
* fcd - command cd function
* @argv: arguments
* Return: result 0
*/
int fcd(char **argv)
{
	/* char *tmp, *cmd;

	tmp = _strcpy(tmp, argv[1]);
	cmd = _strchr(tmp, '\n');
	if (tmp != NULL && cmd != NULL)
	{
		*cmd = 0;
	}
	chdir(cmd); */
	printf("cd %s\n", argv[1]);
	return (0);
}
