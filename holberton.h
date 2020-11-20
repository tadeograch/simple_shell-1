#ifndef HOLBERTON_H
#define HOLBERTON_H
/*LIBRARYS*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

/*BUILTS_INTS*/
/**
 * struct built_in_s - Struct op base
 * @name: shell command name
 * @f: The function associated to the command.
 */
typedef struct built_in_s
{
	char *name;
	int (*f)(char **argv);
} built_in;

/* FUNCTIONS*/

char **create_tokens(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int pedircomando(char **env);
char *findcom(char *str, char **env);
char *find_path(char **env);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int findbuilt_in(char **argv);
int fhelp(char **argv);
int fexit(char **argv);


#endif
