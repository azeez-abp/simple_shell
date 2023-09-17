#include "header.h"
/**
 * run_command - run the command
 * @c: arg count
 * @v: array of string of agument value
 * @pid: Process ID
 * @tokens: Array of command and arguments
 *
 * This function runs commad
 */
void run_command(int c, char **v, pid_t pid, char **tokens)
{
	if (c == 0)
		c = 0;	

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror(v[0]);
		};

	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork failed");
		exit(1);
	}

}
