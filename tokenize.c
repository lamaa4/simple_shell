#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *token(const char *str, const char *charset);
char *_strtok(char *str, const char *delim);
int is_delim(char c, const char *delim);
int count_tokens(char *str, char *delim);
int token_len(char *str, char *delim);

int is_delim(char c, const char *delim)
{
    
    while (*delim != '\0')
    {
        if (c == *delim)
        {
            return 0;
        }
        delim++;
    }
    return 1;
}

char *token(const char *str, const char *delim)
{
     int i=0, j;

    while ( str[i] != '\0') 
    {
        for ( j = 0; delim[j] != '\0'; j++)
        {
            if (str[i] == delim[j]) 
            {
                return (char *)(str+i);
            }
        }
        
        i++;
    }
    return NULL;
}

char *_strtok(char *str, const char *delim)
{
    static char *saveptr = NULL;
    char *token_start = NULL;
    int delim_len = _strlen(delim);

    if (str != NULL)
    {
        saveptr = str;
    }

    if (saveptr == NULL || *saveptr == '\0')
    { 
        return NULL;
    }

    char *token_end = token(saveptr, delim);

    if (token_end != NULL) 
    {
        int count_delim = 0;
        char *c;
        for (c=token_end; *c != '\0'; c++)
        {
            if (is_delim(*c,delim) == 0)
            {
                if (is_delim(*(c + 1),delim) == 1 )
                {
                    break;
                }
                count_delim++;
        }
       
   }
   
   *token_end = '\0'; 
   token_start = saveptr;
   saveptr = c + 1;
        
    } 
    else 
    {
        token_start = saveptr;
        saveptr = NULL;
        
    }
    
    return token_start;
}

/**
 * nbr_tokens - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int count_tokens(char *str, char *delim)
{
		int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += token_len(str + index, delim);
		}
	}

	return (tokens);
}

/**
 * token_len - Locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */
int token_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}
