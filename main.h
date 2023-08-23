#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <sys/wait.h>

extern char **environ;

/* Main functions */
ssize_t _getline(char **lineptr, size_t *len, int fd);

/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, char *s2);
char *_strdup(const char *);
char *_strcpy(char *dest, const char *src);

/* Tokenize functions */
char *token(const char *str, const char *charset);
char *_strtok(char *str, const char *delim);
int is_delim(char c, const char *delim);
int count_tokens(char *str, char *delim);
int token_len(char *str, char *delim);

/* Execute functions */
int execute_builtin(const char *command, char *const args[]);
char *_strchr(const char *str, int character);
int cmd_execute(const char *filename, char *const argv[]);

#endif
