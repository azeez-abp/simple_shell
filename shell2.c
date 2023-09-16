#include "header.h"
#define MAX_INPUT_SIZE 1024

/**
 * prompt_shell - print prompt and take user input
 * @c: arg count
 * @v: arg va;
 * Return: Always 0
 */
int shell2(int c, char **v)
{
	char *input;
	size_t input_size;
	ssize_t input_size_read;
	char *tokens[MAX_INPUT_SIZE];
	int token_count;
	char *token;
	pid_t pid;
	

	while (1)
	{
		write(1, PROMPT, 2);
		input_size_read = getline(&input, &input_size, stdin);

		if (input_size_read < 0)
		{
			perror("Input is empty");
			exit(1);
		}
		
		input[input_size_read - 1] = '\0';
		token_count = 0;
		token = strtok(input, " ");
		

		while (token != NULL)
		{
			tokens[token_count++] = token;
			token = strtok(NULL, " ");
		}
		
		tokens[token_count] = NULL;
		check_env(tokens[0]);
		if (streql(tokens[0], "exit") == 1)
		{
			break;
		}

		if(str_search("/bin/", tokens[0]) == 0)
		{
			tokens[0] = concat("/bin/", tokens[0]);
		}
		pid = fork();
		run_command(c, v, pid, tokens);
	}
	return (0);
}
