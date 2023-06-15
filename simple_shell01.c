#include "main.h"
extern char** environ;
/**
 * main - Entry point
 * Description: a program that waits for the user to enter a command, prints it on the next line
 * Return: 0 on success
 */
int main(void)
{
	size_t len = 0;
	ssize_t read;
	char *buffer = NULL;
	char *av[2];
	pid_t pid;
	int status;
	int running = 1;

	while (running)
	{
		printf("$ ");
		read = getline(&buffer, &len, stdin);
		if (read == -1)
		{
			running = 0;
			printf("\n");
		}
		else
		{
			if (buffer[read - 1] != 10)
			{
				printf("\n");
				running = 0;
			}
			else
			{
				buffer[read - 1] = '\0';
				av[0] = buffer;
				av[1] = NULL;
				if (read == 1)
					continue;
				pid = fork();
				if (pid == 0)
					/*child process*/
				{
					if (execve(av[0], av, environ) == -1)
					{
						perror("./simple_shell");
    					}
				}
				else if (pid == -1)
				{
					running = 0;
				}
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
	}
	free(buffer);
	if (running == 0)
	{
		return (-1);
	}
	return (0);
}
