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
#include <stdarg.h>
extern char **environ;
char *buffer;
int check_empty(void);
void sigint_handler(int sig);
int _printf(const char *format, ...);
int _putchar(char c);
int print_strings(char *s);
int print_number(int n);
int tokenize(char *s, char c);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int input_handle(char **buffer, char **av);
int path(char **av);
int arguments(char **buffer, char **av);
int _fork(char **av, char *shell, char *p);
void _env(void);
void variables(char **tokens, int exit_status);
int input(char **buffer, char *av[]);
void exitStatus(char *buffer, char **av);
int tokenArg(char *buffer, char **av);
#endif
