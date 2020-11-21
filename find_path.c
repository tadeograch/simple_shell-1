#include "holberton.h"
/**
* find_path - search value of variable PATH
* @env: environ received
* Return: value of variable PATH
*/
char *find_path(char **env)
{
	char *path = "PATH=";
	char *tmp = NULL;
	int i, j;

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
	tmp = malloc(strlen(env[i]) + 1);
	if (tmp != NULL)
	{
		tmp = _strcpy(tmp, env[i]);
		return (tmp);
	}
	free(tmp);
	return (NULL);
}
