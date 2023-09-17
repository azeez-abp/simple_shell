#include "header.h"
/**
 * *_strchr - search character in string
 * @str: haystack
 * @ch: needle
 * Return: string found at ch encounyter
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
