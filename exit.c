#include "main.h"
/**
* exitStatus - Checks the exit status
* @buffer: input buffer
* @av: arguments
* @lines: line number
* return: Nothing
*/
void exitStatus(char *buffer, char **av, int lines)
{
	int num = 0, i;
	char *intCheck;

	if (strncmp(av[0], "exit", 4) == 0)
	{
		for (i = 0; av[i] != NULL; i++)
			num++;
		if (num == 1)
		{
			free(buffer);
			exit(exit_status);
		}
		else
		{
			exit_status = (int)strtol(av[1], &intCheck, 10);
			if (*intCheck == '\0' && atoi(av[1]) >= 0)
			{
				exit_status = atoi(av[1]);
				free(buffer);
				exit(exit_status);
			}
			else
			{
				fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", lines, av[1]);
				free(buffer);
				exit_status = 2;
			}
		}
	}
}

