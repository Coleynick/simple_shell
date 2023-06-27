#include "main.h"
/**
* check_in - Entry point
* @input: input
* @running: running
* @buffer: buffer
* Return: 0 on success
*/
void check_in(int input, int *running, char **buffer)
{
	if (input == -1)
	{
		*running = 0;
		free(*buffer);
	}
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

int _setenv(char **buffer, char **av, char *shell);
int _unsetenv(char **buffer, char **av, char *shell);
/**
* main - Entry point
* @argc: num of args
* @argv: argis
* Return: 0 on success
*/
int main(int argc, char **argv)
{
char *av[20] = {NULL}, *p;
int num = 0, running = 1, input = 0, lines = 0;

buffer = NULL;
signal(SIGINT, sigint_handler);
(void) argc;
do {
	if (isatty(STDIN_FILENO))
		_printf("#cisfun$ ");
	else
		lines++;
	input = input_handle(&buffer, av);
	check_in(input, &running, &buffer);
	if (input != -1)
	{
		if (check_enter(&buffer) || check_empty())
			continue;
		if (strcmp(buffer, "env") == 0)
		{
			_env();
			free(buffer);
			continue;
		}
		num = arguments(&buffer, av);
		if (_setenv(&buffer, av, argv[0]) || _unsetenv(&buffer, av, argv[0]))
			continue;
		if (strncmp(av[0], "exit", 4) == 0)
		{
			exitStatus(buffer, av);
			continue;
		}
		if (!num && lines)
			_printf("%s: %d: %s: not found\n", argv[0], lines, av[0]);
		else if (!num)
		{
			exe_not_found(av, &buffer, argv[0]);
			exit_status = 127;
		}
		else
		{
			if (strncmp("echo", buffer, 4) == 0)
			{
				free(buffer);
				free(av[0]);
				continue;
			}
			p = prepare_arguments(&buffer, av, p);
			running = _fork(av, argv[0], p, &exit_status);
			free(buffer);
			if (num == 2)
				free(av[0]);
			check_in(input, &running, &buffer);
		}
	}
} while (running);
return (0);
}
