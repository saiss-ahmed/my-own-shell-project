#include "shell.h"
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

    for (; i < n; i++) {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}
/**
 *_getenv - a funciton that gives the name of teh env
 *@name: the name of the env
 *Return: a string
 */
 char *_getenv(char *name) 
 { 
         extern char **environ; 
         int i = 0, len = 0; 
         char *variable = NULL; 
  
         if (name == NULL || _strlen(name) == 0) 
                 return (NULL); 
  
         for (; environ[i] != NULL; ++i) 
         { 
                 variable = environ[i]; 
                 len = _strlen(name); 
                 if (_strncmp(name, variable, len) == 0 && variable[len] == '=') 
                 { 
                         return (variable + len + 1); 
                 } 
         } 
         return (NULL); 
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
