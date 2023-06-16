#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char** environ;
int input_handle(char **buffer, char *av[2]);
int path(char **av);
int arguments(char **buffer, char **av);
int _fork(char **av);
void _env(void);
#endif
