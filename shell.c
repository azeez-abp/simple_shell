#include "header.h"


/**
 * shell - function for shell
 * @c: number of arg
 * @v: arr of string
 * Return: 0 success
 */
int  shell(int c, char **v)
{
	char buffer[BUFFER_SIZE];
	pid_t pid;
	int status;
	ssize_t input_size;
	char *path_arr[2];

	while (1)
	{
		write(1, PROMPT, 2);
		input_size = read(0, buffer, sizeof(buffer));
		if (input_size > 0)
		{
			buffer[input_size - 1] = '\0';
			if (streql(buffer, "exit") == 1)
			{
				break;
			}
			check_env(buffer);
			pid = fork();
			path_arr[0] = buffer;
			path_arr[1] = NULL;
			run_command(c, v, pid, path_arr);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
