#include "main.h"
/**
 * _env - Entry point
 * Description: print env vars
 * Return: nothing
 */
void _env(void)
{
	int i = 0;

	while(environ[i])
		printf("%s\n", environ[i++]);
}
