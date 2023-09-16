#include "header.h"
/**
 * get_env - output env
 */

void get_env()
{
	char **env;
	int index;
	index = 0;
	env = environ;

	while (env[index] != NULL)
	{
		char *current = env[index];
		int i = 0;
		while (current[i] != '\0')
		{
			write(1, &current[i], 1);
			i++;
		}
		write(1, "\n", 1);
		index++;
	}
}
