#include "holberton.h"
/**
 * main - simple command interpreter
 * Return: 0;
 */
void pedircomando(void);
int main(void)
{
	while (1)
	{
		write(1, "$ ", 2);
		pedircomando();
	}
	return (0);
}
/**
 * pedircomando - ask command
 */
void pedircomando(void)
{
	size_t buffsize = 0, len;
	char *buffer = NULL, *argv[2];
	pid_t child_pid;
	int status;

	/** write(1, "$ ", 2);*/
	len = getline(&buffer, &buffsize, stdin);
	buffer[len - 1] = '\0';
	argv[0] = buffer;
	argv[1] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		/**return (1);*/
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(&status);
	}
}
