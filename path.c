#include "main.h"
/**
 * path - handle the path
 * @av: the path
 * Return: 0 on failure.
 */
int path(char **av)
{
	struct stat st;
	char *s = getenv("PATH");
	char filepath[265];
	char *dir = strtok(s, ":");

	while (dir != NULL)
	{
		strcpy(filepath, dir);
		if (strncmp(filepath, *(av), strlen(filepath)) == 0)
		{
			if (stat((*av), &st) == 0)
				return (1);
		}
	else
	{
		strcat(filepath, "/");
		strcat(filepath, (*av));
		if (stat(filepath, &st) == 0)
		{
			(*av) = strdup(filepath);
			return (1);
		}
	}
	dir = strtok(NULL, ":");
	}
	return (0);
}
