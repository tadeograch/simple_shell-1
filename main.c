#include "holberton.h"
/**
 * main - Entry point
 * @ac: ac
 * @av: av
 * @env: environment variables
 * Return: void;
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **args = NULL;
	int built_in = 0;
	char *path = NULL;
	(void)ac;
	(void)av;

	signal(SIGINT, controlcfun);
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt_0();
		}
		buffer = getline_1();
		if (buffer[0] != ' ' && buffer[0] != '\0')
		{
			args = split_line_2(buffer);
			built_in = find_built_in_3(args, env);
			if (built_in == 0)
				continue;
			path = getpath_4(args[0], env);
			execute_5(path, args, env);
		}
		else
		{
			continue;
		}
	}
	return (0);
}
