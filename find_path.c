#include "holberton.h"
char *find_path(char **env)
{
	char *path = "PATH=";
	char *tmp;
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
		tmp = strcpy(tmp, env[i]);
		/*printf("find_path: %s", tmp)*/;
		return (tmp);
	}
	return (NULL);
}