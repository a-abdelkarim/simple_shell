#include "shell.h"

/**
 * setEnvironmentVariable - Set the value of an environment variable
 * @arguments: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */
int setEnvironmentVariable(char **arguments)
{
	char *variableName, *variableValue;

	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		printError("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	variableName = arguments[1];
	variableValue = arguments[2];

	if (setenv(variableName, variableValue, 1) != 0)
	{
		printError("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unsetEnvironmentVariable - Unset an environment variable
 * @arguments: Arguments (name of the environment variable)
 *
 * Return: Nothing
 */
int unsetEnvironmentVariable(char **arguments)
{
	char *variableName;

	if (arguments[1] == NULL)
	{
		printError("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	variableName = arguments[1];

	if (unsetenv(variableName) != 0)
	{
		printError("unsetenv");
	}

	return (0);
}

