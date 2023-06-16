#include "main.h"
/**
* main - Entry point
* Return: 0 on success
*/
int main(void)
{
char *av[20], *arg_s, *buffer = NULL;
pid_t pid;
int status, num = 0, running = 1;

while (running)
{
	printf("#cisfun$ ");
	if (input_handle(&buffer, av) == -1)
		running = 0;
	else
	{
		if (buffer[0] == '\0')
			continue;
		arg_s = strtok(buffer, " ");
		while (arg_s != NULL)
		{
			av[num] = arg_s;
			arg_s = strtok(NULL, " ");
			num++;
		}
		av[num] = NULL;
		pid = fork();
		if (pid == 0)
		{
			if (execve(av[0], av, environ) == -1)
				perror(av[0]);
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
return (running ? 0 : 1);
}
