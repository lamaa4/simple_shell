#include "main.h"

int execute_builtin(const char *command, char *const args[]);
char *_strchr(const char *str, int character);
int cmd_execute(const char *filename, char *const argv[]);

/**
 * _strchr - Found a character in the string
 * @str: The string
 * @character: The character
 *
 * Return: The character
 */
    
char *_strchr(const char *str, int character)
{
        while (*str != '\0')
        {
                if (*str == character)
                {
                        return (char *)str;
                }
                str++;
        }
        
        return NULL;
}

/**
 * execute_builtin - Execute built-in commands
 * @cmd: The command
 * @args: The arguments
 *
 * Return: Execute built-in commands
 */
  
int execute_builtin(const char *cmd, char *const args[])
{
        if (_strcmp(cmd, "exit") == 0)
        {
                exit(0);
                
        }
        else if (_strcmp(cmd, "cd") == 0)
        {
                if (args[1] != NULL)
                {
                        if (chdir(args[1]) != 0)
                        {
                                perror("cd");
                        }
                }
                return 1;
        }
        return 0;
}

/**
 * cmd_execute - Execute the command using execve
 * @cmd: The command
 * @filename: The file name
 *
 * Return: Execute the command
 */
  
int cmd_execute(const char *filename, char *const argv[]) 
{
        if (_strchr(filename, '/') != NULL)
        {
                return execve(filename, argv, NULL);
        }
        else
        {
                char *path_env;
                path_env = getenv("PATH");
                
                if (path_env == NULL)
                {
                        perror("getenv");
                        return -1;
                }
                else
                {
                        int nbr_paths;
                        int dir_len, cmd_len;
                        
                        nbr_paths = count_tokens(path_env, ":");
                        char *path_dirs[nbr_paths], *cmd_path;
                        
                        if (nbr_paths == 0)
                        {
                                return (-1);
                        }
                                                                   
                        char *token = _strtok(path_env, ":");
                        int dir_count = 0;
                        cmd_len = _strlen(filename);
                        
                        while (token != NULL && dir_count < nbr_paths)
                        {
                                struct stat st;
                                path_dirs[dir_count] = token;
                                
                                dir_len = _strlen(token);
                                cmd_path = malloc(cmd_len + dir_len + 2);
                                
                                _strcpy(cmd_path, token);
                                _strcat(cmd_path, "/");
                                _strcat(cmd_path, filename);
                                _strcat(cmd_path, "\0");
                                
                                if (stat(cmd_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
                                {
                                        return execve(cmd_path, argv, NULL);
                                }
                                else
                                {
                                        free(cmd_path);
                                        token = _strtok(NULL, ":");
                                        dir_count++;
                                }
                        }
                        return -1;
                }
                
        }
        return -1;
        
} 
