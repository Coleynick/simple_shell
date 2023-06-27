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
	int exit_status;

	if (strncmp(av[0], "exit", 4) == 0)
	{
		for (i = 0; av[i] != NULL; i++)
			num++;
		if (num == 1)
		{
			free(buffer);
			exit(0);
		}
		else
		{
				exit_status = atoi(av[1]);
				if (exit_status == 0 && av[1][0] != '0')
				{
				_printf("./hsh: exit: Illegal number: %s\n", av[1]);
				free(buffer);
				exit(2);
				}
				else
				{
					free(buffer);
					exit(exit_status);
				}
		}
	}
}
