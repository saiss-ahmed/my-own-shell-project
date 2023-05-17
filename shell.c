#include "shell.h"

#define MAX_WORDS 1024
#define BUFFER_SIZE 1024

/**
* main - entry point
* Return: 0 on success
*/

int main(int ac, char **args, char **env)
{
	char input[BUFFER_SIZE];

	(void)ac;
	while (true)
	{
		print_string("$ ");
		if ((read(STDIN_FILENO, &input, BUFFER_SIZE)) == '\0')
		{
			exit(EXIT_FAILURE);
		}
		input[_strcspn(input, "\n")] = '\0';
		args = parse_input(input);
		run_command(args, env);
		if (args[0] != NULL && args[0] != input)
		free(args[0]);
		free(args);
	}

	return (0);
}



