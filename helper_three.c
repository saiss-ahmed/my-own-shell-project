#include "shell.h"
/**
 *_strncmp - a funciton that compares two str
 *@s1: string 1
 *@s2: string 2
 *@n: buffer size
 *Return: 0 (success)
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
    while (*str1 && *str2 && n)
	{
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
        n--;
    }
    if (n == 0)
        return 0;
    return (*str1 - *str2);
}
/**
 *_getenv - a funciton that gives the name of teh env
 *@name: the name of the env
 *Return: a string
 */
char *_getenv(const char *name)
{
    size_t name_length = strlen(name);
	int i = 0;

    if (name == NULL || strlen(name) == 0)
        return NULL;
    for (; environ[i] != NULL; i++)
    {
        const char *variable = environ[i];
        size_t variable_length = strcspn(variable, "=");

        if (name_length == variable_length && strncmp(name, variable, variable_length) == 0)
        {
            return strdup(variable + variable_length + 1);
        }
    }

    return NULL;
}

/**
 *_strcmp - a function that copare two strings
 *@str1: first string
 *@str2: second string
 *Return: 0 for success
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
/**
 *cut_string - a function that cuts a string
 *@str: the string we are cutting
 *@ch: the unwanted char
 *@result: the string that will paste the result in
 */
void cut_string(char *str, char ch, char *result)
{
	int dst = 0;
	int src = 0;
	int len = strlen(str);

	for (; src < len; src++)
	{
		if (str[src] != ch || (src > 0 && str[src - 1] != ch))
		{
			result[dst] = str[src];
			dst++;
		}
	}

	result[dst] = '\0';
}
/**
 *cut_string_two - a function that cuts a string
 *@str: the string we are cutting
 *@ch: the unwanted char
 *@result: the string that will paste the result in
 */
void cut_string_two(char *str, char ch, char *result)
{
	int dst = 0;
	int src = 0;
	int len = strlen(str);

	for (; src < len; src++)
	{
		if (str[src] != ch)
		{
			result[dst] = str[src];
			dst++;
		}
	}

	result[dst] = '\0';
}
