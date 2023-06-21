#include "main.h"
/**
* tokenArg - Tokenizes the buffer into arguments
* @buffer: input buffer
* @av: arguments
* Return: Num
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
