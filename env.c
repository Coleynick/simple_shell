#include "main.h"
/**
 * _env - Entry point
 * Description: print env vars
 * Return: nothing
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
		printf("%s\n", environ[i++]);
}
/**
 * _setenv - Entry point
 * Description: set env vars
 * @buffer: buffer
 * @av: arguments
 * @shell: shell name
 * Return: 1 on success
 */
int _setenv(char **buffer, char **av, char *shell)
{
	int i = 0, num = 0, err;

	if (strncmp("setenv", *buffer, 6))
		return (0);
	for (; av[i] != NULL; i++)
		num++;
	if (num != 3)
	{
		dprintf(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n");
	}
	else
	{
		err = setenv(av[1], av[2], 1);
		if (err == -1)
			perror(shell);
	}
	free(*buffer);
	return (1);
}

/**
 * _unsetenv - Entry point
 * Description: set env vars
 * @buffer: buffer
 * @av: arguments
 * @shell: shell name
 * Return: 1 on success
 */
int _unsetenv(char **buffer, char **av, char *shell)
{
	int i = 0, num = 0, err;

	if (strncmp("unsetenv", *buffer, 8))
		return (0);
	for (; av[i] != NULL; i++)
		num++;
	if (num != 2)
	{
		dprintf(STDERR_FILENO, "Usage: unsetenv VARIABLE\n");
	}
	else
	{
		err = unsetenv(av[1]);
		if (err == -1)
			perror(shell);
	}
	free(*buffer);
	return (1);
}
