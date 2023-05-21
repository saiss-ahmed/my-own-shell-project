#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>
#include <limits.h>

#define MAX_WORDS 1024
#define BUFFER_SIZE 1024
#define MAX_WORD 100


/*the main functions*/
int run_command(char **ls, char **env);
char **parse_input(char *input);
char **process_input_words(char *input, char **ls, int word_count);
void check_and_execute_exit(char **ls);
void execute_echo_command(char **ls);
void execute_cd_command(char **ls);
void execute_external_command(char **ls, char **env);
/*the main fucnions*/

extern char **environ;


int put_char(char c);
void print_string(char *str);
int _strlen(const char *str);
size_t _strcspn(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
int _isspace(int c);
int _atoi(char *s);
char *_getenv(const char *name);
int _strcmp(char* str1, char* str2);
void cut_string(char *str, char ch, char *result);
void cut_string_two(char *str, char ch, char *result);
int _setenv(char *name, char *value, int overwrite);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif
