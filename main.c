#include "header.h"
/**
 * main - Entry point
 * @c: arg count
 * @v: arg value
 * Return: 0 to stop execution
 */

int main(int c, char **v)
{	
	if (c == 2)
		readfile(v[1]);
	else
	shell2(c, v);
	return (0);
}
