#include "header.h"
#define MAX_INPUT_SIZE 1024
/**
 * get_input - Get the input from keyboard
 *
 * Return: The read input
 */
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_size_read;

	input_size_read = getline(&input, &input_size, stdin);

	input[input_size_read - 1] = '\0';
	return (input);
}

/**
 * _strlen - return the lenth of the string
 * @s: the string to measure.
 *
 * Return: Int value of the length.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strncpy - copies a string
 * @dest: destination.
 * @src: source.
 * @n: amount of bytes from src.
 * Return: the pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * input_to_array - Convert string to array of tokens
 * @inputs: Input string
 *
 * Return: Array of tokens
 */
char **input_to_array(char *inputs)
{
	char **tokens = malloc(sizeof(char *) * MAX_INPUT_SIZE);
	unsigned int token_count = 0;

	char *token = strtok(inputs, " ")
		;
	while (token != NULL)
	{
		tokens[token_count] = malloc(_strlen(token) + 1);
		_strncpy(tokens[token_count++], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
	}

	tokens[token_count] = NULL;
	return (tokens);
}
/**
 * shell2 - print prompt and take user input
 * @c: arg count
 * @v: arg va;
 * Return: Always 0
 */
int shell2(int c, char **v)
{
	char *input;
	char **tokens;
	pid_t pid;

	while (1)
	{
		write(1, PROMPT, 2);
		input  = get_input();
		tokens  = input_to_array(input);

		if (_strlen(input) == 0 || _strlen(input)  == 1)
			continue;

		check_env(tokens[0]);
		if (streql(tokens[0], "exit") == 1)
			break;

		if (str_search("/bin/", tokens[0]) == 0)
			tokens[0] = concat("/bin/", tokens[0]);
		pid = fork();
		run_command(c, v, pid, tokens);
		
		if(!isatty(STDIN_FILENO))
			break;
	}
	free(tokens);
	free(input);
	return (0);
}
