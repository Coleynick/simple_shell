#include "main.h"
/**
* main - Starting point
* Return: 0 on success
*/
int main(void)
{
	char *av[20], *buffer = NULL;
	int running = 1;
	int exit_status = 0;

	while (running)
	{
		printf("#cisfun$ ");
		if (input_handle(&buffer, av) == -1)
			running = 0;
		else
		{
			if (buffer[0] == '\0' || buffer[0] == '#')
				free(buffer);
			continue;
			if (strncmp(buffer, "exit", 4) == 0)
			{
				tokenArg(buffer, av);
				if (av[1] != NULL)
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
