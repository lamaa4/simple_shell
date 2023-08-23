#include "main.h"

int main(int argc, char *argv[])
{
        FILE *input_file = NULL;
        int non_interactive = 0;
        int fd;
        
        if (argc > 1)
        {
                fd = open(argv[1], O_RDONLY);
                            if (fd == -1)
                            {
                                    perror("open");
                                    return 1;
                            }
                            non_interactive = 1;
                
        }
        char *line = NULL;
        size_t line_size = 0;

        while (1)
        {
                if (non_interactive)
                {
                        ssize_t read_size = _getline(&line, &line_size, fd);
                        if (read_size == -1)
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
                                ssize_t read_size = _getline(&line, &line_size, STDIN_FILENO);
                                if (read_size == -1)
                                {
                                        break;
                                }
                                if (line[read_size - 1] == '\n')
                                {
                                        line[read_size - 1] = '\0';
                                }
                        }
                        
                        int ARGS = count_tokens(line, " ");
                        char *args[ARGS];
                        int arg_count = 0;
                        
                        char *token = _strtok(line, " ");
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
                                for (int i = 0; i < arg_count; i++)
                                {
                                        free(args[i]);
                                }
                                
                                if (line != NULL)
                                {
                                        free(line);
                                }
                                continue;
                        }
                        
                        pid_t pid = fork();
                        if (pid == 0)
                        {
                                cmd_execute(args[0], args);
                                perror("execve");
                                exit(1);
                                
                        } else if (pid < 0)
                        {
                                perror("fork");
                        } 
                        else
                        {
                                waitpid(pid, NULL, 0);
                        }
                        
                        
                        for (int i = 0; i < arg_count; i++)
                        {
                                free(args[i]);
                        }
    }
    
    if (line != NULL)
    {
            free(line);
    }
    
    if (non_interactive)
    {
            fclose(input_file);
    }

    return 0;
}
