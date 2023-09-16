#include "header.h"
/**
 * main - Entry point
 * @c: arg count
 * @v: arg value
 * Return: 0 to stop execution
 */

int main(int c, char **v)
{
	char *prompt;
	char *file_name;
	file_name = v[0];
        prompt	= "$ ";

	if (v[1] == "exit")
		exit(0);
	if (v[1] == "env")
		get_env();

	if (c != 1)
	{ /*Handle PATH*/
		return (0);
	}
	
	if (!isatty(STDIN_FILENO))
	{
		/*None interactive; input not from shell*/
		printf("HANDL PATH,%s %s",v[1],v[2]);
		run_command(c, v, 0, v);
		
	}
	
	shell2(c, v);
	return (0);
}
