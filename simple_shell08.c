#include "main.h"
/**
* main - Starting point
* Return: 0 on success
*/
int main(void)
{
	char *av[20], *buffer = NULL;
	int running = 1;

	while (running)
	{
		printf("#cisfun$ ");
		if (input_handle(&buffer, av) == -1)
			running = 0;
		else
		{
			if (buffer[0] == '\0')
				continue;
			exitStatus(buffer, av);
		}
		if (running)
		{
			tokenArg(buffer, av);
		}
	}

	free(buffer);
	return (0);
}
