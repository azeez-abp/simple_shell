#include "header.h"
#define MAX_INPUT_SIZE 1024
/**
 * get_input - Get the input from keyboard
 *
 * Return: The read input
 */
char *get_input(void)
{
	char *input;
	size_t input_size;
	ssize_t input_size_read;

	input = NULL;
	input_size = 0;
	input_size_read = _getline(&input, &input_size);

	input[input_size_read - 1] = '\0';
	return (input);
}

/**
 * input_to_array - Convert string to array of tokens
 * @inputs: Input string
 *
 * Return: Array of tokens
 */
char **input_to_array(char *inputs)
{
	char **tokens;
	unsigned int token_count;
	char *token;

	token_count = 0;
	tokens  = (char **) malloc(sizeof(char *) * MAX_INPUT_SIZE);
	if (tokens == NULL)
	{
		printf("Error in input_to_array\n");
		exit(-1);
	}
	token = _strtok(inputs, " ");
	while (token != NULL)
	{
		tokens[token_count] = malloc(_strlen(token) + 1);
		_strncpy(tokens[token_count++], token, _strlen(token) + 1);
		token = _strtok(NULL, " ");
	}

	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * execution - run the code
 * @token: array string
 * @c: arg count
 * @v: args value 
 * @input: string read from stdinp and converted tokens
 */
void execution(int c, char **v, char **token)
{
	if (tokens)
	{
		check_env(tokens[0]);

		if (streql("setenv", tokens[0]) == 1)
		{
			if (!tokens[1] || !tokens[2])
				continue;
			setenvfunc(tokens[1], tokens[2]);
			free(tokens);
			continue;
		}
		else if (streql("unsetenv", tokens[0]) == 1)
		{
			unsetenvfunc(tokens[1]);
			continue;
		}
		else if (streql("cd", tokens[0]) == 1)
		{

			_cd(tokens);
		}
		else
		{
			if (streql(tokens[0], "exit") == 1)
			{
				if (tokens[1])
				{
					exit((int)(*tokens[1]));
				}
				else
					exit(0);
			}
			if (str_search("/bin/", tokens[0]) == 0)
				tokens[0] = concat("/bin/", tokens[0]);
			pid = fork();
			run_command(c, v, pid, tokens);
			if (!isatty(STDIN_FILENO))
				break;
		}
		free(tokens);
	}
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

		if (_strlen(input) == 0 || _strlen(input) == 1)
			continue;

		tokens  = input_to_array(input);

		execution(c, v, tokens);

	}
	
	return (0);
}
