#include "main.h"

/**
*print_strings - Entrypoint
*Description : to checkifletterisuppercase
*@s:param
*Return:int
*/


int print_strings(char *s)
{
char *z = "(null)";
int i = 0;
int n = 0;

if (s == NULL)
while (z[i])
{
n += _putchar(z[i]);
i++;
}
else
while (s[i])
{
n += _putchar(s[i]);
i++;
}
return (n);
}
