#include "main.h"
/**
* exitStatus - Checks the exit status
* @buffer: input buffer
* @av: arguments
* return: Nothing
*/
void exitStatus(char *buffer, char **av)
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
			if (*intCheck == '\0')
			{
				exit_status = atoi(av[1]);
				free(buffer);
				exit(exit_status);
			}
			else
			{
				_printf("./hsh: exit: Illegal number: %s\n", av[1]);
				free(buffer);
			}
		}
	}
}
