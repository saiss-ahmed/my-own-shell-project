#include "shell.h"
/**
 * run_command - executes the command based on the given array
 * @ls: the given array
 * @env: the environment variables array
 * Return: 0 on success
 */
int run_command(char **ls, char **env)
{
	if (ls[0] == NULL)
		return (0);

	if (_strcmp(ls[0], "/bin/echo") == 0)
	{
		execute_echo_command(ls);
		return (0);
	}

	if (strcmp(ls[0], "cd") == 0)
	{
		execute_cd_command(ls);
		return (0);
	}

	execute_external_command(ls, env);
	return (0);
}
/**
 * execute_echo_command - executes the echo command with environment variables
 * @ls: the command arguments array
 */
void execute_echo_command(char **ls)
{
	int i;
	char *env_var_name;
	char *env_var_value;

	for (i = 1; ls[i] != NULL; i++)
	{
		char *arg = ls[i];

		if (arg[0] == '$' && strcmp(arg, "$PWD") == 0)
		{
			char cwd[PATH_MAX];

			if (getcwd(cwd, sizeof(cwd)) != NULL)
				print_string(cwd);
		}
		else if (arg[0] == '$')
		{
			env_var_name = arg + 1;
			env_var_value = _getenv(env_var_name);
			if (env_var_value != NULL)
				print_string(env_var_value);
		}
		else if (arg[0] == '~')
		{
			env_var_name = arg;
			env_var_value = _getenv("HOME");
			print_string(env_var_value);
		}
		else
		{
			cut_string_two(arg, '"', arg);
			cut_string_two(arg, '\'', arg);
			print_string(arg);
		}

		print_string("\n");
	}
}

/**
 * execute_cd_command - executes the cd command with directory change
 * @ls: the command arguments array
 */
void execute_cd_command(char **ls)
{
	static char previous_directory[PATH_MAX];
    char *arg = ls[1];
    char *env_var_name;
    char *env_var_value;

    if (arg == NULL)
    {
        chdir(getenv("HOME"));
    }
    else if (strcmp(arg, "-") == 0)
    {
          if (previous_directory[0] != '\0')
        {
            chdir(previous_directory);
            printf("%s\n", previous_directory);
        }
    }
    else
    {
        if (getcwd(previous_directory, sizeof(previous_directory)) == NULL)
        {
            perror("getcwd");
            return;
        }

        if (chdir(arg) != 0)
        {
            if (arg[0] == '$')
            {
                env_var_name = arg + 1;
                env_var_value = getenv(env_var_name);

                if (env_var_value != NULL)
                    chdir(env_var_value);
            }
            else if (arg[0] == '~')
            {
                env_var_value = getenv("HOME");
                chdir(env_var_value);
            }
            if (access(arg, F_OK) != -1)
            {
                perror(arg);
            }
        }
    }
}


/**
 * execute_external_command - executes a command using fork and execve
 * @ls: the command arguments array
 * @env: the environment variables array
 */
void execute_external_command(char **ls, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(ls[0], ls, env);
		perror(ls[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

