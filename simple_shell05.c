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
* check_enter - Entry point
* @buffer: buffer
* Return: 1 on success
*/
int check_enter(char **buffer)
{
	if (*buffer[0] == '\0')
	{
		free(*buffer);
		return (1);
	}
	return (0);
}
/**
 * prepare_arguments - prepare argument list
 * @buffer: buffer
 * @av: first arg
 * @p: path
 * Return: path
 */
char *prepare_arguments(char **buffer, char **av, char *p)
{
	if (strcmp(*buffer, av[0]))
	{
		p = strdup(av[0]);
		free(av[0]);
		av[0] = strdup(*buffer);
	}
	else
		p = av[0];
	return (p);
}
/**
* main - Entry point
* @argc: num of args
* @argv: argis
* Return: 0 on success
*/
int main(int argc, char **argv)
{
char *av[20] = {NULL}, *buffer = NULL, *p;
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
		if (check_enter(&buffer))
			continue;
		if (strcmp(buffer, "env") == 0)
		{
			_env();
			free(buffer);
			continue;
		}
		num = arguments(&buffer, av);
		exitStatus(buffer, av);
		if (!num)
			exe_not_found(av, &buffer, argv[0]);
		else
		{
			p = prepare_arguments(&buffer, av, p);
			running = _fork(av, argv[0], p);
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
