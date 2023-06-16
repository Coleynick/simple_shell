#include "main.h"
/**
 * path - handle the path
 * @av: the path
 * Return: 0 on failure.
 */
int path(char **av)
{
	struct stat st;
	char *s = getenv("PATH"), filepath[265];
	char *dir = strtok(s, ":"), *paths[20];
	int num = 0;
	static int first = 1;

	if (first == 1)
	{
		while (dir != NULL)
		{
			paths[num] = dir;
			num++;
			dir = strtok(NULL, ":");
		}
		paths[num] = NULL;
		first = 2;
	}
	num = 0;
	while (paths[num] != NULL)
	{
		strcpy(filepath, paths[num]);
		if (strncmp(filepath, (*av), strlen(filepath)) == 0)
		{
			if (stat((*av), &st) == 0)
				return (1);
		}
		else
		{
			strcat(filepath, "/");
			strcat(filepath, (*av));
			if (access(filepath, F_OK) == 0)
			{
				(*av) = strdup(filepath);
				return (1);
			}
		}
		num++;
	}
	return (0);
}
