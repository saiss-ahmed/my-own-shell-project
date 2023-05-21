#include "shell.h"
int _setenv(char *name, char *value, int overwrite)
{
    int name_len = _strlen(name);
    int value_len = _strlen(value);
    int var_len = name_len + value_len + 2;
    char *new_var;
    char **new_environ;
    int i;
    int env_count = 0;
    char **env = environ;

    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
    {
        perror("Invalid environment variable name");
        return -1;
    }
    if (value == NULL || strchr(value, '=') != NULL)
    {
        perror("Invalid environment variable value");
        return -1;
    }
    new_var = malloc(var_len);
    if (new_var == NULL)
    {
        perror("Failed to allocate memory");
        return -1;
    }
    _strcpy(new_var, name);
    _strcat(new_var, "=");
    _strcat(new_var, value);
    for (; *env != NULL; env++)
    {
        if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
        {
            if (!overwrite) {
                free(new_var);
                return 0;
            }
            free(*env);
            *env = new_var;
            return 0;
        }
    }
    while (environ[env_count] != NULL)
        env_count++;
    new_environ = malloc((env_count + 2) * sizeof(char *));
    if (new_environ == NULL)
    {
        perror("Failed to allocate memory");
        return -1;
    }
    for (i = 0; i < env_count; i++)
        new_environ[i] = environ[i];
    new_environ[i++] = new_var;
    new_environ[i++] = NULL;
    environ = new_environ;
    return 0;
}