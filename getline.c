#include "header.h"
/**
 * _getline - read line of input
 * @lineptr: 
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[MAX_BUFFER_SIZE];
	static int buffer_pos = 0;
	static int bytes_read = 0;

	if (buffer_pos >= bytes_read)
	{
		bytes_read = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			return -1; // End of input or error
		}
		buffer_pos = 0;
	}

	char *line = &buffer[buffer_pos];
	while (buffer_pos < bytes_read && buffer[buffer_pos] != '\n')
	{
		buffer_pos++;
	}
	buffer[buffer_pos++] = '\0'; /* Replace '\n' with '\0'*/

	*lineptr = line;
	*n = buffer_pos;

	return *n;
}
