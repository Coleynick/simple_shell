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
			if (strcmp(av[0], "exit") == 0)
			{
				exitStatus(buffer, av);
				running = 0;
			}
			else if (strncmp(buffer, "echo", 4) == 0)
			{
				echoCommand(buffer, av);
			}
			else
			{
				tokenArg(buffer, av);
				running = _fork(av, "./simple_shell", av[0]);
			}
		}
	}
	free(buffer);
	return (0);
}
