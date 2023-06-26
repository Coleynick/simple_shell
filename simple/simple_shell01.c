#include "main.h"
/**
 * main - Entry point
 * Description: a program that waits for the user to enter a command
 * Return: 0 on success
 */
int main(void)
{
	char *buffer = NULL, *av[2];
	pid_t pid;
	int status, running = 1, input;

	while (running)
	{
		printf("$ ");
		input = input_handle(&buffer, av);
		if (input == -1 || input == 2)
			running = 0;
		if (input == -1)
			printf("\n");
		if (input != -1)
		{
			if (buffer[0] == '\0')
			{
				free(buffer);
				continue;
			}
			pid = fork();
			if (pid == 0)
			{
				if (execve(av[0], av, environ) == -1)
					perror("./hsh");
				free(buffer);
			}
			else if (pid == -1)
				running = 0;
			else
			{
				wait(&status);
				if (!(WIFEXITED(status) && (WEXITSTATUS(status) == 0)))
				{
					running = 0;
				}
			}
		}
	}
	if (running == 0)
		return (-1);
	return (0);
}
