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

	read = getline(buffer, &len, stdin);
	if (read == -1 || (*buffer)[read - 1] != 10)
	{
		return (-1);
	}
	(*buffer)[read - 1] = '\0';
	av[0] = (*buffer);
	av[1] = NULL;
	if (read == 1)
		return (1);
	return (0);
}
