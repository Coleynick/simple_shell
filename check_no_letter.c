#include "main.h"
/**
 * check_empty - Entry point
 * Description: print env vars
 * Return: nothing
 */
int check_empty(void)
{
	int i = 0;

	for (; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
			return (0);
	}
	return (1);
}
