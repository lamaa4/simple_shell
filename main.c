#include "main.h"

/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: input.
 * @argv: input.
 *
 * Return: The return 0.
 */

int main(int argc, char *argv[])
{
int non_interactive;

int fd, i;

char *line = NULL;
ssize_t read_size;

size_t line_size;

if (argc > 1)
{
fd = open(argv[1], O_RDONLY);

if (fd == -1)
{
perror("open");
return (1);
}
}

if (argc > 1 || !isatty(STDIN_FILENO))
{
non_interactive = 1;
}
line_size = 0;
while (1)
{
pid_t pid;
int nbr_args;
char **args;
char *token;
int arg_count = 0;
read_size = 0;
line = NULL;

if (non_interactive)
{
read_size = _getline(&line, &line_size, fd);

if (read_size == -1 || read_size == 0)
{
break;
}

if (line[read_size - 1] == '\n')
{
line[read_size - 1] = '\0';
}
}
else
{
printf("$ ");
fflush(stdout);

read_size = _getline(&line, &line_size, STDIN_FILENO);

if (read_size == -1 || read_size == 0)
{
break;
}

if (line[read_size - 1] == '\n')
{
line[read_size - 1] = '\0';
}
}
nbr_args = count_tokens(line, " ");

args = malloc(nbr_args *sizeof(char *));

if (args == NULL)
{
return (1);
}

token = _strtok(line, " ");

if (token == NULL)
{
continue;
}

while (token != NULL)
{
args[arg_count] = _strdup(token);

if (args[arg_count] == NULL)
{
perror("strdup");
break;
}

arg_count++;

token = _strtok(NULL, " ");
}

args[arg_count] = NULL;
if (execute_builtin(args[0], args))
{
for (i = 0; i < arg_count; i++)
{
free(args[i]);
}
free(line);
continue;
}

pid = fork();

if (pid == 0)
{
cmd_execute(args[0], args);
/*perror("execve");*/
exit(EXIT_FAILURE);
}

else if (pid < 0)
{
perror("fork");
}
else
{
waitpid(pid, NULL, 0);
}

if (non_interactive == 0)
{
for (i = 0; i < arg_count; i++)
{
free(args[i]);
}
free(args);

free(line);
}
}

if (line)
{
free(line);
}

if (non_interactive == 1)
{
close(fd);
}

return (0);

}
