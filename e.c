#include "main.h"
void echoCommand(char *buffer, char **av)
{
    int exit_status = atoi(av[1]);
    char *exitStr = "$?";
    char *pidStr = "$$";
    char exitBuffer[10];
    char pidBuffer[10];
    size_t exitSlen, pidSlen;
    char *ss = strstr(buffer, exitStr);

    if (ss != NULL)
    {
        snprintf(exitBuffer, sizeof(exitBuffer), "%d", exit_status);
        exitSlen = strlen(exitStr);
        memmove(ss + exitSlen, ss + exitSlen + 1, strlen(ss + exitSlen + 1) + 1);
        memcpy(ss, exitBuffer, strlen(exitBuffer));
    }

    ss = strstr(buffer, pidStr);
    if (ss != NULL)
    {
        snprintf(pidBuffer, sizeof(pidBuffer), "%d", getpid());
        pidSlen = strlen(pidStr);
        memmove(ss + pidSlen, ss + pidSlen + 1, strlen(ss + pidSlen + 1) + 1);
        memcpy(ss, pidBuffer, strlen(pidBuffer));
    }
}

