#include "shell.h"

/**
 * printEnvironmentVariables - Prints all the environment variables.
 *
 * Return: void.
 */
int printEnvironmentVariables(void)
{
	int index;

	for (index = 0; environ[index]; index++)
	{
		printString(environ[index]);
		custom_putchar('\n');
	}

	return (0);
}

