#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


/**
 * _getline - Read characters from the stream.
 * @lineptr: A buffer to store the characters.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */

ssize_t _getline(char **lineptr, size_t *len, FILE *stream) {
    
    ssize_t nbrCharsRead = 0;
    char c;
    ssize_t r;
    
    if ( *len == 0)
    { 
        *len = 1024;
    }
    
    if (*lineptr == NULL) 
    {
        *lineptr = (char *)malloc(sizeof(char) * *len);

        if (*lineptr == NULL) 
        {
            return (-1);
        }
    }
    
        
    
c='a';
    while (c!='\n') 
    {
        r = read(STDIN_FILENO, &c, 1);

        if (r == -1) 
        {
            free(lineptr);
            return (-1);
            
        } 
        else if (r == 0 && nbrCharsRead== 0)
        {
            free(lineptr);
            return (-1); // No characters read (end of file or error)
           
        }else if (r == 0 && nbrCharsRead != 0)
        {
			nbrCharsRead++;
			break;
		}

        if (nbrCharsRead >= *len - 1) 
        {
           // *len *= 2; // Double the buffer size
            char *new_ptr = (char *)realloc(*lineptr, *len+1);

            if (new_ptr == NULL) 
            {
                return (-1); // Memory allocation error
            }

            *lineptr = new_ptr;
        }

        (*lineptr)[nbrCharsRead++] = c;

        /*if (c == '\n') {
            break;
        }*/
    }

    (*lineptr)[nbrCharsRead] = '\0'; // Null-terminate the string

    return nbrCharsRead;
}
