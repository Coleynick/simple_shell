#include "main.h"
/**
* tokenArg - Tokenizes the buffer into arguments
* @buffer: input buffer
* @av: arguments
* Return: Num
*/
int tokenArg(char *buffer, char **av)
{
	char *arg_s;
	int num = 0;

	if (buffer == NULL || *buffer == '\0')
	{
		av[num] = NULL;
		return (num);
	}
	arg_s = strtok(buffer, " ");
	while (arg_s != NULL)
	{
		av[num] = arg_s;
		arg_s = strtok(NULL, " ");
		num++;
	}
	av[num] = NULL;
	return (num);
}
