#include "main.h"

char *token(const char *str, const char *charset);
char *_strtok(char *str, const char *delim);
int is_delim(char c, const char *delim);

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
        int i=0, count_delim = 0;
        char *c;
        for (c=token_end; *c != '\0'; c++)
        {
            if (is_delim (*c,delim) == 0)
            {
                if (is_delim (*(c + 1),delim) == 1 )
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
