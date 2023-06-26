#include "main.h"
/**
 * _fork - Entry point
 * Description: to craete a child process
 * @av: arguments
 * @p: path
 * @shell: argv[0]
 * @exit_status: Value of exit status
 * Return: int
 */
int _fork(char **av, char *shell, char *p, int *exit_status)
{
	pid_t pid;
	int r = 1;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(p, av, environ) == -1)
			perror(shell);
	}
	else if (pid == -1)
		return (0);
	wait(&status);
	if (WIFEXITED(status))
	{
		*exit_status = WEXITSTATUS(status);
		if (*exit_status != 0)
		r = 1;
	}
	else
	{
		r = 0;
	}
	if (strcmp(p, av[0]))
		free(p);
	return (r);
}
