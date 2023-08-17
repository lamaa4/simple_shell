#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/* Main */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *);

#endif
