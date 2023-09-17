#include "header.h"
/**
 *_strtok - identify the point where char should be group as a string
 * @str: string to split
 * @delim: delimiter
 * Return: string when the delimiter is encounter
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *start;

	start = NULL;

	if (str != NULL)
		token = str;

	while (*token && strchr(delim, *token))
		token++;

	start = token;

	while (*token && !strchr(delim, *token))
		token++;

	if (*token)
	{
		*token = '\0';
		token++;
	}

	return (*start ? start : NULL);
}
