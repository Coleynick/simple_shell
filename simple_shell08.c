#include "main.h"
/**
* tokenArg - Tokenizes the buffer into arguments
* @buffer: input buffer
* @av: arguments
*/
int tokenArg(char *buffer, char **av)
{
	char *arg_s;
	int num = 0;

	if (buffer == NULL || *buffer == '\0')
	{
		av[num] = NULL;
		return (num);
	}
	arg_s = strtok(buffer, " ");
	while (arg_s != NULL)
	{
		av[num] = arg_s;
		arg_s = strtok(NULL, " ");
		num++;
	}
	av[num] = NULL;

	return (num);
}
/**
* main - Starting point
* Return: 0 on success
*/
int main(void)
{
	char *av[20], *intCheck, *buffer = NULL;
	int num = 0, running = 1;
	int exit_status;

	while (running)
	{
		printf("#cisfun$ ");
		if (input_handle(&buffer, av) == -1)
			running = 0;
		else
		{
			if (buffer[0] == '\0')
				continue;
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
			else
			{
				tokenArg(buffer, av);
				running = _fork(av);
			}
		}
	}

	free(buffer);
	return (0);
}
