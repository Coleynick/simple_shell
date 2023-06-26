#include "main.h"

/**
* input_handle - Entry point
* @buffer: Contains user input
* @av: String array for command args
* Description: Prog waits for user to enter command, prints it on the next line
* Return: 0 on success
*/
int input_handle(char **buffer, char *av[])
{
	size_t len = 0;
	ssize_t read;
	char *endCommand;

	read = _getline(buffer, &len, stdin);
	if (read == -1 || (*buffer)[read - 1] != 10)
	{
		return (-1);
	}
	(*buffer)[read - 1] = '\0';
	endCommand = strchr(*buffer, '#');
	if (endCommand != NULL)
	{
		*endCommand = '\0';
	}
	av[0] = (*buffer);
	av[1] = NULL;
	if (read == 1)
		return (1);
	if (!isatty(STDIN_FILENO))
	{
		return (2);
	}
<<<<<<< HEAD
	tokens = toks(*buffer, ' ');
	if (strcmp(tokens[0], "echo") == 0)
	{
		variables(tokens, exit_status);
		for (i = 1; tokens[i] != NULL; i++)
		{
			_printf("%s", tokens[i]);
		}
		_printf("\n");
	}
	freeToks(tokens);
=======
>>>>>>> 6641ec2d1ee6d9acb54e446ed2b96cf14421a700
	return (0);
}
