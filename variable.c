#include "main.h"
/**
 * variables - Substitute tokens with values
 * @tokens: Token array
 * @exit_status: Value of exit status
 */
void variables(char **tokens, int exit_status)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		if (strcmp(tokens[i], "$?") == 0)
		{
			free(tokens[i]);
			tokens[i] = malloc(12);
			snprintf(tokens[i], 12, "%d", exit_status);
		}
		else if (strcmp(tokens[i], "$$") == 0)
		{
			free(tokens[i]);
			tokens[i] = malloc(12);
			snprintf(tokens[i], 12, "%d", getpid());
		}
	}
}
