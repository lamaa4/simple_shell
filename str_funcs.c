#include "main.h"

int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);

/**
 * _strlen - Computes the length of a string
 * @str: A pointer to the characters string.
 * Return: the length of str
 */
 
int _strlen(const char *str)
{
  
	int l=0;

	while (str[l] != '\0')
	{
		l++;
	}

	return (l);
}

/**
 * _strcat - Concatenate the contents of one string to the end of another string.
 * @dest: string to append to
 * @src: string to add
 * Return: Pointer to dest
 */

char *_strcat(char *dest, const char *src)
{  
	int i=0,j=0;
  const char* dest_copy=dest;


	if (dest_copy==NULL)
	{
		return(NULL);
	}
  
	while (dest_copy[i] != '\0')
	{
    dest[i]=dest_copy[i];
	  i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
    
  dest[i] = '\0';

  return (dest);
}

/**
 * _strcmp - Compare two strings
 * @s1: A pointer to the first string to be compared
 * @s2: A pointer to the second string to be compared
 * Return: 0 if s1 is equal to s2,
 *         a negative value if s1 is less than s2,
 *         a positive value if s1 is greater than s2
 */

int _strcmp(const char *s1, char *s2)
{
    int i=0;
    
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - Duplicates a string
 * @str: A string that you want to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
  char *dup;
  int i=0, l;
  
  if (str == NULL)
    return (NULL);
  
  l = _strlen(str);
  
  dup = malloc(sizeof(char) * (l + 1));
  
  if (dup == NULL) 
	  return (NULL);
  
  while (str[i] != '\0')
  {
    dup[i] = str[i];
    i++;
  }
  dup[l] = '\0';
  
  return (dup);
}

/**
 * _strcpy- Copies a string from the source to the destination
 * @src: Pointer to the source string
 * @dest: Pointer to the destination string
 *
 * Return: Pointer to the duplicated string
 */

char *_strcpy(char *dest, const char *src)
{
    char *ptr = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return (ptr);
}
