#include "main.h"
/**
 * main - Entry point
 * Description: a program that waits for the user to enter a command
 * Return: 0 on success
 */
int main(void)
{
	char *buffer = NULL;
	char *av[2];
	pid_t pid;
	int status, running = 1;

	while (running)
	{
		printf("$ ");
		if (input_handle(&buffer, av) == -1)
			running = 0;
		else
		{
			if (buffer[0] == '\0')
				continue;
			pid = fork();
			if (pid == 0)
			{
				if (execve(av[0], av, environ) == -1)
					perror("./simple_shell");
			}
			else if (pid == -1)
				running = 0;
			else
			{
				wait(&status);
				if (!(WIFEXITED(status) && (WEXITSTATUS(status) == 0)))
					running = 0;
			}
		}
	}
	free(buffer);
	if (running == 0)
		return (-1);
	return (0);
}
