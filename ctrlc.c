#include "holberton.h"
/**
 * controlcfun - function that finds specific command
 * @a: path line as string
 *
 * Return: void;
 */
void controlcfun(int a)
{
	(void)a;
	signal(SIGINT, controlcfun);
	write(1, "\n", 1);
	prompt_0();
}

/**
 * fenv - function that finds specific command
 * @args: user input
 * @env: environment variables
 *
 * Return: 0
 */
int fenv(char **args, char **env)
{
	int i, len = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		len = _strlen(env[i]);
		write(1, env[i], len);
		write(1, "\n", 1);
	}
	free_double(args);
	return (0);
}