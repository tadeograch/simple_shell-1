#include "holberton.h"
/**
 * main - simple command interpreter
 * @ac: number of arguments
 * @av: arguments
 * @env: environment variable
 * Return: 0;
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	while (1)
	{
		write(1, "<3 ", 3);
		pedircomando(env);
	}
	return (0);
}
/**
 * pedircomando - function that interprets command line
 * @env: environment variable
 * Return: 0 or 1;
 */
int pedircomando(char **env)
{
	size_t buffsize = 0;
	int len;
	char *buffer = NULL, **argv = NULL, *path = NULL;
	pid_t child_pid;
	int status;

	len = getline(&buffer, &buffsize, stdin);
	if (len == -1)
	{
		if (len == EOF)
		{
			perror("");
			return (0);
		}
		perror("");	
	}
	if (len == 1)
		return (0);	
	buffer[len - 1] = '\0';
	argv = create_tokens(buffer);
	if (findbuilt_in(argv) == 1)
	{
		path = findcom(argv[0], env);
		child_pid = fork();
		if (child_pid == -1)
			perror("");
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				if (execve(path, argv, env) == -1)
				{
					perror("");
					exit(0);
				}
			}
		}
		else
			wait(&status);
	}
	free(buffer);
	free(argv);
	free(path);
	return (1);
}
/**
 * create_tokens - separates command line
 * @line: line received from main.
 * Return: tokens array;
 */
char **create_tokens(char *line)
{
	unsigned int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token = NULL;

	if (!tokens)
	{
		perror("");
		return (NULL);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, (bufsize - 64) * sizeof(char *),
			bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("");
				return (NULL);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * findcom - function that finds specific command
 * @str: path line as string
 * @env: environment variable
 * Return: tkn;
 */
char *findcom(char *str, char **env)
{
	int res;
	char *cat = NULL, *barra = "/";
	char *tkn = NULL;
	char *path = NULL;
	struct stat st;

	path = find_path(env);
	tkn = strtok(path, ":");
	while (tkn != NULL)
	{
		tkn = str_concat(tkn, barra);
		cat = str_concat(tkn, str);
		res = stat(cat, &st);
		if (res == 0)
		{
			return (cat);
		}
		tkn = strtok(NULL, ":");
	}
	free(tkn);
	free(path);
	return (NULL);
}
