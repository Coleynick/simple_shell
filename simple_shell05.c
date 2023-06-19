#include "main.h"
/**
* check_in - Entry point
* @input: input
* @running: running
* Return: 0 on success
*/
void check_in(int input, int *running)
{
	if (input == -1)
		*running = 0;
	else if (input == 2)
		*running = 1;
}
/**
* exe_not_found - Entry point
* @av: args
* @buffer: input
* @hsh: shell name
* Return: 0 on success
*/
void exe_not_found(char **av, char **buffer, char *hsh)
{
	if (execve(av[0], av, environ) == -1)
		perror(hsh);
	free(*buffer);

}
/**
* main - Entry point
* @argc: num of args
* @argv: argis
* Return: 0 on success
*/
int main(int argc, char **argv)
{
char *av[20] = {NULL}, *buffer = NULL;
int num = 0, running = 1, input = 0;

(void) argc;
while (running)
{
	if (input != 2)
		printf("#cisfun$ ");
	input = input_handle(&buffer, av);
	check_in(input, &running);
	if (input != -1)
	{
		if (buffer[0] == '\0')
			continue;
		if (strcmp(buffer, "env") == 0)
		{
			_env();
			free(buffer);
			continue;
		}
		if (strcmp(buffer, "exit") == 0)
			break;
		num = arguments(&buffer, av);
		if (!num)
			exe_not_found(av, &buffer, argv[0]);
		else
		{
			running = _fork(av);
			free(buffer);
			if (num == 2)
				free(av[0]);
			check_in(input, &running);
		}
	}
}
free(buffer);
if (input == 2)
	printf("#cisfun$ ");
return (running ? 0 : -1);
}
