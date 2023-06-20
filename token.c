#include "main.h"
/**
 * tokenize - Entry point
 * Description: tokenizes string
 * @s: string
 * @c: seperator
 * Return: num of tokens
 */
int tokenize(char *s, char c)
{
	int i, num = 1;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
		{
			num++;
			s[i] = '\0';
		}
	}
	return (num);
}
