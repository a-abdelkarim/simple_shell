#include "shell.h"

/**
 * getEnvVariable - Get the value of an environment variable
 * @varName: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *getEnvVariable(const char *varName)
{
	char **env;
	size_t nameLen = custom_strlen(varName);

	for (env = environ; *env != NULL; env++)
	{
		if (custom_strncmp(*env, varName, nameLen) == 0 && (*env)[nameLen] == '=')
		{
			return (&(*env)[nameLen + 1]);
		}
	}

	return (NULL);
}

