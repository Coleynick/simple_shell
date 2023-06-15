#include <unistd.h>
/**
 * main - Starting point
 * Return: Successful if 0
 */

int main(void)
{
	char c[5] = {'C', 'h', 'i', 'n', 'a'};

	for (x = 0; x < 5; x++)
	{
		write(1, &c[x], sizeof(char));
	}
	write(1, "\n", 1);
	return (0);
}
