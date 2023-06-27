#include "main.h"
/**
 * set_paths - set paths array
 * @paths: the array
 * @num: number of tokens
 * @dir: tokened string
 */
void set_paths(char **paths, const int num, char *dir)
{
	int i;

	for (i = 0; i < num; i++)
	{
		paths[i] = strdup(dir);
		dir += strlen(dir) + 1;
	}
	paths[i] = NULL;
}
/**
 * free_paths - frees paths array
 * @paths: the array
 * @num: number of tokens
 * @return_val: return value
 * Return: return value
 */
int free_paths(char **paths, int num, int return_val)
{
	int i;

	for (i = 0; i <= num; i++)
		free(paths[i]);
	free(paths);

	return (return_val);
}
/**
 * path - handle the path
 * @av: the path
 * Return: 0 on failure.
 */
int path(char **av)
{
	struct stat st;
	char *p = getenv("PATH"), filepath[256];
	char **paths = malloc(20 * sizeof(char *)), *dir;
	int i, num = 1;

	if (stat((*av), &st) == 0)
		return (1);
	if (p == NULL)
		return (0);
	dir = strdup(p);
	num = tokenize(dir, ':');
	set_paths(paths, num, dir);
	free(dir);
	for (i = 0; i < num; i++)
	{
		strcpy(filepath, paths[i]);
		if (strncmp(filepath, (*av), strlen(filepath)) == 0)
		{
			if (stat((*av), &st) == 0)
				return (free_paths(paths, num, 1));
		}
		else
		{
			strcat(filepath, "/");
			strcat(filepath, (*av));
			if (access(filepath, F_OK) == 0)
			{
				(*av) = strdup(filepath);
				return (free_paths(paths, num, 2));
			}
		}
	}
	return (free_paths(paths, num, 0));
}
