#include "holberton.h"

void prompt_0 (void)
{
    write(1, "<3 ", 3);
}

char *getline_1 ()
{
    int len = 0;
    size_t buffsize = 0;
    char *buffer = NULL;

    len = getline(&buffer, &buffsize, stdin);
	if (len == -1)
	{
		if (len == EOF)
			return (0);
		perror("");
	}
    buffer[len - 1] = '\0';
    return (buffer);
}

/**
 * 2_split_line - separates command line
 * @buffer: buffer received from getline.
 * Return: tokens array;
 */
char **split_line_2(char *buffer)
{
	unsigned int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error: ");
		return (NULL);
	}
	token = strtok(buffer, " ");
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
				perror("Error");
				return (NULL);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * 4_getpath - function that finds specific command
 * @str: path line as string
 * @env: environment variable
 * Return: tkn;
 */
char *getpath_4(char *str, char **env)
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
	return (NULL);
}

void execute_5 (char *path, char **args, char **env)
{
    pid_t child_pid = 0;
    int status;

    child_pid = fork();
		if (child_pid == -1)
			perror("");
		if (child_pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				if (execve(path, args, env) == -1)
				{
					perror("");
					exit(0);
				}
			}
		}
		else
		{
			wait(&status);
			free(path);
			free(args);
		}
}

void controlcfun(int a)
{
    (void)a;
    signal(SIGINT, controlcfun);
    write(1, "\n", 1);
    prompt_0();
}
