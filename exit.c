#include "main.h"
/**
* exitStatus - Checks the exit status
* @buffer: input buffer
* @av: arguments
* return: Nothing
*/
void exitStatus(char *buffer, char **av)
{
	int num = 0, exit_status;
	char *intCheck;

	if (strncmp(buffer, "exit", 4) == 0)
	{
		num = tokenArg(buffer, av);
		if (num == 1)
		{
			exit(0);
		}
		else if (num == 2)
		{
			exit_status = (int)strtol(av[1], &intCheck, 10);
			if (*intCheck == '\0')
				exit(exit_status);
			else
				printf("Invalid exit status\n");
		}
		else
		{
			printf("Error: More than two arguments\n");
		}
	}
}
