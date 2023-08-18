/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "main.h"
#include<string.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int tokenizeInput(const char *input, char *tokens[]);







/**
 * 
 * strtok
 * 
 * 
 * 
 * */
 
 











char *my_strtokpbrk(char *str, const char *delim) {
    static char *saveptr = NULL;

    if (str != NULL) {
        saveptr = str;
    }

    if (saveptr == NULL || *saveptr == '\0') {
        return NULL;
    }

    char *token_start = saveptr;
    char *token_end = strpbrk(token_start, delim);

    if (token_end != NULL) {
        *token_end = '\0';
        saveptr = token_end + 1;
    } else {
        saveptr = NULL;
    }

    return token_start;
}

/*int main() {
    char input[] = "Hello,World! This is,a,test";
    const char delim[] = ", ";
    
    char *token = my_strtok(input, delim);
    while (token != NULL) {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}*/









char *my_strtok(char *str, const char *delim) {
    static char *saveptr = NULL;
    char *token_start = NULL;
    int is_delim = 0;
    char **tokens;

    if (str != NULL) {
        saveptr = str;
    }

    if (saveptr == NULL || *saveptr == '\0') {
        return NULL;
    }

int str_len=strlen(str),delim_len=strlen(delim),start_token=0,token_len=0;
int tokens_count=0;
for (int i=0;i<str_len;i++){
    for (int j=0;j<delim_len;j++){
    if(str[i]==delim[j])
    {
  
 
  printf("\ntoken_len=%d, start_token=%d\n",token_len,start_token);
  write(1,&str[start_token],token_len);
        if(token_len!=0 && j==delim_len-1){
            start_token=i+1;
            tokens_count++;
        tokens=(char **)realloc(tokens, tokens_count * sizeof(char *));
        tokens[tokens_count-1]=_strndup(str,  start_token,token_len);

        printf("\n");
        start_token=i+1;
        token_len=0;
        break;}
        break;
    } if(j==delim_len-1){
    token_len++;

    }
}
}
        tokens_count++;
        tokens=(char **)realloc(tokens, tokens_count * sizeof(char *));
        tokens[tokens_count-1]=_strndup(str,  start_token,token_len);

  printf("\ntoken_len=%d, start_token=%d\n",token_len,start_token);
  write(1,&str[start_token],token_len);
printf("\nstr_len = %d, delim_len = %d, tokens_count = %d\n",str_len,delim_len,tokens_count);

for(int i= 0 ; i< tokens_count; i++)
printf("String %d: %s\n", i, tokens[i]);

exit(0);

    while (*saveptr != '\0') {
        for (int i = 0; delim[i] != '\0'; i++) {
            if (*saveptr == delim[i]) {
                *saveptr = '\0';
                is_delim = 1;
                break;
            }
        }

        if (is_delim) {
            is_delim = 0;
            if (token_start == NULL) {
                token_start = saveptr + 1;
            }
        } else if (token_start != NULL) {
            break;
        }

        saveptr++;
    }

    if (token_start == NULL) {
        return NULL;
    }

    return token_start;
}

int main() {
    char input[] = "Hello,World! This is,a,test \nhi every one   lol\n \n      , ,  ";
    const char delim[] = ", \n";
    
     char input1[] = "Hello,World! This is,a,test";
    const char delim1[] = ", ";
    
    char *token = my_strtok(input, delim);
    while (token != NULL) {
        printf("%s\n", token);
        fflush(stdout);
        token = my_strtok(NULL, delim);
    }
     printf("------------------------------------\n");
     char *token1 = strtok(input1, delim1);
    while (token1 != NULL) {
        printf("%s\n", token1);
 
        token1 = strtok(NULL, delim1);
    }

    return 0;
}




/*// ----------------------main test-------------
int main() {
    char *input = NULL;
    size_t input_size = 0;
    ssize_t nchars_read;
    char *input1 = NULL;
    size_t input_size1 = 0;
    ssize_t nchars_read1;
    
        
  //  char input[100];
    char *tokens[MAX_TOKENS];

    
    


    while(1)
    {
        printf("   $ ");
        fflush(stdout);
        nchars_read = _getline(&input, &input_size, stdin);
        
       if (nchars_read == -1) {
             return 1;
        } else if (nchars_read == 1 && input[nchars_read-1]=='\n') {
            // End of file reached
            printf("end of file");
            break;
        }
        
        
        
        
        
        
        if (nchars_read != -1) {
        printf("   Read %zd characters: %s", nchars_read, input);
    } else {
        printf("Error reading input.\n");
    }
    printf("1  $ ");
    nchars_read1 = getline(&input1, &input_size1, stdin);

        if (nchars_read1 != -1) {
        printf("1  Read %zd characters: %s", nchars_read1, input1);
    } else {
        printf("1  Error reading input.\n");
    }
    
    
    
    
   
    int tokenCount = tokenizeInput(input, tokens);

    printf("Tokens:\n");
    for (int i = 0; i < tokenCount; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]);  // Free allocated memory for tokens
    }
    }
    
    free(input);

    return 0;
}

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
    }

    (*lineptr)[nbrCharsRead] = '\0'; // Null-terminate the string

    return nbrCharsRead;
}


*/
