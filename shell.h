#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* shell.c module */
void fork_cmd(char **argv);

/* strtok.c module */
char **mystrtok(char *str, char *delim);

/* string.c module */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int starts_with(const char *haystack, const char *needle);

/* env.c module */
char *_getenv(const char *name);

#endif
