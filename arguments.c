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
	int num = 0;
	int found;
	char *args_s;

	args_s = strtok(*buffer, " ");
	while (args_s != NULL)
	{
		av[num] = args_s;
		args_s = strtok(NULL, " ");
		num++;
	}
	av[num] = NULL;
	found = path(&av[0]);
	return (found);
}
