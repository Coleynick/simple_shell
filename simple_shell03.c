#include "main.h"
/**
* main - Entry point
* Return: 0 on success
*/
int main(void)
{
char *av[20], *buffer = NULL;
int num = 0, running = 1, input;

while (running)
{
	printf("#cisfun$ ");
	input = input_handle(&buffer, av);
	if (input == -1 || input == 2)
		running = 0;
	if (input != -1)
	{
		if (buffer[0] == '\0')
			continue;
		num = arguments(&buffer, av);
		if (!num)
		{
			if (execve(av[0], av, environ) == -1)
				perror(av[0]);
		}
		else
		{
			running = _fork(av);
		}
	}
}
free(buffer);
return (running ? 0 : -1);
}
