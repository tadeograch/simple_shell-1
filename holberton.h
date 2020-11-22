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
	int (*f)(char **argv, char **env);
} built_in;

/* FUNCTIONS*/

void prompt_0(void);
char  *getline_1();
char **split_line_2(char *buffer);
int find_built_in_3(char **args, char **env);
char *getpath_4(char *str, char **env);
void execute_5 (char *path, char **args, char **env);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int fhelp(char **args, char **env);
int fexit(char **args, char **env);
int fcd(char **argv, char **env);
int fenv(char **args, char **env);
char *find_path(char **env);
void controlcfun(int a);
int _strcmp(char *s1, char *s2);


#endif
