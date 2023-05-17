#include "shell.h"
/**
 * parse_input - a fucntion that cuts a string and put it as an array
 * @input: the string
 * Return: a double demintional pointer
 */
char **parse_input(char *input)
{
	char **ls;
	int word_count = 0;

	cut_string(input, ' ', input);
	ls = malloc(sizeof(char *) * (MAX_WORDS + 1));
	ls = process_input_words(input, ls, word_count);
	check_and_execute_exit(ls);
	return (ls);
}
/**
 * process_input_words - a function that turn turn input into a double pointer
 * @input: the string
 * @ls: the double pointer
 * @word_count: an int
 * Return: word_count or NULL
 */
char **process_input_words(char *input, char **ls, int word_count)
{
	char bin[] = "/bin/";
	char *word, *command = NULL;

	word = _strtok(input, " ");
	while (word != NULL && word_count < MAX_WORDS)
	{
		if (word_count == 0 && _strcmp(word, "cd") == 0)
		{
			ls[word_count++] = word;
		}
		else if (word_count > 0 && _strcmp(ls[0], "cd") == 0)
		{
			ls[word_count++] = word;
			break;
		}
		else if (word_count == 0 && word[0] >= 'a' && word[0] <= 'z')
		{
			command = malloc(_strlen(bin) + _strlen(word) + 1);
			if (command == NULL)
			{
				free(ls);
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			_strcpy(command, bin);
			_strcat(command, word);
			ls[word_count++] = command;
		}
		else
			ls[word_count++] = word;
		word = _strtok(NULL, " ");
	}
	ls[word_count] = NULL;
	return (ls);
}
/**
 * check_and_execute_exit - a fucntion checks if the first argument is exit
 * @ls: the list argument
 */
void check_and_execute_exit(char **ls)
{
	int status;

	if (_strcmp(ls[0], "/bin/exit") == 0)
	{
		if (ls[1] == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			status = _atoi(ls[1]);
			exit(status);
		}
		free(ls);
	}
}
