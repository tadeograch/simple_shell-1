#include "holberton.h"
/**
* find_built_in_3 - find builts in
* @args: arguments
* @env: environment variables
* Return: result 0 or -1
*/
int find_built_in_3(char **args, char **env)
{
	int comp, i = 0;

	built_in functions[] = {
		{"exit", fexit},
		{"help", fhelp},
		{"cd", fcd},
		{"env", fenv},
		{NULL, NULL}
	};
	while (functions[i].name != NULL)
	{
		comp = _strcmp(args[0], functions[i].name);
		if (comp == 0)
		{
			if (functions[i].f(args, env) == -1)
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
* @args: arguments
* @env: environment variables
* Return: result 0 or -1
*/
int fhelp(char **args, char **env)
{
	(void)env;
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
* @args: arguments
* @env: environment variables
* Return: result...
*/
int fexit(char **args, char **env)
{
	(void)env;
	(void)args;

	exit(0);
}
/**
* fcd - command cd function
* @args: arguments
* @env: environment variables
* Return: result 0
*/
int fcd(char **args, char **env)
{
	char *path = "HOME=";
	char *tmp = NULL;
	int i, j, k;

	if (args[1] == NULL)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (path[j] != env[i][j])
					break;
			}
			if (j == 5)
				break;
		}
		tmp = malloc(_strlen(env[i]) + 1);
		if (tmp == NULL)
		{
			perror("");
		}
		for (k = 0; env[i][j] != '\0'; j++, k++)
		{
			tmp[k] = env[i][j];
		}
		if (chdir(tmp) != 0)
			perror("");

	}
	else
		if (chdir(args[1]) != 0)
	{
			perror("");
	}
		return (0);
}
