#include "main.h"
/**
 * _getline - Entry point
 * Description: print env vars
 * @lineptr: line buffer
 * @n: length
 * @stream: stream
 * Return: length
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t i = 0;
	char c;
	int r;

	(void) stream;
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	*n = 1024;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
		return (-1);
	fflush(stdout);
	(*lineptr)[0] = '\0';
	for (i = 0; ; i++)
	{
		if (strlen(*lineptr) == *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		r = read(STDIN_FILENO, &c, 1);
		if (r == 0 && i == 0)
			return (-1);
		else if (r == 0)
		{
			i--;
			continue;
		}
		if (c == 10)
		{
			(*lineptr)[i] = c;
			return (i + 1);
		}
		(*lineptr)[i] = c;
		(*lineptr)[i + 1] = '\0';
	}
	return (-1);
}