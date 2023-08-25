#include "main.h"

ssize_t _getline (char **lineptr, size_t * len, int fd);


/**
 * _getline - Read characters from the stream.
 * @lineptr: A buffer to store the characters.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */

ssize_t
_getline (char **lineptr, size_t * len, int fd)
{

  static size_t nbrCharsRead = 0;
  char c;
  ssize_t r;
  size_t ret;

  if (nbrCharsRead != 0)

    return (-1);

  nbrCharsRead = 0;

  if (*len == 0)
    {
      *len = 1024;
    }

  if (*lineptr == NULL)
    {
      *lineptr = (char *) malloc (sizeof (char) * *len);

      if (*lineptr == NULL)
	{
	  return (-1);
	}
    }



  c = 'a';
  while (c != '\n')
    {
      r = read (fd, &c, 1);

      if (r == -1)
	{
	  return (-1);

	}
      else if (r == 0 && nbrCharsRead == 0)
	{
	        return (-1);

	}
      else if (r == 0 && nbrCharsRead != 0)
	{
	  nbrCharsRead++;
	  break;
	}

      if (nbrCharsRead >= ((size_t) (*len - 1)))
	{
	  char *new_ptr = (char *) realloc (*lineptr, *len * 3);

	  if (new_ptr == NULL)
	    {
	      return (-1);
	    }

	  *lineptr = new_ptr;
	}

      (*lineptr)[nbrCharsRead++] = c;

    }

  (*lineptr)[nbrCharsRead] = '\0';

  ret = nbrCharsRead;

  if (r != 0)
  {nbrCharsRead = 0;}
  return (ret);
}
