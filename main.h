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
char *_strndup(const char *src, size_t start_pos, size_t n);

/* Tokenize functions */
char *token(const char *str, const char *charset);
char *_strtok(char *str, const char *delim);
int is_delim(char c, const char *delim);

#endif
