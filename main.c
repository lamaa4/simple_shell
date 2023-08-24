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
FILE *input_file = NULL;

int non_interactive = 0;

int fd, i;

char *line = NULL;

size_t line_size;

if (argc > 1)
{
fd = open(argv[1], O_RDONLY);

if (fd == -1)
{
perror("open");
return (1);
}
non_interactive = 1;
}
line_size = 0;
while (1)
{
pid_t pid;
int nbr_args;
char *token;
int arg_count = 0;

char **args;

if (non_interactive)
{
ssize_t read_size;

read_size = _getline(&line, &line_size, fd);

if (read_size == -1)
{
write(STDOUT_FILENO, "\n", 1);
break;
}

if (line[read_size - 1] == '\n')
{
line[read_size - 1] = '\0';
}
}
else
{
ssize_t read_size;

write(STDOUT_FILENO, "$ ", 2);

read_size = _getline(&line, &line_size, STDIN_FILENO);

if (read_size == -1)
{
write(STDOUT_FILENO, "\n", 1);
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
perror("execve");
exit(1);
}

else if (pid < 0)
{
perror("fork");
}
else
{
waitpid(pid, NULL, 0);
}

for (i = 0; i < arg_count; i++)
{
free(args[i]);
}
}

if (line)
{
free(line);
}

if (non_interactive)
{
fclose(input_file);
}

return (0);

}
