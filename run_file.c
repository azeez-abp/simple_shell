#include "shell.h"
/**
 * run_ funcion that execute command
 * @line: array of characrter read from each line of fiel
 */

void run_(char *line)
{
	char *args[4];
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = line;
		args[3] = NULL;

		execve("/bin/sh", args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * readfile - A function that read content of a fiel and exec command
 * @path: file rectory
 * Return: 0 successfule
 */
int readfile(char *path)
{

	char line[1024];
	ssize_t bytes_read;
	int file_descriptor;

	file_descriptor = open(path, O_RDONLY);

	if (file_descriptor == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	do
	{
		bytes_read = read(file_descriptor, line, sizeof(line));

		if (bytes_read > 0)
		{
			line[bytes_read - 1] = '\0';

			run_(line);
		}

	} while (bytes_read > 0);

	close(file_descriptor);
	return (0);
}
