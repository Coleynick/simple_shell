#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char** environ;
int tokenize(char *s, char c);
int input_handle(char **buffer, char **av);
int path(char **av);
int arguments(char **buffer, char **av);
int _fork(char **av);
void _env(void);
void exitStatus(char *buffer, char **av);
int tokenArg(char *buffer, char **av);
#endif
