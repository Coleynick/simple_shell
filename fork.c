#include "main.h"
/**
 * _fork - Entry point
 * Description: to craete a child process
 * Return: int
 */
int _fork(char **av)
{
	pid_t pid;
	int r = 1;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(av[0], av, environ) == -1)
			perror(av[0]);
	}
	else if (pid == -1)
		return (0);
	wait(&status);
	if (!(WIFEXITED(status) && (WEXITSTATUS(status) == 0)))
		r = 0;
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		r = 1;

	return (r);
}
