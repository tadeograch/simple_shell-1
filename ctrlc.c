#include "holberton.h"
/**
 * controlcfun - function that finds specific command
 * @a: path line as string
 *
 * Return: void;
 */
void controlcfun(int a)
{
	(void)a;
	signal(SIGINT, controlcfun);
	write(1, "\n", 1);
	prompt_0();
}
