#include "main.h"
/**
 * sigint_handler - Entry point
 * Description: free buffer when ctrl c is pressed
 * @sig: signal
 * Return: nothing
 */
void sigint_handler(int sig){
	(void) sig;
	free(buffer);
	exit(0);
}
