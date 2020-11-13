#include "holberton.h"
/**
 * main - shell is a command-line interpreter which
 * exposes access to an operating system's services
 * Return: 0
 */
int main(void)
{

	print_prompt();
	return (0);
}

void print_prompt()
{
	write(1, "$ ", 2);
}
