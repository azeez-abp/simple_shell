#include "header.h"
/**
 * concat - methode use to join two strings
 * @str1: first string
 * @str2: second string
 * Return: combined string1 and string2
 */

char *concat(char *str1, char *str2)
{

	char *path;
	int str1_len;
	int str2_len;

	str1_len = 0;
	str2_len = 0;

	path = (char *)malloc(sizeof(*path) + 1);
	while (str1[str1_len] != '\0')
	{
		path[str1_len] = str1[str1_len];
		str1_len++;
	}

	while (str2[str2_len] != '\0')
	{
		path[str1_len] = str2[str2_len];
		str2_len++;
		str1_len++;
	}

	return (path);
}
