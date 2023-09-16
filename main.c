#include "header.h"
/**
 * main - Entry point
 * @c: arg count
 * @v: arg value
 * Return: 0 to stop execution
 */

int main(int c, char **v)
{

	if (!isatty(STDIN_FILENO))
	{
		/*None interactive; input not from shell*/
		printf("HANDL PATH, %s %s", v[1],  v[2]);
		run_command(c, v, 0, v);
	}

	shell2(c, v);

	return (0);
}
