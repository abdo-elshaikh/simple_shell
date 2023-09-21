#include "hsh.h"
/**
 * print_environment - Print environment variables
 * @arguments: array of command arguments (not used)
 * Description: function prints value of PATH environment variable
 * Return: always returns -1
 */
int print_environment(char **arguments)
{
	int i = 0;
	char **env = NULL;
	(void)arguments;

	env = environ;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (-1);
}

/**
 * set_default_path - Set default PATH environment variable
 * Description: function sets PATH environment variable to default value
 */
void set_default_path(void)
{
	set_environment("PATH", "/home/abdo/bin");
}

/**
 * set_environment - Set an environment variable
 * @var: Name of variable
 * @value: Value of variable
 * Description: function sets value of specified environment variable
 */
void set_environment(char *var, char *value)
{
	char *env_var = malloc(strlen(var) + strlen(value) + 2);

	sprintf(env_var, "%s=%s", var, value);
	putenv(env_var);
}

/**
 * unset_environment - Unset  environment variable
 * @var: name of variable
 * Description: function unsets specified environment variable
 * Return: Nothing
 */
void unset_environment(char *var)
{
	unsetenv(var);
}

/**
 * get_environment - Get value of an environment variable
 * @var: name of environment variable
 * Description: function retrieves value of specified environment variable
 * Return: value of environment variable, or NULL if not found
 */
char *get_environment(char *var)
{
	char *value = getenv(var);

	if (value == NULL)
	{
		fprintf(stderr, "environment variable %s not found\n", var);
		return (NULL);
	}
	return (strdup(value));
}

