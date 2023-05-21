#include "shell.h"

#define MAX_WORDS 1024
#define BUFFER_SIZE 1024

/**
* main - entry point
* @ac: args count
* @args: args vector
* @env: environment
* Return: 0 on success
*/

int main(int ac, char **args, char **env)
{
	char input[BUFFER_SIZE];
	int i = 0;

	while (true)
	{
		print_string("$ ");
		if ((read(STDIN_FILENO, &input, BUFFER_SIZE)) == '\0')
		{
				if (env != environ)
				{
				for (ac = 0; env[ac] != NULL; ac++)
				{
					environ[ac] = env[ac];
					if (env[ac + 1] == NULL)
					{
						for (i = ac + 1; environ[i] != NULL; i++)
						{
							free(environ[i]);
						}
					}
				}
				free(environ);
			
            }
			exit(EXIT_FAILURE);
		}
		if (!_isspace(*input))
		{
		input[_strcspn(input, "\n")] = '\0';
		args = parse_input(input);
		}
		if (args != 0)
		{
			run_command(args, environ);
			if (args[0] != NULL && args[0] != input)
			{
			free(args[0]);
			free(args);
			}
		}
		else
		{
			ac++;
		}
	}
	return (0);
}
