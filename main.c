#include "shell.h"

int main(void)
{
	size_t buffsize = 0;
	char *buffer = NULL, *argv[] = {"0", NULL};
	pid_t child_pid;
	int status;

	while (1)
	{
		write(1, "$ ", 2);
		getline(&buffer, &buffsize, stdin);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("buffer: %s\n", buffer);
			if(buffer == "/bin/ls")
			{
				printf("x");
			}
			else
				printf("y");

			if (execve("/bin/ls", argv, NULL) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
