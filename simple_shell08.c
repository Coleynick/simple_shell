#include "main.h"
/**
* tokenArg - Tokenizes the buffer into arguments
* @buffer: input buffer
* @av: arguments
*/
void tokenArg(char *buffer, char **av)
{
	char *arg_s = strtok(buffer, " ");
	int num = 0;

	while (arg_s != NULL)
	{
		av[num] = arg_s;
		arg_s = strtok(NULL, " ");
		num++;
	}
	av[num] = NULL;
}
/**
* main - Starting point
* Return: 0 on success
*/
int main(void)
{
	char *av[20], *buffer = NULL;
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
			if (strcmp(buffer, "exit") == 0)
			{
				tokenArg(buffer, av);
				if (num >= 2)
				{
					exit_status = atoi(av[1]);
					exit(exit_status);
				}
				else
				{
					exit(0);
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
