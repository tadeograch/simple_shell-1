#ifndef HOLBERTON_H
#define HOLBERTON_H
/*LIBRARIES*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

/*BUILTS_INTS*/
/**
 * struct built_in_s - Struct op base
 * @name: shell command name
 * @f: The function associated to the command.
 */
typedef struct built_in_s
{
	char *name;
	int (*f)();
} built_in;

/* FUNCTIONS*/

char **create_tokens(char *line, char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int pedircomando(char **env);
char *findcom(char *str, char **env);
char *find_path(char **env);
char *str_concat(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strchr(char *s, char c);
void free_willy(char **ptr, char *ptr2);
int findbuilt_in(char **argv, char *token);
int fhelp(char **argv);
int fexit(char **argv);
int _endofilee(char *buffer, int len);

#endif
