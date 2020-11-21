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
		if (isatty(STDOUT_FILENO))
			write(STDOUT_FILENO, "<3 ", 3);
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
	ssize_t len;
	char *buffer = NULL, **argv = NULL, *path = NULL;

	len = getline(&buffer, &buffsize, stdin);
	_endofilee(buffer, len);
	argv = create_tokens(buffer, env);
	/*if (findbuilt_in(argv) == 1)
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
	}*/
	free(argv);
	return (1);
}
/**
 * create_tokens - separates command line
 * @line: line received from main.
 * Return: tokens array;
 */
char **create_tokens(char *line, char **env)
{
	unsigned int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token = NULL;
	char *path = NULL;
	pid_t child_pid;
	int status;

	if (!tokens)
	{
		perror("");
		return (NULL);
	}
	token = strtok(line, " ");
	char *token_two = token;

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		/*if (i >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, (bufsize - 64) * sizeof(char *),
			bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("");
				return (NULL);
			}
		}*/
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	if (findbuilt_in(tokens, token_two) == 1)
	{
		path = findcom(tokens[0], env);
		child_pid = fork();
		if (child_pid == -1)
			perror("");
		if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				if (execve(path, tokens, env) == -1)
				{
					perror("");
					exit(0);
				}
			}
		}
		else
			wait(&status);
	}
	free(line);
	free(path);
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
			free(tkn);
			free(path);
			return (cat);
		}
		tkn = strtok(NULL, ":");
	}
	free(tkn);
	free(path);
	return (NULL);
}

int _endofilee(char *buffer, int len)
{

if (len == EOF)
	{
		perror("");
		free(buffer);
		return (0);
	}
	if (len == 1)
	{
		free(buffer);
		return(0);
	}	
	buffer[len - 1] = '\0';
	return (1);
	}