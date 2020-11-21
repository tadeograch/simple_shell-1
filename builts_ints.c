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
<<<<<<< HEAD
		comp = strcmp(args[0], functions[i].name);
=======
		comp = _strcmp(argv[0], functions[i].name);
>>>>>>> 786f3e8f178cdd8f670d919b46d085d98b3f9546
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
<<<<<<< HEAD
	(void)args;
	/*printf("Exit !\n");*/
=======
	free(argv);
>>>>>>> 786f3e8f178cdd8f670d919b46d085d98b3f9546
	exit(0);
}
/**
* fcd - command cd function
* @argv: arguments
* Return: result 0
*/
int fcd(char **args)
{
<<<<<<< HEAD
	if (args[1] != NULL)
	{
		chdir(args[1]);
=======
	/* char *tmp, *cmd;

	tmp = _strcpy(tmp, argv[1]);
	cmd = _strchr(tmp, '\n');
	if (tmp != NULL && cmd != NULL)
	{
		*cmd = 0;
>>>>>>> 786f3e8f178cdd8f670d919b46d085d98b3f9546
	}
	chdir(cmd); */
	printf("cd %s\n", argv[1]);
	return (0);
}
