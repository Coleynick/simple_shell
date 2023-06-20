#include "main.h"
/**
 * arguments - Entry point
 * Description: sets command line arguments
 * @buffer: input buffer
 * @av: arguments
 * Return: int
 */
int arguments(char **buffer, char **av)
{
	int num = 0, i;
	int found;
	char *args_s;

	num = tokenize(*buffer, ' ');

	args_s = *buffer;
	for (i = 0; i < num; i++)
	{
		av[i] = args_s;
		args_s += strlen(args_s) + 1;
	}
	av[num] = NULL;
	found = path(&av[0]);
	return (found);
}
