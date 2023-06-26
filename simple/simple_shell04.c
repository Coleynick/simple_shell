#include "main.h"
/**
* main - Entry point
* Return: 0 on success
*/
int main(void)
{
	char *av[20], *arg_s, *buffer = NULL;
	pid_t pid;
	int status, num = 0, running = 1, input;
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
			if (strcmp(buffer, "exit") == 0)
				break;
			arg_s = strtok(buffer, " ");
			for (num = 0; arg_s != NULL; num++)
			{
				av[num] = arg_s;
				arg_s = strtok(NULL, " ");
			}
			av[num] = NULL;
			pid = fork();
			if (pid == 0)
			{
				if (execvp(av[0], av) == -1)
				{
					perror(av[0]);
					exit(EXIT_FAILURE);
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
					running = 0;
			}
		}
	}
	free(buffer);
	return (running ? 0 : 1);
}
