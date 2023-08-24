#include "main.h"

int print_env(const char *cmd);

/**
 * print_env - print env
 * @cmd: input
 */

int print_env(const char *cmd)
{
	char **env = environ;
	int i;
	
	if (!env)
		return (-1);
	(void) cmd;        
	for (i = 0; env[i] != NULL; i++)
	{
        printf("%s\n", env[i]);
        fflush(stdout);
	}
        return (0);
}
