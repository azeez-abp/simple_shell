#include "header.h"
/**
 * check_env - check env
 * @input: input value
 */
void check_env(char *input)
{
	if (streql(input, "env") == 1)
	{
		get_env();
	}
}
