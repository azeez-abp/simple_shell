#include "header.h"
/**
* _getline - read line of input
* @lineptr: pointer to the string
* @n: size  of char read
* Return: size of character;
*/
ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int bytes_read;
	char *line;

	buffer_pos = 0;
	bytes_read = 0;

	if (buffer_pos >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return (-1);
		}
		buffer_pos = 0;
	}

	line = &buffer[buffer_pos];
	while (buffer_pos < bytes_read && buffer[buffer_pos] != '\n')
	{
		buffer_pos++;
	}
	buffer[buffer_pos++] = '\0'; /* Replace '\n' with '\0'*/

	*lineptr = line;
	*n = buffer_pos;

	return (*n);
}
