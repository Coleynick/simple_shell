#include "main.h"
/**
 * toks - Tokenize a string using a delimiter as base
 * @buffer: String to tokenize
 * @delimiter: Delimiter character
 * Return: An array of tokens
 */
char **toks(char *buffer, char delimiter)
{
	char *token, *cpyBuffer = strdup(buffer);
	char **toks = NULL, *pbuffer = cpyBuffer;
	size_t count = 0;

	while ((token = strsep(&pbuffer, &delimiter)) != NULL)
	{
		toks = realloc(toks, (count + 1) * sizeof(char *));
		toks[count] = strdup(token);
		count++;
	}
	toks = realloc(toks, (count + 1) * sizeof(char *));
	toks[count] = NULL;
	free(cpyBuffer);
	return (toks);
}

/**
 * freeToks - Free memory allocated for toks
 * @toks: Tokens array to free
 */
void freeToks(char **toks)
{
	int i;

	for (i = 0; toks[i] != NULL; i++)
	{
		free(toks[i]);
	}
	free(toks);
}

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
	char *endCommand, **tokens;
	int i;

	read = _getline(buffer, &len, stdin);
	if (read == -1 || (*buffer)[read - 1] != 10)
	{
		return (-1);
	}
	(*buffer)[read - 1] = '\0';
	endCommand = strchr(*buffer, '#');
	if (endCommand != NULL && endCommand[-1] == ' ')
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
	tokens = toks(*buffer, ' ');
	if (strcmp(tokens[0], "echo") == 0)
	{
		variables(tokens, &exit_status);
		for (i = 1; tokens[i] != NULL; i++)
		{
			printf("%s", tokens[i]);
		}
		printf("\n");
	}
	freeToks(tokens);
	return (0);
}
