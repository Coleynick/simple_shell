#include "main.h"
#include <ctype.h>
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
			if (av[1][0] == '-')
			{
				fprintf(stderr, "./hsh: exit: Illegal number: %s\n", av[1]);
				free(buffer);
				exit(2);
			}
				exit_status = 0;
				for (i = 0; av[1][i] != '\0'; i++)
				{
					if (!isdigit(av[1][i]))
					{
						fprintf(stderr, "./hsh: exit: Illegal number: %s\n", av[1]);
						free(buffer);
						exit(2);
					}
				exit_status = exit_status * 10 + (av[1][i] - '0');
				}
				free(buffer);
				exit(exit_status);
		}

	}
}
